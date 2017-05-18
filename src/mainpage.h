#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QFrame>
#include <QStackedWidget>
#include <QHBoxLayout>

namespace Ui {
class MainPage;
}

class MainPage : public QFrame
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    QStackedWidget *stackWidget;
        QHBoxLayout * mainLayout;
    ~MainPage();
public slots:
    void switchScreen(const int);
private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
