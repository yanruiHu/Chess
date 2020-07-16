#include "Mainwindow.h"
#include<QHBoxLayout>
#include"Oneperson.h"
#include"Twoperson.h"
#include"Backstep.h"
//主界面
Mainwindow::Mainwindow(int gametype,QWidget*parent):QWidget(parent)
{
    _gametype=gametype;
    if(_gametype==0)
    {
        Oneperson *game=new Oneperson;
        Backstep *step=new Backstep;
        QHBoxLayout*lay=new QHBoxLayout(this);
        lay->addWidget(game,1);
        lay->addWidget(step);
        connect(step,SIGNAL(sigBack()),game,SLOT(slotBack()));
    }
    else if(_gametype==1)
    {
        Twoperson *game=new Twoperson;
        Backstep *step=new Backstep;
        QHBoxLayout*lay=new QHBoxLayout(this);
        lay->addWidget(game,1);
        lay->addWidget(step);
        connect(step,SIGNAL(sigBack()),game,SLOT(slotBack()));
    }
}
Mainwindow::~Mainwindow(){}
