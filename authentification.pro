QT       += core gui sql
QT       += sql
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    admin.cpp \
    congee.cpp \
    connection.cpp \
    delegate.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    ouvrier.cpp \
    prod.cpp \
    produitch.cpp \
    produitph.cpp \
    smtp.cpp

HEADERS += \
    admin.h \
    congee.h \
    connection.h \
    delegate.h \
    dialog.h \
    mainwindow.h \
    menu.h \
    ouvrier.h \
    prod.h \
    produitch.h \
    produitph.h \
    smtp.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    menu.ui \
    prod.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sour.qrc

DISTFILES += \
    source/autentificeation.jpg
