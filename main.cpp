#include <QApplication>
#include <QThread>
#include <QDeclarativeContext>
#include "qmlapplicationviewer.h"

#include "server.h"
#include "client.h"
#include "audiostream.h"
#include "uvoipdata.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QThread tcpServerThread;
    QThread tcpClientThread;
    QThread audioThread;
    AudioStream stream;
    UVoipData uvoipData;
    Server tcpServer;
    Client tcpClient(&uvoipData);

    tcpServer.moveToThread(&tcpServerThread);
    tcpServerThread.start();

    tcpClient.moveToThread(&tcpClientThread);
    tcpClientThread.start();

    stream.moveToThread(&audioThread);
    audioThread.start();
    stream.start();
    QObject::connect(&stream, SIGNAL(updateLevel(qreal)), &uvoipData, SLOT(setHostMicrophoneLevel(qreal)), Qt::DirectConnection);
    QObject::connect(&tcpClient, SIGNAL(connectedSocket(QIODevice*)), &stream, SLOT(slotClientSocket(QIODevice*)), Qt::DirectConnection);
    QObject::connect(&uvoipData, SIGNAL(requestConnectChanged()), &tcpClient, SLOT(attemptConnection()), Qt::DirectConnection);
    QObject::connect(&uvoipData, SIGNAL(requestDisconnectChanged()), &tcpClient, SLOT(attemptDisconnection()), Qt::DirectConnection);

    QmlApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("uvoipData", &uvoipData);
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/uVoip/main.qml"));

    viewer.showExpanded();

    return app->exec();
}
