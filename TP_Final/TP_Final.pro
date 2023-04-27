QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        espaciotrabajo.cpp \
        gestoraic.cpp \
        gestordearchivos.cpp \
        gestorpnm.cpp \
        imagen.cpp \
        main.cpp \
        pixel.cpp \
        sistemaoperativo.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    espaciotrabajo.h \
    gestoraic.h \
    gestordearchivos.h \
    gestorpnm.h \
    imagen.h \
    pixel.h \
    sistemaoperativo.h
