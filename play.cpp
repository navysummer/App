#include "play.h"
#include "ui_play.h"
#include "widget.h"
#include "playlist.h"
#include <QDesktopServices>
#include <QUrl>
#include<QDebug>

Play::Play(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Play)
{
    ui->setupUi(this);
//    PlayList *playlist = new PlayList();
//    connect(this,SIGNAL(togToplaylist),playlist,SLOT(tagToshow));

}

Play::~Play()
{
    delete ui;
}

void Play::toPlay(QString video_url){
    this->show();
//    qWarning() << video_url<<endl;
    QDesktopServices::openUrl(QUrl(video_url));
}


void Play::on_toSearch_clicked()
{
    this->hide();
    Widget *widget = new Widget();
    widget->show();
}


void Play::on_toPlaylist_clicked()
{
    this->hide();
//    emit togToplaylist();
    PlayList *playlist = new PlayList();
    playlist->show();

}
