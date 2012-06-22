#ifndef AUDIOPLAYBACK_H
#define AUDIOPLAYBACK_H

#include <QObject>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QTcpSocket>

class AudioPlayback : public QObject
{
    Q_OBJECT
public:
    explicit AudioPlayback(QObject *parent = 0);
    
signals:
    
public slots:
    void stopPlaying();
    void startPlaying(QIODevice *stream);
    void printState(QAudio::State state);
    void processIncomingData();

private:
    QIODevice *m_stream;
    QAudioOutput *m_audioOutput;
    QAudioFormat m_format;
};

#endif // AUDIOPLAYBACK_H
