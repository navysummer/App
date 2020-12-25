#include "play.h"
#include "ui_play.h"

Play::Play(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Play)
{
    ui->setupUi(this);
    view = new QWebEngineView(this);
    view->load(QUrl("http://www.baidu.com/"));
    view->show();

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
    view->resize(this->size());
}
