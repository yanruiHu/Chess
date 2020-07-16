#include "Backstep.h"
#include<QGridLayout>
#include<QVBoxLayout>
Backstep::Backstep(QWidget*parent):QWidget(parent)
{
   QGridLayout *grid=new QGridLayout(this);
   QVBoxLayout *vLay=new QVBoxLayout;
   grid->setColumnStretch(0,1);
   grid->setColumnStretch(2,1);
   grid->setRowStretch(0,1);
   grid->setRowStretch(2,1);
   grid->addLayout(vLay,1,1);
   vLay->addWidget(this->_backstep=new QPushButton("悔棋"));
   connect(this->_backstep,SIGNAL(clicked()),this,SIGNAL(sigBack()));
}
Backstep::~Backstep(){}
