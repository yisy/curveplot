#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

#include "navgationbar.h"
#include "mainpage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVBoxLayout *mainLayout;

    NavgationBar *navgationBar;
    MainPage *mainPage;

    void initConnect();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
