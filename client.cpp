#include "client.h"
#include <QHostAddress>
#include <QDebug>


Client::Client(QObject *parent)
    : QObject(parent)
    , m_client()
{
    connect(&m_client, SIGNAL(connected()), this, SLOT(sendAudio()), Qt::DirectConnection);
}

void Client::connectToServer(const QString &address, uint port)
{
    QHostAddress addr(address);
    m_client.connectToHost(addr, port);
}

QTcpSocket *Client::socket()
{
    return &m_client;
}

void Client::sendAudio()
{
    m_client.write(QByteArray("Howdy, this is send from the client to the server!"));
    qDebug() << "The client has just send some data!";
    emit connectedSocket(&m_client);
}
