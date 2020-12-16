#include "widget.h"
#include "result.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    Result *result = new Result();
    connect(this,SIGNAL(infoSend(QString)),result,SLOT(inforeceive(QString)));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_searchBtn_clicked()
{
    //    qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
    //    qDebug()<<url<<endl;
    QString keyword = ui->KeyWord->text();
    QString url = "https://www.baidu.com/s?ie=utf-8&wd=";
    url.append(keyword);
    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
    QMetaObject::Connection connRet = QObject::connect(naManager,
                                                       SIGNAL(finished(QNetworkReply*)),
                                                       this, SLOT(requestFinished(QNetworkReply*)));

    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36");
    request.setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");
    request.setRawHeader("Host","www.baidu.com");
    request.setRawHeader("Connection","keep-alive");
    request.setRawHeader("Upgrade-Insecure-Requests","1");
    QSslConfiguration config;
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::TlsV1_2);
    request.setSslConfiguration(config);
    request.setUrl(QUrl(url));
    QNetworkReply *reply = naManager->get(request);
    reply->ignoreSslErrors();

}
void Widget::requestFinished(QNetworkReply* reply)
{
      qDebug() << QString(reply->readAll());
      this->hide();
       QString keyword = ui->KeyWord->text();
       emit infoSend(keyword);

}

