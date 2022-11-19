INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

QT += core gui
!build_gifimage_lib:DEFINES += GIFIMAGE_NO_LIB

include($$PWD/../gif_lib/giflib.pri)

HEADERS += \
    $$PWD/qgifglobal.h \
    $$PWD/qgifimage.h \
    $$PWD/qgifimage_p.h

SOURCES += \ 
    $$PWD/qgifimage.cpp
