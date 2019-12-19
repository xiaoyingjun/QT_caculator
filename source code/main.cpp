#include"calculator.h"
#include "ui_calculator.h"
#include <QApplication>
#include<qpushbutton.h>
#include<sstream>
#include<qstring.h>
#include <QtGui>
#include <QTextCodec>
#include <ActiveQt/QAxWidget>
#include <QTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    Ui::Calculator ui;
    ui.setupUi(&w);
    //w.setStyle(QStyleFactory::create("fusion"));
    w.show();
    return a.exec();

}
