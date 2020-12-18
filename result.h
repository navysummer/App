#ifndef RESULT_H
#define RESULT_H
#include<QStandardItemModel>
#include <QWidget>

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
    void toPlaylist(QString,QString);

public slots:
    void inforeceive(QString,QStandardItemModel*);
    void onTableClicked(const QModelIndex &);
    void onPlaylistClicked();

private:
    Ui::Result *ui;
    QString name;
    QString video_url;
};

#endif // RESULT_H
