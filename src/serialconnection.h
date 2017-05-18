#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H

#include <QFrame>

namespace Ui {
class SerialConnection;
}

class SerialConnection : public QFrame
{
    Q_OBJECT

public:
    explicit SerialConnection(QWidget *parent = 0);
    ~SerialConnection();

private:
    Ui::SerialConnection *ui;
};

#endif // SERIALCONNECTION_H
