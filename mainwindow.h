#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPixmap>
#include<QMessageBox>
#include<QDebug>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QStandardItemModel>
#include "result.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendData(QString,QStandardItemModel*);
private slots:
    void on_SearchBtn_clicked();
    void requestFinished(QNetworkReply*);

private:
    Ui::MainWindow *ui;
    Result *result = new Result();
    QString url = "https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&tn=baidu&wd=";
};
#endif // MAINWINDOW_H
