#include "server.h"

#include <QDebug>


Server::Server(UVoipData* voipData, QObject *parent)
    : QObject(parent)
    , m_server()
    , m_clientConnection()
    , m_playback()
    , m_voipData(voipData)
{
    connect(&m_server, SIGNAL(newConnection()), this, SLOT(connectionHandler()));
    m_server.listen(QHostAddress::Any, 1985);

    connect(m_voipData, SIGNAL(clientConnectedChanged()), this, SLOT(clientConnectionChanged()), Qt::DirectConnection);
}

void Server::connectionHandler()
{
    m_clientConnection = m_server.nextPendingConnection();
    connect(m_clientConnection, SIGNAL(disconnected()), this, SLOT(connectionClosed()), Qt::DirectConnection);

    m_voipData->setServerConnected(true);
}

void Server::clientConnectionChanged()
{
    if(m_voipData->clientConnected() && m_clientConnection)
    {
        m_clientConnection->setSocketOption(QTcpSocket::LowDelayOption, 1);
        m_playback.startPlaying(m_clientConnection);
        qDebug() << "Server::clientConnected true";
    }
    else
    {
        m_clientConnection->close();
        qDebug() << "Server::clientConnected false";
    }
}

void Server::connectionClosed()
{
    m_voipData->setServerConnected(false);
}
