#include "Board.h"
#include<QPainter>
#include<QPen>
#include<QMouseEvent>
#include<QMessageBox>
Board::Board(QWidget *parent) : QFrame(parent)
{
     end = 0;
    init(true);
}
void Board::init(bool RedSide)
{
    for(int i=0;i<32;i++)//初始化棋子
    {
        c[i].init(i);
    }
    if(RedSide)
    {
      for(int i=0; i<32; ++i)
      {
        c[i].rotate();
      }
    }
    _chooseid=-1;
    _beRedTurn=true;
    _Side = RedSide;
}


void Board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int d=60;
    _r=d/2;
    //画10条水平线
    for(int i=1;i<=10;i++)
    {
        painter.drawLine(QPoint(d,i*d),QPoint(9*d,i*d));
    }
    //画9条垂直线
    for(int i=1;i<=9;i++)
    {
        if(i==1||i==9)
            painter.drawLine(QPoint(i*d,d),QPoint(i*d,10*d));
        else//画河界
            {
                painter.drawLine(QPoint(i*d,d),QPoint(i*d,5*d));
                painter.drawLine(QPoint(i*d,6*d),QPoint(i*d,10*d));
            }
    }
    //画九宫
    painter.drawLine(QPoint(4*d,8*d),QPoint(6*d,10*d));
    painter.drawLine(QPoint(6*d,8*d),QPoint(4*d,10*d));
    painter.drawLine(QPoint(4*d,d),QPoint(6*d,3*d));
    painter.drawLine(QPoint(6*d,d),QPoint(4*d,3*d));
    //画小十字
    for(int i=2;i<=8;i+=6)//第1到2个
    {
        painter.drawLine(QPoint((i*d)-3,(3*d)-3),QPoint((i*d)-8,(3*d)-3));
        painter.drawLine(QPoint((i*d)-3,(3*d)+3),QPoint((i*d)-8,(3*d)+3));
        painter.drawLine(QPoint((i*d)+3,(3*d)-3),QPoint((i*d)+8,(3*d)-3));
        painter.drawLine(QPoint((i*d)+3,(3*d)+3),QPoint((i*d)+8,(3*d)+3));
        painter.drawLine(QPoint((i*d)-3,(3*d)-3),QPoint((i*d)-3,(3*d)-8));
        painter.drawLine(QPoint((i*d)-3,(3*d)+3),QPoint((i*d)-3,(3*d)+8));
        painter.drawLine(QPoint((i*d)+3,(3*d)-3),QPoint((i*d)+3,(3*d)-8));
        painter.drawLine(QPoint((i*d)+3,(3*d)+3),QPoint((i*d)+3,(3*d)+8));
    }
    for(int i=3;i<=7;i+=2)//第3到5个
    {
        painter.drawLine(QPoint((i*d)-3,(4*d)-3),QPoint((i*d)-8,(4*d)-3));
        painter.drawLine(QPoint((i*d)-3,(4*d)+3),QPoint((i*d)-8,(4*d)+3));
        painter.drawLine(QPoint((i*d)+3,(4*d)-3),QPoint((i*d)+8,(4*d)-3));
        painter.drawLine(QPoint((i*d)+3,(4*d)+3),QPoint((i*d)+8,(4*d)+3));
        painter.drawLine(QPoint((i*d)-3,(4*d)-3),QPoint((i*d)-3,(4*d)-8));
        painter.drawLine(QPoint((i*d)-3,(4*d)+3),QPoint((i*d)-3,(4*d)+8));
        painter.drawLine(QPoint((i*d)+3,(4*d)-3),QPoint((i*d)+3,(4*d)-8));
        painter.drawLine(QPoint((i*d)+3,(4*d)+3),QPoint((i*d)+3,(4*d)+8));
    }
    for(int i=3;i<=7;i+=2)//第6到8个
    {
        painter.drawLine(QPoint((i*d)-3,(7*d)-3),QPoint((i*d)-8,(7*d)-3));
        painter.drawLine(QPoint((i*d)-3,(7*d)+3),QPoint((i*d)-8,(7*d)+3));
        painter.drawLine(QPoint((i*d)+3,(7*d)-3),QPoint((i*d)+8,(7*d)-3));
        painter.drawLine(QPoint((i*d)+3,(7*d)+3),QPoint((i*d)+8,(7*d)+3));
        painter.drawLine(QPoint((i*d)-3,(7*d)-3),QPoint((i*d)-3,(7*d)-8));
        painter.drawLine(QPoint((i*d)-3,(7*d)+3),QPoint((i*d)-3,(7*d)+8));
        painter.drawLine(QPoint((i*d)+3,(7*d)-3),QPoint((i*d)+3,(7*d)-8));
        painter.drawLine(QPoint((i*d)+3,(7*d)+3),QPoint((i*d)+3,(7*d)+8));
    }
    for(int i=2;i<=8;i+=6)//第9到10个
    {
        painter.drawLine(QPoint((i*d)-3,(8*d)-3),QPoint((i*d)-8,(8*d)-3));
        painter.drawLine(QPoint((i*d)-3,(8*d)+3),QPoint((i*d)-8,(8*d)+3));
        painter.drawLine(QPoint((i*d)+3,(8*d)-3),QPoint((i*d)+8,(8*d)-3));
        painter.drawLine(QPoint((i*d)+3,(8*d)+3),QPoint((i*d)+8,(8*d)+3));
        painter.drawLine(QPoint((i*d)-3,(8*d)-3),QPoint((i*d)-3,(8*d)-8));
        painter.drawLine(QPoint((i*d)-3,(8*d)+3),QPoint((i*d)-3,(8*d)+8));
        painter.drawLine(QPoint((i*d)+3,(8*d)-3),QPoint((i*d)+3,(8*d)-8));
        painter.drawLine(QPoint((i*d)+3,(8*d)+3),QPoint((i*d)+3,(8*d)+8));
    }
    //第11个
    painter.drawLine(QPoint((1*d)+3,(4*d)-3),QPoint((1*d)+8,(4*d)-3));
    painter.drawLine(QPoint((1*d)+3,(4*d)+3),QPoint((1*d)+8,(4*d)+3));
    painter.drawLine(QPoint((1*d)+3,(4*d)-3),QPoint((1*d)+3,(4*d)-8));
    painter.drawLine(QPoint((1*d)+3,(4*d)+3),QPoint((1*d)+3,(4*d)+8));
    //第12个
    painter.drawLine(QPoint((9*d)-3,(4*d)-3),QPoint((9*d)-8,(4*d)-3));
    painter.drawLine(QPoint((9*d)-3,(4*d)+3),QPoint((9*d)-8,(4*d)+3));
    painter.drawLine(QPoint((9*d)-3,(4*d)-3),QPoint((9*d)-3,(4*d)-8));
    painter.drawLine(QPoint((9*d)-3,(4*d)+3),QPoint((9*d)-3,(4*d)+8));
    //第13个
    painter.drawLine(QPoint((1*d)+3,(7*d)-3),QPoint((1*d)+8,(7*d)-3));
    painter.drawLine(QPoint((1*d)+3,(7*d)+3),QPoint((1*d)+8,(7*d)+3));
    painter.drawLine(QPoint((1*d)+3,(7*d)-3),QPoint((1*d)+3,(7*d)-8));
    painter.drawLine(QPoint((1*d)+3,(7*d)+3),QPoint((1*d)+3,(7*d)+8));
    //第14个
    painter.drawLine(QPoint((9*d)-3,(7*d)-3),QPoint((9*d)-8,(7*d)-3));
    painter.drawLine(QPoint((9*d)-3,(7*d)+3),QPoint((9*d)-8,(7*d)+3));
    painter.drawLine(QPoint((9*d)-3,(7*d)-3),QPoint((9*d)-3,(7*d)-8));
    painter.drawLine(QPoint((9*d)-3,(7*d)+3),QPoint((9*d)-3,(7*d)+8));
    //写楚河汉界
    painter.setFont(QFont("STLiti",17));
    QRect rect1=QRect(120,300,120,60);
    QRect rect2=QRect(360,300,120,60);
    painter.drawText(rect1,tr("楚河"),QTextOption(Qt::AlignCenter));
    painter.drawText(rect2,tr("漢界"),QTextOption(Qt::AlignCenter));
    //画轮廓线
    QPen pen;
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawLine(QPoint(d-10,d-10),QPoint(d-10,(10*d)+10));
    painter.drawLine(QPoint(d-10,d-10),QPoint((9*d)+10,d-10));
    painter.drawLine(QPoint((9*d)+10,d-10),QPoint((9*d)+10,(10*d)+10));
    painter.drawLine(QPoint(d-10,(10*d)+10),QPoint((9*d)+10,(10*d)+10));
    //画棋子
    for(int i=0;i<32;i++)
    {
        drawChessman(painter,i);
    }
    if(end==1)
    {
      if(_beRedTurn)
      QMessageBox::information(this,"游戏结束","黑方胜利");
      else
      QMessageBox::information(this,"游戏结束","红方胜利");
      end=-1;
    }
}

QPoint Board::centre(double row,double column)
 {
     QPoint temp;
     temp.rx()=(column+1)*2*_r;
     temp.ry()=(row+1)*2*_r;
     return temp;
 }
 QPoint Board::centre(int id)
 {
     return centre(c[id]._row,c[id]._column);
 }

 /*图片插入的核心*/
 void Board::drawChessman(QPainter& painter,int id)
 {
     if(c[id].dead_ornot)
         return;//棋子被吃就不画
//     QPoint temp=centre(id);
     if(c[id].red_ornot)  //绘制红方棋子
     {
         painter.drawImage(centre(c[id]._row-0.4,c[id]._column-0.4),
                           c[id].getText());
     }
     else  //绘制黑方棋子
     {
         painter.drawImage(centre(c[id]._row-0.4,c[id]._column-0.4),
                            c[id].getText());
     }
 }
void Board::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint point=event->pos();
    int row;
    int column;
    bool ret=getRowandColumn(point,row,column);
    if(ret==false) return;
    int i;
    int clickid=-1;
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
              if(c[clickid]._type==Chessman::Jiang)
              {
                  end=1;
              }
            }
            _chooseid=-1;
            _beRedTurn=!_beRedTurn;
            update();
            if(end==1)
            {
              if(_beRedTurn)
              QMessageBox::information(this,"游戏结束","黑方胜利");
              else
              QMessageBox::information(this,"游戏结束","红方胜利");
              end=-1;
            }
       }
   }
}
bool Board::getRowandColumn(QPoint point,int &row,int &column)
{
    for(row=0;row<=9;row++)
    {
        for(column=0;column<=8;column++)
        {
            QPoint c=centre(row,column);//棋盘上点的坐标
            int dx=c.x()-point.x();
            int dy=c.y()-point.y();
            int distance=dx*dx+dy*dy;
            if(distance<_r*_r)
            {
               return true;
            }
        }
    }
    return false;
}
int Board::onway(int row1, int column1, int row2, int column2)
{
    int ret = 0;
    if(row1 != row2 && column1 != column2) return -1;//不在一条直线上
    if(row1 == row2 && column1 == column2) return -1;//同一个棋子
    if(row1 == row2)//同一行
    {
      int begin = column1 < column2 ? column1 : column2;
      int end = column1 < column2 ? column2 : column1;
      for(int column = begin+1; column<end; column++)
      {
        if(getChessmanid(row1, column) != -1) ++ret;
      }
    }
    else//同一列
    {
      int begin = row1 < row2 ? row1 : row2;
      int end = row1 < row2 ? row2 : row1;
      for(int row = begin+1; row<end; ++row)
      {
        if(getChessmanid(row, column1) != -1)  ++ret;
      }
     }
    return ret;
}
int Board::getChessmanid(int row, int col)
{
    for(int i=0; i<32; ++i)
    {
      if(c[i]._row == row && c[i]._column == col && c[i].dead_ornot==false)
      return i;
    }
    return -1;
}
int Board::getrelation(int row1, int column1, int row2, int column2)
{
    return qAbs(row1-row2)*10+qAbs(column1-column2);
}
bool Board::BottomSide(int id)
{
    return _Side == c[id].red_ornot;
}
bool Board::canMoveChe(int moveid,int row,int column,int)
{
    int ret = onway(c[moveid]._row, c[moveid]._column,row,column);
    if(ret == 0)
    {
      return true;
    }
    return false;
}
bool Board::canMoveMa(int moveid,int row,int column,int)
{
    int r = getrelation(c[moveid]._row,c[moveid]._column,row,column);
    if(r != 12 && r != 21) return false;//不走“日”
    if(r == 12)//前后跳
    {
      if(getChessmanid(c[moveid]._row, (column+c[moveid]._column)/2) != -1)  return false;
    }
    else//左右跳
    {
      if(getChessmanid((row+c[moveid]._row)/2, column) != -1) return false;
    }
    return true;
}
bool Board::canMoveBing(int moveid,int row,int column,int)
{
    int r = getrelation(c[moveid]._row,c[moveid]._column,row,column);
    if(r != 1 && r != 10) return false;//没走1格
    if(BottomSide(moveid))//没过河
    {
      if(row > c[moveid]._row) return false;
      if(c[moveid]._row >= 5 && row == c[moveid]._row) return false;
    }
    else//过河了
    {
      if(row < c[moveid]._row) return false;
      if(c[moveid]._row <= 4 && row == c[moveid]._row) return false;
    }
    return true;
}
bool Board::canMoveJiang(int moveid,int row,int column,int killid)
{ 
    if(killid != -1 && c[killid]._type == Chessman::Jiang)//将对将的情况
    {
      int ret = onway(c[moveid]._row, c[moveid]._column,c[killid]._row, c[killid]._column);
      if(ret == 0)
      {
        return true;
      }
      return false;
    }
    int r = getrelation(c[moveid]._row, c[moveid]._column, row, column);
    if(r != 1 && r != 10) return false;//没走一格
    //没在九宫里移动
    if(column < 3 || column > 5) return false;
    if(BottomSide(moveid))
    {
      if(row < 7) return false;
    }
    else
    {
      if(row > 2) return false;
    }
    return true;    
}
bool Board::canMoveShi(int moveid,int row,int column,int)
{
    int r = getrelation(c[moveid]._row, c[moveid]._column, row, column);
    if(r != 11) return false;
    //没在九宫里移动
    if(column < 3 || column > 5) return false;
    if(BottomSide(moveid))
    {
      if(row < 7) return false;
    }
    else
    {
      if(row > 2) return false;
    }
    return true;
}
bool Board::canMoveXiang(int moveid,int row,int column,int)
{
    int r = getrelation(c[moveid]._row, c[moveid]._column, row, column);
    if(r != 22) return false;
    if(getChessmanid((row+c[moveid]._row)/2, (column+c[moveid]._column)/2) != -1)//象眼有没有棋子
    return false;
    if(BottomSide(moveid))
    {
       if(row < 4) return false;
    }
    else
    {
       if(row > 5) return false;
    }
    return true;
}
bool Board::canMovePao(int moveid, int row, int column, int killid)
{
    int ret = onway(row, column, c[moveid]._row, c[moveid]._column);
    if(killid != -1)//吃子
    {
       if(ret == 1) return true;
    }
    else
    {
       if(ret == 0) return true;
    }
    return false;
}

bool Board::canmove(int moveid,int row,int column,int killid)
{
    if(killid == -1)
    {
       goto next;
    }
    if(c[moveid].red_ornot==c[killid].red_ornot)//想要吃的棋子和选中的棋子一个颜色
    {
       _chooseid=killid;//更改棋子的选中
       update();
       return false;
    }
    next:switch (c[_chooseid]._type)
    {
       case Chessman::Che:
          return canMoveChe(moveid,row,column,killid);
       case Chessman::Ma:
          return canMoveMa(moveid,row,column,killid);
       case Chessman::Pao:
          return canMovePao(moveid,row,column,killid);
       case Chessman::Bing:
          return canMoveBing(moveid,row,column,killid);
       case Chessman::Jiang:
          return canMoveJiang(moveid,row,column,killid);
       case Chessman::Shi:
          return canMoveShi(moveid,row,column,killid);
       case Chessman::Xiang:
          return canMoveXiang(moveid,row,column,killid);
    }
    return false;
}


bool Board::canMoveAI(int moveid,int row,int column,int killid)
{
    if(killid == -1)
    {
       goto next;
    }
    if(c[moveid].red_ornot==c[killid].red_ornot)//想要吃的棋子和选中的棋子一个颜色
    {
       moveid=killid;//更改棋子的选中
       update();
       return false;
    }
    next:switch (c[moveid]._type)
    {
       case Chessman::Che:
          return canMoveChe(moveid,row,column,killid);
       case Chessman::Ma:
          return canMoveMa(moveid,row,column,killid);
       case Chessman::Pao:
          return canMovePao(moveid,row,column,killid);
       case Chessman::Bing:
          return canMoveBing(moveid,row,column,killid);
       case Chessman::Jiang:
          return canMoveJiang(moveid,row,column,killid);
       case Chessman::Shi:
          return canMoveShi(moveid,row,column,killid);
       case Chessman::Xiang:
          return canMoveXiang(moveid,row,column,killid);
    }
    return false;
}

//悔棋核心
void Board::saveStep(int moveId, int killId, int row, int col)
{
    Step* pStep = new Step;
    pStep->_moveId = moveId;
    pStep->_killId = killId;
    pStep->_rowPre = c[moveId]._row;
    pStep->_colPre = c[moveId]._column;
    pStep->_rowNow = row;
    pStep->_colNow = col;
    pStep->_redTurnPre = c[moveId].red_ornot;
    _steps.append(*pStep);
}
void Board::backStep()
{
    if(this->_steps.size() == 0)
    {
        return;
    }

    QVector<Step>::iterator it;
    it = _steps.end();
    --it;
    if((*it)._killId==-1)
    {
        c[(*it)._moveId]._row       =(*it)._rowPre;
        c[(*it)._moveId]._column   =(*it)._colPre;
        _beRedTurn  = (*it)._redTurnPre;
    }
    else
    {
        c[(*it)._moveId]._row=(*it)._rowPre;
        c[(*it)._moveId]._column=(*it)._colPre;
        c[(*it)._killId].dead_ornot=false;
        c[(*it)._killId]._row=(*it)._rowNow;
        c[(*it)._killId]._column=(*it)._colPre;
        _beRedTurn=(*it)._redTurnPre;
    }
    update();
    _steps.removeLast();
    end = 0;
}
void Board::slotBack()
{
    backStep();
}


