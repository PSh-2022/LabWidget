QT += gui# используемые средства Qt: графический интерфейс
QT += widgets# используемые средства Qt: виджеты


CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        area.cpp \
        figura.cpp \
        main.cpp \
        win27.cpp \
        win28.cpp \
        window.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    area.h \
    figura.h \
    win27.h \
    win28.h \
    window.h
