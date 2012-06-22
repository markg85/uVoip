#include "audioplayback.h"
#include <QAudio>
#include <QDebug>

AudioPlayback::AudioPlayback(QObject *parent) :
    QObject(parent)
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
    if (!info.isFormatSupported(m_format))
    {
        qFatal("raw audio format not supported by backend, cannot play audio.");
    }
}

void AudioPlayback::stopPlaying()
{
    qDebug() << "AudioPlayback::stopPlaying";
    m_audioOutput->stop();
    //    delete m_audioOutput;
}

void AudioPlayback::startPlaying(QIODevice * stream)
{
    qDebug() << "AudioPlayback::startPlaying";

    m_audioOutput = new QAudioOutput(m_format);
    connect(m_audioOutput,SIGNAL(stateChanged(QAudio::State)),SLOT(printState(QAudio::State)));

    m_stream = stream;
    connect(m_stream, SIGNAL(readyRead()), this, SLOT(processIncomingData()), Qt::DirectConnection);
    
    //m_audioOutput->start(m_stream);
}

void AudioPlayback::printState(QAudio::State state)
{
    QString output("QAudioOutput state: ");

    switch(state)
    {
        case QAudio::ActiveState:
            output += "QAudio::ActiveState";
            break;
        case QAudio::SuspendedState:
            output += "QAudio::SuspendedState";
            break;
        case QAudio::StoppedState:
            output += "QAudio::StoppedState";
            break;
        case QAudio::IdleState:
            output += "QAudio::IdleState";
            m_audioOutput->stop();
            connect(m_stream, SIGNAL(readyRead()), this, SLOT(processIncomingData()), Qt::DirectConnection);
            break;
    }

    if(m_audioOutput->error() != QAudio::NoError)
    {
        output += ", error: ";
        switch(m_audioOutput->error())
        {
            case QAudio::NoError: // keeps QtCreator happy
            case QAudio::OpenError:
                output += "QAudio::OpenError";
                break;
            case QAudio::IOError:
                output += "QAudio::IOError";
                break;
            case QAudio::UnderrunError:
                output += "QAudio::UnderrunError";
                break;
            case QAudio::FatalError:
                output += "QAudio::FatalError";
                break;
        }
    }

    qDebug() << output;
}

void AudioPlayback::processIncomingData()
{
    qDebug() << "AudioPlayback::processIncomingData";

    disconnect(m_stream, SIGNAL(readyRead()), this, SLOT(processIncomingData()));
    m_audioOutput->start(m_stream);
    //m_audioOutput->start();
}

