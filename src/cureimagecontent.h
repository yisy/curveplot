#ifndef CUREIMAGECONTENT_H
#define CUREIMAGECONTENT_H

#include <QFrame>
#include <QThread>
#include <QPoint>

namespace Ui {
class CureImageContent;
}

class CureImageContent : public QFrame
{
    Q_OBJECT

public:
    explicit CureImageContent(QWidget *parent = 0);
    ~CureImageContent();
protected:
    void startPlot();
public slots:
    void onTimerOut();
    void initConnect();

    void mousePress();
    void mouseWheel();
    void contextMenuRequest(QPoint);
private:
    QVector<double> x,y;
    Ui::CureImageContent *ui;
    int num;
};

#endif // CUREIMAGECONTENT_H
