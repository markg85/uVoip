#include "audioplayback.h"
#include <QDebug>

AudioPlayback::AudioPlayback(QObject *parent) :
    QObject(parent)
    ,m_inputFile()
    ,m_audioOutput()
    ,m_format()
{
    m_format.setFrequency(8000);
    m_format.setChannels(1);
    m_format.setSampleSize(16);
    m_format.setSampleType(QAudioFormat::SignedInt);
    m_format.setByteOrder(QAudioFormat::LittleEndian);
    m_format.setCodec("audio/pcm");

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(m_format)) {
        qFatal("raw audio format not supported by backend, cannot play audio.");
    }
}

void AudioPlayback::stopPlaying()
{
    m_audioOutput->stop();
    m_inputFile.close();
    delete m_audioOutput;
}

void AudioPlayback::startPlaying(QTcpSocket *client)
{
    m_audioOutput = new QAudioOutput(m_format);
    connect(m_audioOutput,SIGNAL(stateChanged(QAudio::State)),SLOT(finishedPlaying(QAudio::State)));
    m_audioOutput->start(client);
}

void AudioPlayback::finishedPlaying(QAudio::State state)
{
    if (state == QAudio::IdleState) {
        m_audioOutput->stop();
        m_inputFile.close();
        delete m_audioOutput;
    }
}
