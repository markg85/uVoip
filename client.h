#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

/*
 * The client sends data to the server.
 * It doesn't play any data!
 */

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    void connectToServer(const QString& address, uint port);
    QTcpSocket* socket();
    
signals:
    void connectedSocket(QTcpSocket*);
    
public slots:
    void sendAudio();
    
private:
    QTcpSocket m_client;
};

#endif // CLIENT_H
