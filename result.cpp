#include "result.h"
#include "ui_result.h"
#include<QDebug>

Result::Result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
}

Result::~Result()
{
    delete ui;
}
void Result::inforeceive(QString name){
    ui->videoName->setText(name);
    this->show();
}
