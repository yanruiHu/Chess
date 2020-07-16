#include "Chessman.h"

Chessman::Chessman()
{
    black_che_image.load(":/new/prefix1/BR.GIF");
    black_ma_image.load(":/new/prefix1/BN.GIF");
    black_xiang_image.load(":/new/prefix1/BB.GIF");
    black_shi_image.load(":/new/prefix1/BA.GIF");
    black_jiang_image.load(":/new/prefix1/BK.GIF");
    black_pao_image.load(":/new/prefix1/BC.GIF");
    black_bing_image.load(":/new/prefix1/BP.GIF");

    red_che_image.load(":/new/prefix1/RR.GIF");
    red_ma_image.load(":/new/prefix1/RN.GIF");
    red_xiang_image.load(":/new/prefix1/RB.GIF");
    red_shi_image.load(":/new/prefix1/RA.GIF");
    red_jiang_image.load(":/new/prefix1/RK.GIF");
    red_pao_image.load(":/new/prefix1/RC.GIF");
    red_bing_image.load(":/new/prefix1/RP.GIF");
}
QImage Chessman::getText()
{
    switch(this->_type)
    {
    case Che:
     if(_id<16)  return red_che_image;
     else        return black_che_image;
    case Ma:
     if(_id<16)  return red_ma_image;
     else        return black_ma_image;
    case Pao:
     if(_id<16)  return red_pao_image;
     else        return black_pao_image;
    case Bing:
     if(_id<16)  return red_bing_image;
     else        return black_bing_image;
    case Jiang:
     if(_id<16)  return red_jiang_image;
     else        return black_jiang_image;
    case Shi:
     if(_id<16)  return red_shi_image;
     else        return black_shi_image;
    case Xiang:
     if(_id<16)  return red_xiang_image;
     else        return black_xiang_image;
 }
 return black_che_image;
}

void Chessman::init(int id)
{
    _id=id;
    dead_ornot=false;
    if(id<16)
    {
        red_ornot=true;
    }
    else
        red_ornot=false;
    struct
    {
        int row;
        int column;
        Chessman::Type type;
    }position[16]={
                 {0,0,Chessman::Che},
                 {0,1,Chessman::Ma},
                 {0,2,Chessman::Xiang},
                 {0,3,Chessman::Shi},
                 {0,4,Chessman::Jiang},
                 {0,5,Chessman::Shi},
                 {0,6,Chessman::Xiang},
                 {0,7,Chessman::Ma},
                 {0,8,Chessman::Che},
                 {2,1,Chessman::Pao},
                 {2,7,Chessman::Pao},
                 {3,0,Chessman::Bing},
                 {3,2,Chessman::Bing},
                 {3,4,Chessman::Bing},
                 {3,6,Chessman::Bing},
                 {3,8,Chessman::Bing},
             };
   if(id<16)
   {
       _row=position[id].row;
       _column=position[id].column;
       _type=position[id].type;
   }
   else//对称的两个棋子，行相加等于9，列相加等于8
   {
       _row=9-position[id-16].row;
       _column=8-position[id-16].column;
       _type=position[id-16].type;
   }
}
void Chessman::rotate()
{
   _column = 8-_column;
   _row = 9-_row;
}

