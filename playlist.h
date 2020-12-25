#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include<QStandardItemModel>
#include<QDebug>
#include<QUrl>
#include<QMessageBox>
#include "play.h"

namespace Ui {
class PlayList;
}

class PlayList : public QWidget
{
    Q_OBJECT

public:
    explicit PlayList(QWidget *parent = nullptr);
    ~PlayList();

signals:
    void toPlay(QString);

private slots:
    void receiveVideos(QString,QStandardItemModel*);

    void on_tableView_clicked(const QModelIndex &index);

    void on_toPlay_clicked();

private:
    Ui::PlayList *ui;
    Play *play = new Play();
    QString episode;
    QString video_url;
};

#endif // PLAYLIST_H
