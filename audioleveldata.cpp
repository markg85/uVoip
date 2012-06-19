#include "audioleveldata.h"

AudioLevelData::AudioLevelData(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
    , m_hostMicLevel(0)
    , m_remoteMicLevel(0)
{
}

qreal AudioLevelData::hostMicrophoneLevel()
{
    return m_hostMicLevel;
}

void AudioLevelData::setHostMicrophoneLevel(qreal level)
{
    m_hostMicLevel = level;
    emit hostMicrophoneLevelChanged();
}

qreal AudioLevelData::remoteMicrophoneLevel()
{
    return m_remoteMicLevel;
}

void AudioLevelData::setRemoteMicrophoneLevel(qreal level)
{
    m_remoteMicLevel = level;
    emit remoteMicrophoneLevelChanged();
}
