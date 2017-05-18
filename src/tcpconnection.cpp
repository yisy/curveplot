#include "tcpconnection.h"
#include "ui_tcpconnection.h"

TCPConnection::TCPConnection(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TCPConnection)
{
    ui->setupUi(this);
}

TCPConnection::~TCPConnection()
{
    delete ui;
}
