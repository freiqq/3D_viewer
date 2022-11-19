QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(src_gif/gifimage/qtgifimage.pri)

SOURCES += \
    ../3D_Viewer_backend/s21_affine_transformations.c \
    ../3D_Viewer_backend/s21_memory_handling.c \
    ../3D_Viewer_backend/s21_parsers.c \
    ../3D_Viewer_backend/s21_settings_bonus.c \
    create_gif_and_image.cpp \
    interaction_with_the_model.cpp \
    main.cpp \
    mainwindow.cpp \
    setters.cpp \
    viewer.cpp

HEADERS += \
    ../3D_Viewer_backend/s21_affine_transformations.h \
    ../3D_Viewer_backend/s21_common.h \
    ../3D_Viewer_backend/s21_memory_handling.h \
    ../3D_Viewer_backend/s21_parsers.h \
    ../3D_Viewer_backend/s21_settings_bonus.h \
    mainwindow.h \
    viewer.h

FORMS += \
    mainwindow.ui \
    viewer.ui \
    viewer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
