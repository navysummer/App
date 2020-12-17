#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include<QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
     void infoSend(QString,QStandardItemModel*);

private slots:
    void on_searchBtn_clicked();
    void requestFinished(QNetworkReply* reply);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
