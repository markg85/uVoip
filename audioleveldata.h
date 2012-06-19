#ifndef AUDIOLEVELDATA_H
#define AUDIOLEVELDATA_H

#include <QDeclarativeItem>

class AudioLevelData : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(qreal hostMicrophoneLevel READ hostMicrophoneLevel NOTIFY hostMicrophoneLevelChanged)
    Q_PROPERTY(qreal remoteMicrophoneLevel READ remoteMicrophoneLevel NOTIFY remoteMicrophoneLevelChanged)
public:
    explicit AudioLevelData(QDeclarativeItem *parent = 0);
    qreal hostMicrophoneLevel();
    qreal remoteMicrophoneLevel();
    
signals:
    void hostMicrophoneLevelChanged();
    void remoteMicrophoneLevelChanged();
    
public slots:
    void setHostMicrophoneLevel(qreal level);
    void setRemoteMicrophoneLevel(qreal level);

private:
    qreal m_hostMicLevel;
    qreal m_remoteMicLevel;
};

#endif // AUDIOLEVELDATA_H
