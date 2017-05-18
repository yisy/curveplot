#ifndef NAVGATIONBAR_H
#define NAVGATIONBAR_H

#include <QFrame>
#include <QList>
#include <QPushButton>

namespace Ui {
class NavgationBar;
}

class NavgationBar : public QFrame
{
    Q_OBJECT

public:
    explicit NavgationBar(QWidget *parent = 0);
    ~NavgationBar();

    QList<QPushButton*> *navgationButtons;

public slots:
    void setButtonChecked();

signals:
    void indexChanged(int);

private:
    Ui::NavgationBar *ui;
};

#endif // NAVGATIONBAR_H
