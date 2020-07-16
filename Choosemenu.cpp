#include "Choosemenu.h"
#include<QVBoxLayout>
#include <QSound>
//选择菜单
Choosemenu::Choosemenu(QWidget *parent):QDialog(parent)
{
    QVBoxLayout *lay=new QVBoxLayout(this);
    lay->addWidget(_buttons[0]=new QPushButton("单人游戏"));
    lay->addWidget(_buttons[1]=new QPushButton("双人游戏"));
    for(int i=0;i<2;i++)
    {
        connect(_buttons[i],SIGNAL(clicked()),this,SLOT(slotClicked()));
    }
}
void Choosemenu::slotClicked()
{
    QObject*s=sender();
    for(int i=0;i<2;i++)
    {
        if(_buttons[i]==s)
        {
            this->_selected=i;
            break;
        }
    }
    accept();
   QSound::play(":/new/prefix2/NewGame.wav");
}
Choosemenu::~Choosemenu(){}
