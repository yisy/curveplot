#include "cureimagecontent.h"
#include "ui_cureimagecontent.h"

#include <QVector>
#include <QTimer>
#include <iostream>
#include <QMenu>

CureImageContent::CureImageContent(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CureImageContent)
{
    ui->setupUi(this);

    srand(100);
    startPlot();

    num = 101;
    ui->qCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                     QCP::iSelectLegend | QCP::iSelectPlottables);
    //自定义右键菜单
    ui->qCustomPlot->setContextMenuPolicy(Qt::CustomContextMenu);

    initConnect();
}

void CureImageContent::initConnect()
{
  connect(ui->qCustomPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(mousePress()));
  connect(ui->qCustomPlot,SIGNAL(mouseWheel(QWheelEvent*)),this,SLOT(mouseWheel()));
  connect(ui->qCustomPlot,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(contextMenuRequest(QPoint)));

}

void CureImageContent::contextMenuRequest(QPoint point){
    QMenu *menu = new QMenu(this);
    menu->setAttribute(Qt::WA_DeleteOnClose);
    menu->addAction("close",this,SLOT(close()));

    menu->popup(ui->qCustomPlot->mapToGlobal(point));
}

void CureImageContent::mouseWheel()
{
    if(ui->qCustomPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->qCustomPlot->axisRect()->setRangeZoom(ui->qCustomPlot->xAxis->orientation());
    else if(ui->qCustomPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->qCustomPlot->axisRect()->setRangeZoom(ui->qCustomPlot->yAxis->orientation());
    else
        ui->qCustomPlot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}

void CureImageContent::mousePress()
{
    if(ui->qCustomPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->qCustomPlot->axisRect()->setRangeDrag(ui->qCustomPlot->xAxis->orientation());
    else if(ui->qCustomPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->qCustomPlot->axisRect()->setRangeDrag(ui->qCustomPlot->yAxis->orientation());
    else
        ui->qCustomPlot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
}

void CureImageContent::startPlot(){

    for(int i=0;i<101;i++){
        x.push_back(i/5 -10);
        y.push_back( x[i] * x[i] * x[i]);

    }

    ui->qCustomPlot->addGraph();

    ui->qCustomPlot->graph(0)->setData(x,y);

    ui->qCustomPlot->xAxis->setLabel("x");
    ui->qCustomPlot->yAxis->setLabel("y");

    ui->qCustomPlot->xAxis->setRange(-11,11);
    ui->qCustomPlot->yAxis->setRange(0,1100);



    QTimer *t = new QTimer();
    t->setInterval(10);
    t->start();
    connect(t,SIGNAL(timeout()),this,SLOT(onTimerOut()));

}

void CureImageContent::onTimerOut(){

    num ++;
    ui->qCustomPlot->graph(0)->addData(num,rand()%1000);
    ui->qCustomPlot->replot();
    ui->qCustomPlot->xAxis->setRange(0,num);

    //ui->qCustomPlot->repaint();
}

CureImageContent::~CureImageContent()
{
    delete ui;
}
