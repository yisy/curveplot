#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QFrame>

namespace Ui {
class TCPConnection;
}

class TCPConnection : public QFrame
{
    Q_OBJECT

public:
    explicit TCPConnection(QWidget *parent = 0);
    ~TCPConnection();

private:
    Ui::TCPConnection *ui;
};

#endif // TCPCONNECTION_H
