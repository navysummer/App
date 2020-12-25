#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <QStandardItemModel>
#include<QMessageBox>
#include<QUrl>
#include<QDebug>
#include "playlist.h"

namespace Ui {
class Result;
}

class Result : public QWidget
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();

signals:
    void sendVideos(QString,QStandardItemModel*);

private slots:
    void receiveData(QString,QStandardItemModel*);
    void onTableClicked(const QModelIndex &);
    void on_getVideos_clicked();

private:
    Ui::Result *ui;
    QString name;
    QString video_url;
    PlayList *playlist = new PlayList();
};

#endif // RESULT_H
