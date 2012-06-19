#include "uvoipdata.h"

#include <QDebug>

UVoipData::UVoipData(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
    , m_hostMicLevel(0)
    , m_remoteMicLevel(0)
    , m_socketUrl()
    , m_connected(false)
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

bool UVoipData::connected()
{
    return m_connected;
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

void UVoipData::setConnected(bool isConnected)
{
    m_connected = isConnected;
    emit connectedChanged();
}


