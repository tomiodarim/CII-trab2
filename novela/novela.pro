QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TRANSLATIONS = dicionario\novela_portugues.ts \
               dicionario\novela_ingles.ts

SOURCES += \
    controller\controllermain.cpp \
    controller\controllernovela.cpp \
    dao\dao.cpp \
    main.cpp \
    model\model.cpp \
    singleton\singletonlog.cpp \
    util\collection.cpp \
    util\parameter.cpp \
    view\viewconsultarnovela.cpp \
    view\viewmanternovela.cpp \
    view\viewMainWindow.cpp

HEADERS += \
    controller\controllermain.h \
    controller\controllernovela.h \
    dao\dao.h \
    model\modelnovela.h \
    model\model.h \
    singleton\singletonlog.h \
    util\collection.h \
    util\parameter.h \
    view\viewconsultarnovela.h \
    view\viewmanternovela.h \
    view\viewtreeitem.h \
    view\viewMainWindow.h

FORMS += \
    view\viewconsultarnovela.ui \
    view\viewmanternovela.ui \
    view\viewMainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource/resource.qrc

