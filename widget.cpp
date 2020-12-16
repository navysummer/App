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
    QString keyword = ui->KeyWord->text();
    QString url = "https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&tn=baidu&wd=";
    url.append(keyword);
//    qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
//    qDebug()<<url<<endl;
    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
    QMetaObject::Connection connRet = QObject::connect(naManager,
                                                       SIGNAL(finished(QNetworkReply*)),
                                                       this, SLOT(requestFinished(QNetworkReply*)));
//    Q_ASSERT(connRet);

//    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36");
//    request.setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");
//    request.setRawHeader("Host","www.baidu.com");
//    request.setRawHeader("Connection","keep-alive");
//    request.setRawHeader("Upgrade-Insecure-Requests","1");
//    request.setRawHeader("","");
//    request.setRawHeader("","");
//    QSslConfiguration config;
//    config.setPeerVerifyMode(QSslSocket::VerifyNone);
//    config.setProtocol(QSsl::SslV3);
//    request.setSslConfiguration(config);
    request.setUrl(QUrl(url));
    naManager->get(request);

}
void Widget::requestFinished(QNetworkReply* reply)
{
      qDebug() << QString(reply->readAll()).replace("\n","").replace("\t","");
      this->hide();
       QString keyword = ui->KeyWord->text();
       emit infoSend(keyword);

}

