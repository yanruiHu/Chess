#ifndef BOARD_H
#define BOARD_H
#include <QVector>
#include <QFrame>
#include <QDebug>
#include <QSound>
#include"Chessman.h"
class Board : public QFrame
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);
    Chessman c[32];//32颗棋子
    int _r;//棋子的半径,格子一半的长度--用来辅助表示坐标
    int _chooseid;//被选中的棋子id
    bool _beRedTurn;//是否轮到红色方走棋
    bool _Side;//选执方
    int end;
    void paintEvent(QPaintEvent *) ;//画棋盘
    void drawChessman(QPainter& painter,int id);//画棋子
    void init(bool bRedSide);
    void mouseReleaseEvent(QMouseEvent *) ;
    QPoint centre(double row,double column);//返回棋子中心点对应的棋盘坐标
    QPoint centre(int id);//函数重载，让调用更加简单
    bool getRowandColumn(QPoint point,int &row,int &column);//判断鼠标是否点到棋盘外并转化为棋盘坐标
    //移动规则
    //传入四个参数为：所选棋子的id，想要移动的位置的行、列坐标，吃子的id（如果不吃子就不传）
    bool canmove(int moveid,int row,int column,int killid);
    bool canMoveAI(int moveid,int row,int column,int killid);
    bool canMoveChe(int moveid,int row,int column,int killid);//车的行动规则
    bool canMoveMa(int moveid,int row,int column,int killid);//马的行动规则
    bool canMovePao(int moveid,int row,int column,int killid);//炮的行动规则
    bool canMoveBing(int moveid,int row,int column,int killid);//兵的行动规则
    bool canMoveJiang(int moveid,int row,int column,int killid);//将的行动规则
    bool canMoveShi(int moveid,int row,int column,int killid);//士的行动规则
    bool canMoveXiang(int moveid,int row,int column,int killid);//象的行动规则
    //帮助函数
    int getChessmanid(int row, int column); //得到棋子id
    int onway(int row1, int column1, int row2, int column2);//得到移动路线上棋子个数
    int getrelation(int row1, int column1, int row2, int column2);//10（横坐标差的绝对值）+纵坐标之差的绝对值
    bool BottomSide(int id);//辅助判断过没过河
class Step
    {
    public:
        Step(){}
        int _moveId;
        int _killId;
        int _rowPre;
        int _colPre;
        int _rowNow;
        int _colNow;
        bool _redTurnPre;
    };
    QVector<Step> _steps;
    void saveStep(int moveId, int killId, int row, int col);
    void backStep();
signals:
public slots:
    void slotBack();
};
#endif // BOARD_H
