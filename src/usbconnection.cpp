#include "usbconnection.h"
#include "ui_usbconnection.h"

USBConnection::USBConnection(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::USBConnection)
{
    ui->setupUi(this);
}

USBConnection::~USBConnection()
{
    delete ui;
}
