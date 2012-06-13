#include "server.h"

#include <QDebug>


Server::Server(QObject *parent)
    : QObject(parent)
    , m_server()
    , m_clientConnection()
{
    connect(&m_server, SIGNAL(newConnection()), this, SLOT(connectionHandler()));
    m_server.listen(QHostAddress::Any, 1985);
}

void Server::connectionHandler()
{
    m_clientConnection = m_server.nextPendingConnection();
    connect(m_clientConnection, SIGNAL(readyRead()), this, SLOT(processIncomingData()), Qt::DirectConnection);
}

void Server::processIncomingData()
{
    qDebug() << m_clientConnection->readAll();
}
