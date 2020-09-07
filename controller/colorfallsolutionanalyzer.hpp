#pragma once

#include <QObject>
#include <QVariantList>
#include <QColor>


class ColorFallSolutionAnalyzer : public QObject
{
  Q_OBJECT
public:
  QList<int> findColorGroupIndexes( int index, int columnCount, QVariantList grid );
  QStringList getUpdatedFillColors( int columnCount,  QList<int> indexColors,  QStringList colors );


  explicit ColorFallSolutionAnalyzer( QObject* parent = nullptr );

signals:

public slots:


private:
  void convert( const QVariantList& source,  QList<QColor>& destination );
  void findColorGroupIndexes( int index, int indexRow, int indexColumn,  const QList<QColor>& grid ) ;
  void removeMissingColumns();

private:
  int populateFillColor( int currentIndex,  int columnCount,  QList<int>& indexColors );
  void setFillColor( int index, QString color );

  QList<int> mIndexColors;
  QStringList mFillColors;
  int mColumnCount;
  int mRowCount;
  QColor mGroupColor;


};

