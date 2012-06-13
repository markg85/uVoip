#include <QApplication>
#include <QThread>

#include "uvoip.h"
#include "server.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QThread tcpServerThread;
    QThread tcpClientThread;
    Server tcpServer;
    Client tcpClient;

    tcpServer.moveToThread(&tcpServerThread);
    tcpServerThread.start();

    tcpClient.moveToThread(&tcpClientThread);
    tcpClientThread.start();

    tcpClient.connectToServer("127.0.0.1", 1985);


//    UVoip w;

//    w.show();
    

    return a.exec();
}
