#ifndef CHOOSEMENU_H
#define CHOOSEMENU_H

#include<QDialog>
#include<QPushButton>
#include <QSound>
class Choosemenu:public QDialog
{
    Q_OBJECT
public:
    explicit Choosemenu(QWidget *parent=0);
    ~Choosemenu();
    QPushButton*_buttons[2];
    int _selected;
signals:
public slots:
    void slotClicked();
};

#endif // CHOOSEMENU_H
