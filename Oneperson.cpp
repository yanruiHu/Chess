#include "Oneperson.h"
#include<QMouseEvent>
#include<QMessageBox>
#include<QDebug>
Oneperson::Oneperson(QWidget*parent):Board(parent){}

void Oneperson::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint point=event->pos();
    int row;
    int column;
    bool ret=getRowandColumn(point,row,column);
    if(ret==false) return;
    int i;
    int clickid=-1;
    qDebug()<<"END init:"<<end;
    for(i=0;i<32;i++)
    {
        if(c[i]._row==row&&c[i]._column==column&&c[i].dead_ornot==false)
        {
            break;
        }
    }
    if(i<32)//获得这次点击的棋子id
    {
        clickid=i;
    }
   if(_chooseid==-1)//选中一枚棋子
   {
       if(clickid!=-1)
       {
           if(_beRedTurn==c[clickid].red_ornot)//只能选本方的棋子
           {
              _chooseid=clickid;
              update();
           }
       }
   }
   else//移动选中的棋子
   {
       if(canmove(_chooseid,row,column,clickid))
       {
           saveStep(_chooseid,clickid,row,column);
            c[_chooseid]._row=row;
            c[_chooseid]._column=column;
            if(clickid!=-1)//吃掉另一枚棋子
            {
                QSound::play(":/new/prefix2/Eat.wav");
              c[clickid].dead_ornot=true;
            }
            _chooseid=-1;
            _beRedTurn=!_beRedTurn;
            update();
            if(c[4].dead_ornot || c[20].dead_ornot)
            {
                end = 1;
            }
            if(end==1)
            {
                qDebug()<<"END P2:"<<end;
              if(_beRedTurn)
              QMessageBox::information(this,"游戏结束","黑方胜利");
              else
              QMessageBox::information(this,"游戏结束","红方胜利");
              end=-1;
            }
            /*黑棋电脑走*/
            {
                ai();
                if (aimove[0] == -1&& aimove[1]==-1)/*发现没能吃的棋子,电脑乱走*/
                {
                    for(int temp_id=16;temp_id<32;temp_id++)
                        if (c[temp_id].dead_ornot != true)/*看死了没*/
                            for (int row = 1; row < 11; row++)
                                for (int colum = 1; colum < 10; colum++)/*遍历棋盘*/
                                {
                                    bool yrn = canMoveAI(temp_id, row, colum , -1);
                                    if (yrn == true)/*能走就走*/
                                    {
                                        saveStep(temp_id,-1,row,column);
                                        c[temp_id]._row = row;
                                        c[temp_id]._column = colum;
                                        goto here;/*跳出多层循环*/
                                    }
                                }
                here:;
                }
                else if(aimove[0]!=-1&&aimove[1]!=-1)/*有能吃的棋子,直接吃*/
                {
                    QSound::play(":/new/prefix2/Eat.wav");
                    if(c[aimove[0]]._type==Chessman::Jiang)
                    {
                        end=1;
                    }
                    saveStep(aimove[0],aimove[1],row,column);
                    c[aimove[0]]._row = c[aimove[1]]._row;
                    c[aimove[0]]._column = c[aimove[1]]._column;
                    c[aimove[1]].dead_ornot = true;/*三行为吃棋*/
                }
                _beRedTurn = !_beRedTurn;/*红黑交替*/
                update();
                qDebug()<<"END ai:"<<end;
                if(end==1)
                {
                  if(_beRedTurn)
                  QMessageBox::information(this,"游戏结束","黑方胜利");
                  else
                  QMessageBox::information(this,"游戏结束","红方胜利");
                  end=-1;
                }
                /*ai到此结束*/
            }
       }
   }

 }


/*ai核心*/
void Oneperson::ai()
{
    int record_chooseid = 0;
    int record_killid = 0;
    int record_score = 0;/*三项记录,记录最高所有可能的吃法中的最高分数*/
    for (int i = 16; i < 32; i++)/*遍历行棋方id*/
        {
            for (int j = 0; j < 15; j++)
                {
                    int score = 0;/*三项临时数据,每种走法*/
                    if (canmove(i, c[j]._row,c[j]._column, j))
                    {
                        switch (c[j]._type)/*吃子得分*/
                        {
                        case Chessman::Che:score = 9; break;
                        case Chessman::Ma:score = 4; break;
                        case Chessman::Pao:score = 5; break;
                        case Chessman::Bing:score = 1; break;
                        case Chessman::Jiang:score = 1000; break;
                        case Chessman::Shi:score = 2; break;
                        case Chessman::Xiang:score = 2; break;
                        }
                    }
                    if (score > record_score)/*看分数会不会比历史分数高,要是高就是更好的走法*/
                    {
                        record_score = score;
                        record_chooseid = i;
                        record_killid = j;/*更改记录*/
                    }
                }
        }
    if (record_score != 0)/*吃到子了,分数变了*/
    {
        aimove[0] = record_chooseid;
        aimove[1] = record_killid;
    }
    else if(record_score==0)/*没子可吃*/
    {
        aimove[0] = -1;
        aimove[1] = -1;
    }
}
Oneperson::~Oneperson(){}
