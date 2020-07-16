#ifndef ONEPERSON_H
#define ONEPERSON_H

#include"Board.h"
class Oneperson:public Board
{
    Q_OBJECT;
public:
    explicit Oneperson(QWidget *parent=0);
    ~Oneperson();
    void mouseReleaseEvent(QMouseEvent *);
    /*前一个是我方棋子的id,后一个是对方棋子的id,点亮这两个棋子作为提示,如果没有可吃的子,这两个数字设定为-1,可以用作检测器*/
    int aimove[2];
    void ai();/*调用这个函数,然后再在aimove这个数组里取结果*/
signals:
public slots:

};

#endif // ONEPERSON_H
