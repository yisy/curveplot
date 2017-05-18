#ifndef USBCONNECTION_H
#define USBCONNECTION_H

#include <QFrame>

namespace Ui {
class USBConnection;
}

class USBConnection : public QFrame
{
    Q_OBJECT

public:
    explicit USBConnection(QWidget *parent = 0);
    ~USBConnection();

private:
    Ui::USBConnection *ui;
};

#endif // USBCONNECTION_H
