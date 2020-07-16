#include "dialog.h"
#include "ui_dialog.h"
#include "about.h"
#include "ui_about.h"
#include"Choosemenu.h"
#include"Mainwindow.h"
#include <QApplication>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    Choosemenu menu;
    if(menu.exec()!=QDialog::Accepted)
        menu._selected= 0;

    Mainwindow *window;
    window = new Mainwindow(menu._selected);
    window->resize(800,800);
    window->show();



}

void Dialog::on_pushButton_2_clicked()
{
    about *inform;
    inform = new about;
    inform->show();
}

void Dialog::on_pushButton_3_clicked()
{
    QApplication* app;

        app->quit();
}
