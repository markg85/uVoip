#ifndef AUDIOSTREAM_H
#define AUDIOSTREAM_H

#include <QFile>
#include <QAudioInput>
#include <QAudioFormat>

// This is going to be inherited by a QTcpSocket to put the audio in a socket for some client to register to and listen to the audio
class AudioStream : public QIODevice
{
    Q_OBJECT
public:
    explicit AudioStream(QObject *parent = 0);
    void start();
    void stop();

    qreal level() const { return m_level; }
    qint64 writeData(const char *data, qint64 len);
    qint64 readData(char *data, qint64 maxlen);


signals:
    void update();
    
public slots:

private:
    QAudioFormat m_format;
    QAudioInput* m_audioInput;
    quint16 m_maxAmplitude;
    qreal m_level; // 0.0 <= m_level <= 1.0
    
};

#endif // AUDIOSTREAM_H
