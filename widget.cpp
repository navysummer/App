#include "widget.h"
#include "ui_widget.h"

#include<QDebug>
#include <curl/curl.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_searchBtn_clicked()
{
    QString keyword = ui->KeyWord->text();
    QString url = "https://www.baidu.com/s?ie=UTF-8&wd=";
    url.append(keyword);
//    qDebug()<<url<<endl;
    QNetworkAccessManager *manage = new QNetworkAccessManager(this);
//    connect(manage,SIGNAL(finished(QNetworkReply*)),this,SLOT(requestFinished(QNetworkReply*)));
//    manage->get(QNetworkRequest(QUrl(url)));
QEventLoop eventLoop;
QNetworkReply *reply =  manage->get(QNetworkRequest(QUrl(url)));
connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
eventLoop.exec();
QString  str  = reply->readAll();
QString  str1  = str.replace("\r","").replace("\n","").replace("\t","");
qWarning()<<str1<<endl;
//ui->LOGO->show();
qWarning()<<str<<endl;
QLabel *label=new QLabel(str1);

label->show();
//ui->LOGO->setText(str);


}
void Widget::requestFinished(QNetworkReply* reply)
 {
   QString a = "qwer";
    QByteArray responseByte  = reply->readAll();
    ui->LOGO->setText(responseByte);

}

