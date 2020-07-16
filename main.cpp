#include <QApplication>
#include"Choosemenu.h"
#include"Mainwindow.h"
#include "dialog.h"
int main(int argc,char*argv[])
{
    QApplication app(argc,argv);

    Dialog start;

    start.show();

    return app.exec();
}
