# Add more folders to ship with the application, here
folder_01.source = qml/uVoip
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

QT       += core gui multimedia network

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

SOURCES += main.cpp \
    server.cpp \
    client.cpp \
    audiostream.cpp \
    audioplayback.cpp \
    uvoipdata.cpp

HEADERS += \
    server.h \
    client.h \
    audiostream.h \
    audioplayback.h \
    uvoipdata.h

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

OTHER_FILES +=
