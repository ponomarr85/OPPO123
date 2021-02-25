QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_dialog.cpp \
    auth_dialog.cpp \
    department.cpp \
    departments.cpp \
    departments_table.cpp \
    main.cpp \
    worker.cpp \
    worker_dialog.cpp \
    worker_layout.cpp \
    workers.cpp \
    workers_table.cpp

HEADERS += \
    admin_dialog.h \
    auth_dialog.h \
    department.h \
    departments.h \
    departments_table.h \
    worker.h \
    worker_dialog.h \
    worker_layout.h \
    workers.h \
    workers_table.h

FORMS += \
    auth_dialog.ui

TRANSLATIONS += \
    test_en_150.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Workers.bin
