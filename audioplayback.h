#ifndef AUDIOPLAYBACK_H
#define AUDIOPLAYBACK_H

#include <QObject>
#include <QFile>
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
    void finishedPlaying(QAudio::State state);

private:
    QFile m_inputFile;
    QAudioOutput *m_audioOutput;
    QAudioFormat m_format;

    
};

#endif // AUDIOPLAYBACK_H
