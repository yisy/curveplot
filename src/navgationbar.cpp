#include "navgationbar.h"
#include "ui_navgationbar.h"

NavgationBar::NavgationBar(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::NavgationBar)
{
    ui->setupUi(this);

       navgationButtons = new QList<QPushButton*>();

       this->setObjectName("navgationBar");

       navgationButtons->append(ui->connectSetting);
       navgationButtons->append(ui->cureImage);
       navgationButtons->append(ui->pointCloudImage);


       for(int i=0;i<navgationButtons->size();i++){
           navgationButtons->at(i)->setCheckable(true);
           connect(navgationButtons->at(i),SIGNAL(clicked(bool)),this,SLOT(setButtonChecked()));
       }

       //默认设置被选中
       navgationButtons->at(0)->setChecked(true);
}
void NavgationBar::setButtonChecked(){
    for(int i=0;i<navgationButtons->size();++i){

        if(navgationButtons->at(i) == sender())
        {
           navgationButtons->at(i)->setChecked(true);
           emit indexChanged(i);
        }else{
            navgationButtons->at(i)->setChecked(false);
        }
    }

}
NavgationBar::~NavgationBar()
{
    delete ui;
}
