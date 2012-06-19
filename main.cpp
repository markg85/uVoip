#include <QApplication>
#include <QThread>
#include "qmlapplicationviewer.h"

#include "uvoip.h"
#include "server.h"
#include "client.h"
#include "audiostream.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QThread tcpServerThread;
    QThread tcpClientThread;
    QThread audioThread;
    Server tcpServer;
    Client tcpClient;
    AudioStream stream;
    UVoip w;

    tcpServer.moveToThread(&tcpServerThread);
    tcpServerThread.start();

    tcpClient.moveToThread(&tcpClientThread);
    tcpClientThread.start();

    stream.moveToThread(&audioThread);
    audioThread.start();
    stream.start();
    QObject::connect(&stream, SIGNAL(updateLevel(qreal)), &w, SLOT(slotUpdateLocalLevel(qreal)));

//    tcpClient.connectToServer("127.0.0.1", 1985);
    tcpClient.connectToServer("192.168.3.110", 1985);

    // Once we have a connection, we send the QTcpSocket with the connection to AudioStream.
    // AudioStream will then send the audio to the socket. I don't know if this is the best solution.
    QObject::connect(&tcpClient, SIGNAL(connectedSocket(QTcpSocket*)), &stream, SLOT(slotClientSocket(QTcpSocket*)));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/uVoip/main.qml"));
    viewer.showExpanded();

    w.show();

    return app->exec();
}
