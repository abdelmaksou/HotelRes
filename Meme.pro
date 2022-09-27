QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT       += core gui multimedia multimediawidgets
QT += widgets
QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aminities.cpp \
    availablecruise.cpp \
    availablehotels.cpp \
    choice.cpp \
    cruise.cpp \
    cruisesearch.cpp \
    customerprofile.cpp \
    edituser.cpp \
    existinguser.cpp \
    flights.cpp \
    graph.cpp \
    history.cpp \
    hotels.cpp \
    invoice.cpp \
    main.cpp \
    mainwindow.cpp \
    newuser.cpp \
    payment.cpp \
    promo.cpp \
    rating.cpp \
    reservation.cpp \
    rooms.cpp \
    targetflight.cpp \
    targethotel.cpp

HEADERS += \
    aminities.h \
    availablecruise.h \
    availablehotels.h \
    choice.h \
    cruise.h \
    cruisesearch.h \
    customerprofile.h \
    edituser.h \
    existinguser.h \
    flights.h \
    graph.h \
    history.h \
    hotels.h \
    invoice.h \
    mainwindow.h \
    newuser.h \
    payment.h \
    promo.h \
    rating.h \
    reservation.h \
    rooms.h \
    targetflight.h \
    targethotel.h

FORMS += \
    availablecruise.ui \
    availablehotels.ui \
    choice.ui \
    cruise.ui \
    cruisesearch.ui \
    customerprofile.ui \
    edituser.ui \
    existinguser.ui \
    flights.ui \
    history.ui \
    hotels.ui \
    invoice.ui \
    mainwindow.ui \
    newuser.ui \
    payment.ui \
    promo.ui \
    rating.ui \
    reservation.ui \
    targetflight.ui \
    targethotel.ui
    RC_ICONS = meme.ico
 #Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
