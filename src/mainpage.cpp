#include "mainpage.h"
#include "ui_mainpage.h"

#include <QPushButton>
#include <iostream>
#include <QStackedWidget>

#include "settingcontent.h"
#include "cureimagecontent.h"

MainPage::MainPage(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    mainLayout = new QHBoxLayout();
    stackWidget = new QStackedWidget();
    setObjectName("mainPage");

    setMinimumHeight(600);
    setMinimumWidth(1000);

    mainLayout->addWidget(stackWidget);

    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);

    stackWidget->addWidget(new SettingContent());
    stackWidget->addWidget(new CureImageContent());
    stackWidget->addWidget(new QPushButton("3"));
    stackWidget->setContentsMargins(0,0,0,0);

}

void MainPage::switchScreen(const int index)
{
    stackWidget->setCurrentIndex(index);
    std::cout << index <<std::endl;
}


MainPage::~MainPage()
{
    delete ui;
}
