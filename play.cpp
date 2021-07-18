#include "play.h"
#include "ui_play.h"

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

void Play::playVideo(QString video_url){
    this->show();

}

void Play::resizeEvent(QResizeEvent *)
{
}
