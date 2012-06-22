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
    void startPlaying(QTcpSocket* client);
    void printState(QAudio::State state);

private:
    QAudioOutput *m_audioOutput;
    QAudioFormat m_format;
};

#endif // AUDIOPLAYBACK_H
