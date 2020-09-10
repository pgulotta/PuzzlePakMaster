TEMPLATE = app

QT += qml quick quickcontrols2

android {
    QT += androidextras
}

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG +=  c++1z

HEADERS += \
    controller/imageprovider.hpp \
    controller/imagesfactory.hpp \
    controller/tileslidegame.hpp \
    controller/puzzlepiecessolutionanalyzer.hpp \
    controller/colorfalliterator.hpp \
    controller/colorfallsolutionanalyzer.hpp \
    controller/shapesfactory.hpp \
    controller/gamecontroller.hpp \
    controller/initializer.hpp \
    controller/switchboardbuilder.hpp \
    controller/puzzlesfactory.hpp \
    controller/gamefactory.hpp \
    controller/tangramsiterator.hpp \
    controller/monochrometangramsiterator.hpp \
    controller/lineupiterator.hpp \
    controller/gameiterator.hpp \
    model/gamemetadata.hpp \
    model/shape.hpp \
    model/puzzle.hpp \
    model/piece.hpp \
    model/constants.hpp \
    model/score.hpp \
    datastore/dataaccessadapter.hpp \
    datastore/handle.hpp \
    datastore/sqlite.hpp \
    datastore/sqlite3.h \
    shared/qmlobjectlistmodel.hpp \


SOURCES += \
    controller/imageprovider.cpp \
    controller/imagesfactory.cpp \
    controller/tileslidegame.cpp \
    controller/main.cpp \
    controller/gamecontroller.cpp \
    controller/initializer.cpp \
    controller/shapesfactory.cpp \
    controller/gamefactory.cpp \
    controller/tangramsiterator.cpp \
    controller/monochrometangramsiterator.cpp \
    controller/lineupiterator.cpp \
    controller/puzzlepiecessolutionanalyzer.cpp \
    controller/colorfalliterator.cpp \
    controller/colorfallsolutionanalyzer.cpp \
    datastore/dataaccessadapter.cpp \
    datastore/sqlite3.c \


RESOURCES += qml.qrc

INCLUDEPATH += ../qml-box2d/Box2D
include(../qml-box2d/box2d-static.pri)


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -ldl
unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \

ANDROID_ABIS = armeabi-v7a arm64-v8a x86 x86_64



