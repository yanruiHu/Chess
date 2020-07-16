#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <QString>
#include <QImage>

class Chessman
{
public:
    Chessman();
    ~Chessman(){};
    enum Type{Jiang,Shi,Xiang,Che,Ma,Pao,Bing};
    double _row;
    double _column;
    int _id;
    bool dead_ornot;//棋子状态
    bool red_ornot;//红方或黑方
    Type _type;
    QImage getText();
    void init(int id);//初始化棋子函数
    void rotate();//旋转棋盘
    QImage black_che_image;
    QImage black_ma_image;
    QImage black_xiang_image;
    QImage black_shi_image;
    QImage black_jiang_image;
    QImage black_pao_image;
    QImage black_bing_image;

    QImage red_che_image;
    QImage red_ma_image;
    QImage red_xiang_image;
    QImage red_shi_image;
    QImage red_jiang_image;
    QImage red_pao_image;
    QImage red_bing_image;
};

#endif // CHESSMAN_H
