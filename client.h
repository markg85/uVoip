#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

#include "uvoipdata.h"

/*
 * The client sends data to the server.
 * It doesn't play any data!
 */

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(UVoipData* voipData, QObject *parent = 0);
    QTcpSocket* socket();
    
signals:
    void connectedSocket(QTcpSocket*);
    
public slots:
    void attemptConnection();
    void attemptDisconnection();
    void disconnected();
    void sendAudio();
    
private:
    QTcpSocket m_client;
    UVoipData* m_voipData;
};

#endif // CLIENT_H
