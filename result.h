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
    void toPlay(QString);

public slots:
    void inforeceive(QString,QStandardItemModel*);
    void onTableClicked(const QModelIndex &);
    void onPlayClicked();

private:
    Ui::Result *ui;
    QString video_url;
};

#endif // RESULT_H