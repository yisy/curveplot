//解决中文乱码问题
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainLayout  = new QVBoxLayout(ui->centralWidget);
    navgationBar = new NavgationBar();
    mainPage  =  new MainPage();


    //添加组件
    mainLayout->addWidget(navgationBar);
    mainLayout->addWidget(mainPage);


    //设置组件间的比例
    mainLayout->setStretchFactor(navgationBar,1);
    mainLayout->setStretchFactor(mainPage,10);


    //设置布局中各组件的间隙
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    QIcon icon(":/image/icon.png");
    this->setWindowIcon(icon);

    this->setWindowTitle("激光三维成像");
    //this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);
    this->setGeometry(50,50,50,50);
    initConnect();
}



void MainWindow::initConnect()
{
    connect(navgationBar,SIGNAL(indexChanged(int)),mainPage,SLOT(switchScreen(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
