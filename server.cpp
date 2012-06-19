#include "server.h"

#include <QDebug>


Server::Server(QObject *parent)
    : QObject(parent)
    , m_server()
    , m_clientConnection()
    , m_playback()
{
    connect(&m_server, SIGNAL(newConnection()), this, SLOT(connectionHandler()));
    m_server.listen(QHostAddress::Any, 1985);
}

void Server::connectionHandler()
{
    m_clientConnection = m_server.nextPendingConnection();

    m_playback.startPlaying(m_clientConnection);
    qDebug() << "(server) Connection established!";



//    connect(m_clientConnection, SIGNAL(readyRead()), this, SLOT(processIncomingData()), Qt::DirectConnection);
}

void Server::processIncomingData()
{
//    QByteArray data = m_clientConnection->readAll();


    qDebug() << m_clientConnection->readAll();
}
