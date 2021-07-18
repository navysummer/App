#ifndef PLAY_H
#define PLAY_H

#include <QWidget>
#include<QDebug>
#include<QMediaPlaylist>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QFileDialog>
#include<QHBoxLayout>
namespace Ui {
class Play;
}

class Play : public QWidget
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = nullptr);
    ~Play();


protected:
    void resizeEvent(QResizeEvent *);

private slots:
    void playVideo(QString video_url);

private:
    Ui::Play *ui;
    QString video_url;
};

#endif // PLAY_H
