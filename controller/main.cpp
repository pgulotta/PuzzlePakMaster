#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "initializer.hpp"
#include <QStyleHints>



int main( int argc, char* argv[] )
{
  QCoreApplication::setAttribute( Qt::AA_EnableHighDpiScaling );
  QGuiApplication app( argc, argv );
  QObject::connect( &app, &QGuiApplication::lastWindowClosed, &app, &QGuiApplication::quit );
  QCoreApplication::setApplicationName( QObject::tr( "Puzzle Pak" ) );
  QCoreApplication::setOrganizationDomain( "twentysixapps.com" );
  QCoreApplication::setOrganizationName( QLatin1String( "26Apps" ) );
  QCoreApplication::setApplicationVersion( "1.20" );
  QQuickStyle::setStyle( "Material" );
  Initializer initializer( &app );
  return app.exec();
}
