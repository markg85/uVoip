#include "client.h"
#include <QHostAddress>
#include <QStringList>
#include <QDebug>


Client::Client(UVoipData* voipData, QObject *parent)
    : QObject(parent)
    , m_client()
    , m_voipData(voipData)
{
    connect(&m_client, SIGNAL(connected()), this, SLOT(sendAudio()), Qt::DirectConnection);
    connect(&m_client, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);
    connect(m_voipData, SIGNAL(requestConnectChanged()), this, SLOT(attemptConnection()), Qt::DirectConnection);
    connect(m_voipData, SIGNAL(requestDisconnectChanged()), this, SLOT(attemptDisconnection()), Qt::DirectConnection);
}

QTcpSocket *Client::socket()
{
    return &m_client;
}

void Client::sendAudio()
{
//    qDebug() << "The client has just send some data!";

    m_voipData->setConnected(true);
    emit connectedSocket(&m_client);
}


void Client::attemptConnection()
{

    QStringList list = m_voipData->socketUrl().split(":", QString::SkipEmptyParts);
    QString host = list.first();
    int port = list.last().toInt();

    qDebug() << "Client::attemptConnection" << m_voipData->socketUrl();
    qDebug() << "--> Host:" << host;
    qDebug() << "--> Port:" << port;

    m_client.connectToHost(host, port);
}

void Client::attemptDisconnection()
{
    m_client.disconnectFromHost();
}

void Client::disconnected()
{
    m_voipData->setConnected(false);
}
