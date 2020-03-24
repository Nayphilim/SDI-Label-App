QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SDILabelApp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    classfile.cpp \
    classmanagement.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    classfile.h \
    classmanagement.h \
    mainwindow.h

FORMS += \
    classmanagement.ui \
    mainwindow.ui

INCLUDEPATH += $$PWD/thirdparty/opencv/include

LIBS += -L$$PWD/thirdparty/opencv/bin/libopencv_core420.dll
LIBS += -L$$PWD/thirdparty/opencv/bin/libopencv_highgui420.dll
LIBS += -L$$PWD/thirdparty/opencv/bin/libopencv_imgcodecs420.dll
LIBS += -L$$PWD/thirdparty/opencv/bin/libopencv_imgproc420.dll
LIBS += -L$$PWD/thirdparty/opencv/bin/libopencv_features2d420.dll
LIBS += -L$$PWD/thirdparty/opencv/bin/libopencv_calib3d420.dll

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_core420.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_core420.dlld
else:unix: LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_core420.dll

INCLUDEPATH += $$PWD/thirdparty/opencv/include
DEPENDPATH += $$PWD/thirdparty/opencv/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_calib3d420.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_calib3d420.dlld
else:unix: LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_calib3d420.dll

INCLUDEPATH += $$PWD/thirdparty/opencv/include
DEPENDPATH += $$PWD/thirdparty/opencv/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_imgcodecs420.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_imgcodecs420.dlld
else:unix: LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_imgcodecs420.dll

INCLUDEPATH += $$PWD/thirdparty/opencv/include
DEPENDPATH += $$PWD/thirdparty/opencv/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_imgproc420.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_imgproc420.dlld
else:unix: LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_imgproc420.dll

INCLUDEPATH += $$PWD/thirdparty/opencv/include
DEPENDPATH += $$PWD/thirdparty/opencv/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_features2d420.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_features2d420.dlld
else:unix: LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_features2d420.dll

INCLUDEPATH += $$PWD/thirdparty/opencv/include
DEPENDPATH += $$PWD/thirdparty/opencv/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_highgui420.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_highgui420.dlld
else:unix: LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_highgui420.dll

INCLUDEPATH += $$PWD/thirdparty/opencv/include
DEPENDPATH += $$PWD/thirdparty/opencv/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/Qt5/lib/ -lQt5Core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/Qt5/lib/ -lQt5Cored
else:unix: LIBS += -L$$PWD/thirdparty/Qt5/lib/ -lQt5Core

INCLUDEPATH += $$PWD/thirdparty/Qt5/include
DEPENDPATH += $$PWD/thirdparty/Qt5/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/Qt5/lib/ -lQt5Gui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/Qt5/lib/ -lQt5Guid
else:unix: LIBS += -L$$PWD/thirdparty/Qt5/lib/ -lQt5Gui

INCLUDEPATH += $$PWD/thirdparty/Qt5/include
DEPENDPATH += $$PWD/thirdparty/Qt5/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/Qt5/lib/ -lQt5Widgets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/Qt5/lib/ -lQt5Widgetsd
else:unix: LIBS += -L$$PWD/thirdparty/Qt5/lib/ -lQt5Widgets

INCLUDEPATH += $$PWD/thirdparty/Qt5/include
DEPENDPATH += $$PWD/thirdparty/Qt5/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_features2d420.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_features2d420.dlld
else:unix: LIBS += -L$$PWD/thirdparty/opencv/lib/ -llibopencv_features2d420.dll

INCLUDEPATH += $$PWD/thirdparty/opencv/include
DEPENDPATH += $$PWD/thirdparty/opencv/include
