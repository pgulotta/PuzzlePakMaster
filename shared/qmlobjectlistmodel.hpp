#pragma once

#include <QAbstractListModel>
#include <QByteArray>
#include <QChar>
#include <QDebug>
#include <QHash>
#include <QList>
#include <QMetaMethod>
#include <QMetaObject>
#include <QMetaProperty>
#include <QObject>
#include <QString>
#include <QStringBuilder>
#include <QVariant>
#include <QVector>

template<typename T> QList<T> fromVariantList ( const QVariantList& variantList )
{
  QList<T> list;
  list.reserve ( variantList.size () );

  for ( QVariantList::const_iterator cit = variantList.constBegin (); cit != variantList.constEnd (); ++cit ) {
    const QVariant& variant = static_cast<QVariant>( *cit );
    list.append ( variant.value<T> () );
  }

  return list;
}

template<typename T> QVariantList toVariantList ( const QList<T>& list )
{
  QVariantList variantList;
  variantList.reserve ( list.size () );

  for ( typename QList<T>::const_iterator cit = list.constBegin (); cit != list.constEnd (); ++cit ) {
    const T& val = static_cast<T>( *cit );
    variantList.append ( QVariant::fromValue ( val ) );
  }

  return variantList;
}

class QmlObjectListModelBase  : public QAbstractListModel
{
  Q_OBJECT
  Q_PROPERTY ( int count READ count NOTIFY countChanged )

public:
  explicit QmlObjectListModelBase ( QObject* parent = nullptr ) : QAbstractListModel ( parent )
  {
  }
  virtual ~QmlObjectListModelBase() {}

  Q_INVOKABLE virtual int size (  ) const = 0;
  Q_INVOKABLE virtual int count (  ) const = 0;
  Q_INVOKABLE virtual bool isEmpty (  ) const = 0;
  Q_INVOKABLE virtual bool contains ( QObject* item ) const = 0;
  Q_INVOKABLE virtual int indexOf ( QObject* item ) const = 0;
  Q_INVOKABLE virtual int roleForName ( const QByteArray& name ) const = 0;
  Q_INVOKABLE virtual void clear (  ) = 0;
  Q_INVOKABLE virtual void append ( QObject* item ) = 0;
  Q_INVOKABLE virtual void prepend ( QObject* item ) = 0;
  Q_INVOKABLE virtual void insert ( int index, QObject* item ) = 0;
  Q_INVOKABLE virtual void move ( int index, int pos ) = 0;
  Q_INVOKABLE virtual void remove ( QObject* item ) = 0;
  Q_INVOKABLE virtual void remove ( int index ) = 0;
  Q_INVOKABLE virtual QObject* get ( int index ) const = 0;
  Q_INVOKABLE virtual QObject* get ( const QString& uid ) const = 0;
  Q_INVOKABLE virtual QObject* getFirst (  ) const = 0;
  Q_INVOKABLE virtual QObject* getLast (  ) const = 0;
  Q_INVOKABLE virtual QVariantList toVarArray (  ) const = 0;

protected slots:
  virtual void onItemPropertyChanged ( void ) = 0;

signals:
  void countChanged ( void );
};

template<class ItemType> class QmlObjectListModel final : public QmlObjectListModelBase
{
public:
  explicit QmlObjectListModel ( QObject*           parent      = nullptr,
                                const QByteArray& displayRole = QByteArray (),
                                const QByteArray& uidRole     = QByteArray () )
    : QmlObjectListModelBase ( parent )
    , m_count ( 0 )
    , mUidRoleName ( uidRole )
    , mDispRoleName ( displayRole )
    , mMetaObject ( ItemType::staticMetaObject )
  {
    static QSet<QByteArray> roleNamesBlacklist;

    if ( roleNamesBlacklist.isEmpty () ) {
      roleNamesBlacklist << QByteArrayLiteral ( "id" )
                         << QByteArrayLiteral ( "index" )
                         << QByteArrayLiteral ( "class" )
                         << QByteArrayLiteral ( "model" )
                         << QByteArrayLiteral ( "modelData" );
    }

    static const char* handler = "onItemPropertyChanged()";
    mPropertyChangedHandler = metaObject ()->method ( metaObject ()->indexOfMethod ( handler ) );

    if ( !displayRole.isEmpty () ) {
      mRoles.insert ( Qt::DisplayRole, QByteArrayLiteral ( "display" ) );
    }

    mRoles.insert ( baseRole (), QByteArrayLiteral ( "qtObject" ) );
    const int propertyCount = mMetaObject.propertyCount ();

    for ( int propertyIndex = 0, role = ( baseRole () + 1 ); propertyIndex < propertyCount; propertyIndex++, role++ ) {
      QMetaProperty metaProperty = mMetaObject.property ( propertyIndex );
      const QByteArray propertyName = QByteArray ( metaProperty.name () );

      if ( !roleNamesBlacklist.contains ( propertyName ) ) {
        mRoles.insert ( role, propertyName );

        if ( metaProperty.hasNotifySignal () ) {
          mRoleSignals.insert ( metaProperty.notifySignalIndex (), role );
        }
      } else {
        static const QByteArray CLASS_NAME = ( QByteArrayLiteral ( "QmlObjectListModel<" ) % mMetaObject.className () % '>' );
        qWarning () << "Can't have" << propertyName << "as a role name in" << qPrintable ( CLASS_NAME );
      }
    }
  }
  bool setData ( const QModelIndex& index, const QVariant& value, int role ) override
  {
    bool isDataSet {false};
    ItemType* item = at ( index.row () );
    const QByteArray rolename = ( role != Qt::DisplayRole ? mRoles.value ( role, emptyBA () ) : mDispRoleName );

    if ( item != nullptr && role != baseRole () && !rolename.isEmpty () ) {
      isDataSet = item->setProperty ( rolename, value );
    }

    return isDataSet;
  }
  QVariant data ( const QModelIndex& index, int role ) const override
  {
    QVariant dataVariant;
    ItemType* item = at ( index.row () );
    const QByteArray rolename = ( role != Qt::DisplayRole ? mRoles.value ( role, emptyBA () ) : mDispRoleName );

    if ( item != nullptr && !rolename.isEmpty () ) {
      dataVariant.setValue ( role != baseRole () ? item->property ( rolename ) : QVariant::fromValue ( static_cast<QObject*>
                             ( item ) ) );
    }

    return dataVariant;
  }
  QHash<int, QByteArray> roleNames (  ) const override
  {
    return mRoles;
  }
  typedef typename QList<ItemType*>::const_iterator const_iterator;
  const_iterator begin (  ) const
  {
    return mItemTypes.begin ();
  }
  const_iterator end (  ) const
  {
    return mItemTypes.end ();
  }
  const_iterator constBegin (  ) const
  {
    return mItemTypes.constBegin ();
  }
  const_iterator constEnd (  ) const
  {
    return mItemTypes.constEnd ();
  }

public:
  ItemType* at ( int index ) const
  {
    ItemType* result = nullptr;

    if ( index >= 0 && index < mItemTypes.size () ) {
      result = mItemTypes.value ( index );
    }

    return result;
  }
  ItemType* getByUid ( const QString& uid ) const
  {
    return ( !mUidIndex.isEmpty () ? mUidIndex.value ( uid, nullptr ) : nullptr );
  }
  int roleForName ( const QByteArray& name ) const
  {
    return mRoles.key ( name, -1 );
  }
  int count (  ) const
  {
    return m_count;
  }
  int size (  ) const
  {
    return m_count;
  }
  bool isEmpty (  ) const
  {
    return mItemTypes.isEmpty ();
  }
  bool contains ( ItemType* itemType ) const
  {
    return mItemTypes.contains ( itemType );
  }
  int indexOf ( ItemType* itemType ) const
  {
    return mItemTypes.indexOf ( itemType );
  }
  void clear ( void )
  {
    if ( !mItemTypes.isEmpty () ) {
      beginRemoveRows ( noParent (), 0, mItemTypes.count () - 1 );

      for ( auto item : mItemTypes ) {
        dereferenceItem ( item );
      }

      mItemTypes.clear ();
      endRemoveRows ();
      updateCounter ();
    }
  }
  void append ( ItemType* itemType )
  {
    if ( itemType != nullptr ) {
      const int position = mItemTypes.count ();
      beginInsertRows ( noParent (), position, position );
      mItemTypes.append ( itemType );
      referenceItem ( itemType );
      endInsertRows ();
      updateCounter ();
    }
  }
  void prepend ( ItemType* itemType )
  {
    if ( itemType != nullptr ) {
      beginInsertRows ( noParent (), 0, 0 );
      mItemTypes.prepend ( itemType );
      referenceItem ( itemType );
      endInsertRows ();
      updateCounter ();
    }
  }
  void insert ( int index, ItemType* itemType )
  {
    if ( itemType != nullptr ) {
      beginInsertRows ( noParent (), index, index );
      mItemTypes.insert ( index, itemType );
      referenceItem ( itemType );
      endInsertRows ();
      updateCounter ();
    }
  }

  void append ( const QList<ItemType*>& itemTypes )
  {
    if ( !itemTypes.isEmpty () ) {
      const int pos = mItemTypes.count ();
      beginInsertRows ( noParent (), pos, pos + itemTypes.count () - 1 );
      mItemTypes.reserve ( mItemTypes.count () + itemTypes.count () );
      mItemTypes.append ( itemTypes );

      for ( auto item : itemTypes ) {
        referenceItem ( item );
      }

      endInsertRows ();
      updateCounter ();
    }
  }
  void prepend ( const QList<ItemType*>& itemTypes )
  {
    if ( !itemTypes.isEmpty () ) {
      beginInsertRows ( noParent (), 0, itemTypes.count () - 1 );
      mItemTypes.reserve ( mItemTypes.count () + itemTypes.count () );
      int offset = 0;

      for ( auto item : itemTypes ) {
        mItemTypes.insert ( offset, item );
        referenceItem ( item );
        offset++;
      }

      endInsertRows ();
      updateCounter ();
    }
  }
  void insert ( int index, const QList<ItemType*>& itemTypes )
  {
    if ( !itemTypes.isEmpty () ) {
      beginInsertRows ( noParent (), index, index + itemTypes.count () - 1 );
      mItemTypes.reserve ( mItemTypes.count () + itemTypes.count () );
      int offset = 0;

      for ( auto item : itemTypes ) {
        mItemTypes.insert ( index + offset, item );
        referenceItem ( item );
        ++offset;
      }

      endInsertRows ();
      updateCounter ();
    }
  }
  void move ( int index, int position )
  {
    if ( index != position ) {
      // TODO : use begin/end MoveRows when supported by Repeater, since then use remove/insert pair
      //beginMoveRows (noParent (), index, index, noParent (), (index < pos ? pos +1 : pos));
      beginRemoveRows ( noParent (), index, index );
      beginInsertRows ( noParent (), position, position );
      mItemTypes.move ( index, position );
      endRemoveRows ();
      endInsertRows ();
      //endMoveRows ();
    }
  }
  void remove ( ItemType* itemType )
  {
    if ( itemType != nullptr ) {
      const int index = mItemTypes.indexOf ( itemType );
      remove ( index );
    }
  }
  void remove ( int index )
  {
    if ( index >= 0 && index < mItemTypes.size () ) {
      beginRemoveRows ( noParent (), index, index );
      ItemType* item = mItemTypes.takeAt ( index );
      dereferenceItem ( item );
      endRemoveRows ();
      updateCounter ();
    }
  }
  ItemType* first (  ) const
  {
    return mItemTypes.first ();
  }
  ItemType* last (  ) const
  {
    return mItemTypes.last ();
  }
  const QList<ItemType*>& toList ( ) const
  {
    return mItemTypes;
  }

public: // QML slots implementation
  void append ( QObject* item )
  {
    append ( qobject_cast<ItemType*> ( item ) );
  }
  void prepend ( QObject* item )
  {
    prepend ( qobject_cast<ItemType*> ( item ) );
  }
  void insert ( int index, QObject* item )
  {
    insert ( index, qobject_cast<ItemType*> ( item ) );
  }
  void remove ( QObject* item )
  {
    remove ( qobject_cast<ItemType*> ( item ) );
  }
  bool contains ( QObject* item ) const
  {
    return contains ( qobject_cast<ItemType*> ( item ) );
  }
  int indexOf ( QObject* item ) const
  {
    return indexOf ( qobject_cast<ItemType*> ( item ) );
  }
  int indexOf ( const QString& uid ) const
  {
    return indexOf ( get ( uid ) );
  }
  QObject* get ( int index ) const
  {
    return static_cast<QObject*> ( at ( index ) );
  }
  QObject* get ( const QString& uid ) const
  {
    return static_cast<QObject*> ( getByUid ( uid ) );
  }
  QObject* getFirst (  ) const
  {
    return static_cast<QObject*> ( first () );
  }
  QObject* getLast (  ) const
  {
    return static_cast<QObject*> ( last () );
  }
  QVariantList toVarArray (  ) const
  {
    return toVariantList<ItemType*> ( mItemTypes );
  }

protected:
  static const QString& emptyStr (  )
  {
    static const auto result = QStringLiteral ( "" );
    return result;
  }
  static const QByteArray& emptyBA ( void )
  {
    static const auto result = QByteArrayLiteral ( "" );
    return result;
  }
  static const QModelIndex& noParent (  )
  {
    static const auto result = QModelIndex{};
    return result;
  }
  static const int& baseRole (  )
  {
    static const int result = Qt::UserRole  ;
    return result;
  }

  int rowCount ( const QModelIndex& parent = QModelIndex () ) const override
  {
    Q_UNUSED ( parent );
    return mItemTypes.count ();
  }
  void referenceItem ( ItemType* itemType )
  {
    if ( itemType != nullptr ) {
      if ( itemType->parent () == nullptr ) {
        itemType->setParent ( this );
      }

      const QList<int> signalsindexList = mRoleSignals.keys ();

      for ( QList<int>::const_iterator it = signalsindexList.constBegin (); it != signalsindexList.constEnd (); ++it ) {
        const int signalindex = static_cast<int> ( *it );
        QMetaMethod notifier = itemType->metaObject ()->method ( signalindex );
        connect ( itemType, notifier, this, mPropertyChangedHandler, Qt::UniqueConnection );
      }

      if ( !mUidRoleName.isEmpty () ) {
        const QString key = mUidIndex.key ( itemType, emptyStr () );

        if ( !key.isEmpty () ) {
          mUidIndex.remove ( key );
        }

        const QString value = itemType->property ( mUidRoleName ).toString ();

        if ( !value.isEmpty () ) {
          mUidIndex.insert ( value, itemType );
        }
      }
    }
  }
  void dereferenceItem ( ItemType* itemType )
  {
    if ( itemType != nullptr ) {
      disconnect ( this, nullptr, itemType, nullptr );
      disconnect ( itemType, nullptr, this, nullptr );

      if ( !mUidRoleName.isEmpty () ) {
        const QString key = mUidIndex.key ( itemType, emptyStr () );

        if ( !key.isEmpty () ) {
          mUidIndex.remove ( key );
        }
      }

      if ( itemType->parent () == this ) {
        itemType->deleteLater ();
      }
    }
  }
  void onItemPropertyChanged (  )
  {
    ItemType* item = qobject_cast<ItemType*> ( sender () );
    const int row = mItemTypes.indexOf ( item );
    const int signalIndex = senderSignalIndex ();
    const int role = mRoleSignals.value ( signalIndex, -1 );

    if ( row >= 0 && role >= 0 ) {
      QModelIndex index = QAbstractListModel::index ( row, 0, noParent () );
      QVector<int> rolesList;
      rolesList.append ( role );

      if ( mRoles.value ( role ) == mDispRoleName ) {
        rolesList.append ( Qt::DisplayRole );
      }

      emit dataChanged ( index, index, rolesList );
    }

    if ( !mUidRoleName.isEmpty () ) {
      const QByteArray roleName = mRoles.value ( role, emptyBA () );

      if ( !roleName.isEmpty () && roleName == mUidRoleName ) {
        const QString key = mUidIndex.key ( item, emptyStr () );

        if ( !key.isEmpty () ) {
          mUidIndex.remove ( key );
        }

        const QString value = item->property ( mUidRoleName ).toString ();

        if ( !value.isEmpty () ) {
          mUidIndex.insert ( value, item );
        }
      }
    }
  }
  inline void updateCounter (  )
  {
    if ( m_count != mItemTypes.count () ) {
      m_count = mItemTypes.count ();
      emit countChanged ();
    }
  }

private: // data members
  int m_count;
  QByteArray mUidRoleName;
  QByteArray mDispRoleName;
  QMetaObject mMetaObject;
  QMetaMethod mPropertyChangedHandler;
  QHash<int, QByteArray> mRoles;
  QHash<int, int> mRoleSignals;
  QList<ItemType*> mItemTypes;
  QHash<QString, ItemType*> mUidIndex;
};



