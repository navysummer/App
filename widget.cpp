#include "widget.h"
#include "ui_widget.h"

#include<QDebug>

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
    qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
//    qDebug()<<url<<endl;
    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
    QMetaObject::Connection connRet = QObject::connect(naManager,
                                                       SIGNAL(finished(QNetworkReply*)),
                                                       this, SLOT(requestFinished(QNetworkReply*)));
    Q_ASSERT(connRet);

    request.setUrl(QUrl(url));
    naManager->get(request);
//    qDebug()<<reply->readAll()<<endl;

}
void Widget::requestFinished(QNetworkReply* reply)
 {
    while(true){
        if(reply->isFinished()){
            qDebug() << reply->readAll();
            break;
        }
    }


}

