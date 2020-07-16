#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"Board.h"
#include<QWidget>
class Mainwindow:public QWidget
{
    Q_OBJECT
public:
    explicit Mainwindow(int gametype,QWidget *parent=0);
    ~Mainwindow();
    int _gametype;
signals:
public slots:
};

#endif // MAINWINDOW_H
