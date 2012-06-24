#include "uvoipdata.h"

#include <QDebug>

UVoipData::UVoipData(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
    , m_hostMicLevel(0)
    , m_remoteMicLevel(0)
    , m_socketUrl()
    , m_clientConnected(false)
    , m_serverConnected(false)
{
}

qreal UVoipData::hostMicrophoneLevel()
{
    return m_hostMicLevel;
}

void UVoipData::setHostMicrophoneLevel(qreal level)
{
    m_hostMicLevel = level;
    emit hostMicrophoneLevelChanged();
}

qreal UVoipData::remoteMicrophoneLevel()
{
    return m_remoteMicLevel;
}

const QString &UVoipData::socketUrl()
{
    return m_socketUrl;
}

void UVoipData::requestConnect()
{
    emit requestConnectChanged();
}

void UVoipData::requestDisconnect()
{
    emit requestDisconnectChanged();
}

bool UVoipData::clientConnected()
{
    return m_clientConnected;
}

bool UVoipData::serverConnected()
{
    return m_serverConnected;
}

void UVoipData::setRemoteMicrophoneLevel(qreal level)
{
    m_remoteMicLevel = level;
    emit remoteMicrophoneLevelChanged();
}

void UVoipData::setSocketUrl(const QString &url)
{
    qDebug() << "Socket url received:" << url;

    m_socketUrl = url;
    emit socketUrlChanged();
}

void UVoipData::setClientConnected(bool isConnected)
{
    if(m_clientConnected != isConnected)
    {
        m_clientConnected = isConnected;
        emit clientConnectedChanged();
    }
}

void UVoipData::setServerConnected(bool isConnected)
{
    if(m_serverConnected != isConnected)
    {
        m_serverConnected = isConnected;
        emit serverConnectedChanged();
    }
}

void UVoipData::emitClientConnectionFailed()
{
    emit clientConnectionFailedChanged();
}


