#include "cerror.h"
#include "ui_cerror.h"
#include<QSound>

CError::CError(QWidget*parent):
    QDialog(parent),
    ui(new Ui::CError)
{
    ui->setupUi(this);
}

CError::~CError()
{
    delete ui;
}

void CError::on_pushButton_clicked()
{
    QSound::play("C:/soundeffcet/19.wav");
    done(Accepted);
}
