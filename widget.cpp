#include "widget.h"
#include "result.h"
#include "ui_widget.h"
#include<QDebug>
#include<QMessageBox>
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
//    ui->LOGO->setStyleSheet("background-image: url(C:/Users/NAVY/Desktop/work/GUI/App/favicon.ico);");
    QImage img;
    img.load("C:/Users/NAVY/Desktop/work/GUI/App/logo.jpg");
    ui->LOGO->setPixmap(QPixmap::fromImage(img));
    Result *result = new Result();
    connect(this,SIGNAL(infoSend(QString,QStandardItemModel*)),result,SLOT(inforeceive(QString,QStandardItemModel*)));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_searchBtn_clicked()
{
    QString keyword = ui->KeyWord->text();
    if(keyword.isEmpty()){
         QMessageBox box(QMessageBox::Warning,"警告","输入关键词不允许为空");
         box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
         box.setButtonText (QMessageBox::Ok,QString("确 定"));
         box.setButtonText (QMessageBox::Cancel,QString("取 消"));
         box.exec ();
         return ;
    }
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
    request.setRawHeader("Accept-Encoding","deflate");
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
    int httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qWarning() << httpStatus<<endl;
    qWarning() << reply->readAll();
    this->destroy();
    QString keyword = ui->KeyWord->text();
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,QString("剧名"));
    model->setHeaderData(1,Qt::Horizontal,QString("url"));
    for(int i = 0; i < 20; i++)
    {
        model->setItem(i,0,new QStandardItem("2009441676"));
        //设置字符颜色
        model->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
        //设置字符位置
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem("https://www.baidu.com"));
    }
    emit infoSend(keyword,model);

}


