#include "settingcontent.h"
#include "ui_settingcontent.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QStackedLayout>
#include "serialconnection.h"
#include "usbconnection.h"
#include "tcpconnection.h"
#include <QIcon>
#include <QListWidgetItem>

SettingContent::SettingContent(QFrame *parent) :
    QFrame(parent),
    ui(new Ui::SettingContent)
{
    ui->setupUi(this);

    styleSelect = new QListWidget(this);
    styleSelect->addItem(new QListWidgetItem(QIcon(":/image/serial.png"),"串口连接"));
    styleSelect->addItem(new QListWidgetItem(QIcon(":/image/usb.png"),"USB连接"));
    styleSelect->addItem(new QListWidgetItem(QIcon(":/image/tcp.png"),"TCP/IP连接"));
    styleSelect->setViewMode(QListView::IconMode);

   styleContent = new QStackedWidget();
   styleSelect->setObjectName("styleSelect");

   styleSelect->setCurrentRow(0);

   styleContent->addWidget(new SerialConnection());
   styleContent->addWidget(new USBConnection());
   styleContent->addWidget(new TCPConnection());

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(styleSelect);

    mainLayout->addWidget(styleContent);

    mainLayout->setStretchFactor(styleSelect,-1);
    mainLayout->setStretchFactor(styleContent,10);


    connect(styleSelect,SIGNAL(currentRowChanged(int)),styleContent,SLOT(setCurrentIndex(int)));

}

SettingContent::~SettingContent()
{
    delete ui;
}
