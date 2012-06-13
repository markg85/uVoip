#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

/*
 * The server receives data and plays it.
 * It doesn't send any data!
 */

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    
signals:
    
public slots:
    void connectionHandler();
    void processIncomingData();

private:
    QTcpServer m_server;

    // TODO: this is for just 1 client meaning you can only have a 1on1 conversation, not multiple people in 1 call.
    QTcpSocket* m_clientConnection;
    
};

#endif // SERVER_H
