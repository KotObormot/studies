QT       += core gui sql                            # список модулей Qt, которые применяются в проекте

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets     # условие, когда добавлять конкретный модуль в проект

CONFIG += c++17                                     # при компиляции проекта применяется стандарт C++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# TEMPLATE: определяет тип проекта - будет ли при сборке проекта создавать исполняемое приложение, библиотека или плагин :
# TEMPLATE = lib

# Default rules for deployment. Платформозависимые настройки
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
