#ifndef UVOIPDATA_H
#define UVOIPDATA_H

#include <QDeclarativeItem>

class UVoipData : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(qreal hostMicrophoneLevel READ hostMicrophoneLevel NOTIFY hostMicrophoneLevelChanged)
    Q_PROPERTY(qreal remoteMicrophoneLevel READ remoteMicrophoneLevel NOTIFY remoteMicrophoneLevelChanged)
    Q_PROPERTY(QString socketUrl READ socketUrl WRITE setSocketUrl NOTIFY socketUrlChanged)
    Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged)
public:
    explicit UVoipData(QDeclarativeItem *parent = 0);
    qreal hostMicrophoneLevel();
    qreal remoteMicrophoneLevel();
    const QString& socketUrl();
    Q_INVOKABLE void requestConnect();
    Q_INVOKABLE void requestDisconnect();
    bool connected();
    
signals:
    void hostMicrophoneLevelChanged();
    void remoteMicrophoneLevelChanged();
    void socketUrlChanged();
    void requestConnectChanged();
    void requestDisconnectChanged();
    void connectedChanged();
    
public slots:
    void setHostMicrophoneLevel(qreal level);
    void setRemoteMicrophoneLevel(qreal level);
    void setSocketUrl(const QString& url);
    void setConnected(bool isConnected);

private:
    qreal m_hostMicLevel;
    qreal m_remoteMicLevel;
    QString m_socketUrl;
    bool m_connected;
};

#endif // UVOIPDATA_H
