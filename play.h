#ifndef PLAY_H
#define PLAY_H

#include <QWidget>

namespace Ui {
class Play;
}

class Play : public QWidget
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = nullptr);
    ~Play();

signals:
    void togToplaylist();

public slots:
    void toPlay(QString);

private slots:
    void on_toSearch_clicked();

    void on_toPlaylist_clicked();

private:
    Ui::Play *ui;
};

#endif // PLAY_H
