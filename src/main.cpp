#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <iostream>
#include <QStyleFactory>
#include <iostream>
#include <QStyle>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    //添加样式
    QFile styleFile(":/qss/BB.qss");
    styleFile.open(QFile::ReadOnly);

    if(styleFile.isOpen()){
        a.setStyleSheet(styleFile.readAll());
        styleFile.close();
    }else{
        std::cout << "fail not open" << std::endl;

    }

    return a.exec();
}
