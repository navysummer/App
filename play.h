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

public slots:
    void toPlay(QString);

private:
    Ui::Play *ui;
};

#endif // PLAY_H
