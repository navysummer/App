#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>

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

public slots:
    void toPlaylist(QString,QString);
    void onTableClicked(const QModelIndex &index);
    void tagToshow();

private slots:
    void on_playBtn_clicked();

private:
    Ui::PlayList *ui;
    QString video_url;
};

#endif // PLAYLIST_H
