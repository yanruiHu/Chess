#ifndef BACKSTEP_H
#define BACKSTEP_H

#include<QWidget>
#include<QPushButton>
class Backstep:public QWidget
{
    Q_OBJECT
public:
    explicit Backstep(QWidget*parent=0);
    ~Backstep();
    QPushButton*_backstep;
signals:
    void sigBack();
public slots:
};

#endif // BACKSTEP_H
