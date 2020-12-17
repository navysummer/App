#include "play.h"
#include "ui_play.h"
#include<QDebug>

Play::Play(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Play)
{
    ui->setupUi(this);
}

Play::~Play()
{
    delete ui;
}

void Play::toPlay(QString video_url){
    this->show();
    qWarning() << video_url<<endl;
}

