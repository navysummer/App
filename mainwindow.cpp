#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QXmlStreamReader>
#include <QDomDocument>
#include <QXmlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage img;
    img.load(":/static/logo.png");
    ui->LOGO->setPixmap(QPixmap::fromImage(img));
    connect(this,
            SIGNAL(sendData(QString,QStandardItemModel*)),
            result,
            SLOT(receiveData(QString,QStandardItemModel*)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SearchBtn_clicked()
{
    QString keyword = ui->KeyWord->text();
    if(keyword.isEmpty()){
        QMessageBox box(QMessageBox::Warning,"Warning","keyword is empty");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("OK"));
        box.exec ();
    }else{
        url.append(keyword);
        qWarning() << "url="<<url<<endl;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        connect(naManager,
                SIGNAL(finished(QNetworkReply*)),
                this,
                SLOT(requestFinished(QNetworkReply*)));
        QNetworkRequest request;
        request.setRawHeader("User-Agent",
                             "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                             "AppleWebKit/537.36 (KHTML, like Gecko) "
                             "Chrome/87.0.4280.88 Safari/537.36");
        request.setUrl(QUrl(url));
        naManager->get(request);

    }
}

void MainWindow::requestFinished(QNetworkReply* reply){
    int httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qWarning() << "status="<< httpStatus<<endl;
    if(httpStatus==200){
        QXmlQuery query(QXmlQuery::XPath20);
        QString res = reply->readAll();
        query.setFocus(res);
        query.setQuery("div[@class='yl-vd-basis_3H7DH']");
        if(query.isValid()){
            QString sOptionSettings;
            query.evaluateTo(&sOptionSettings);
            qWarning() << sOptionSettings<<endl;
        }else{
            qWarning() << "query is not valid"<<endl;
        }
    }
    this->hide();
    QString keyword = ui->KeyWord->text();
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,QString("video name"));
    model->setHeaderData(1,Qt::Horizontal,QString("url"));
    for(int i = 0; i < 20; i++){
        model->setItem(i,0,new QStandardItem("2009441676"));
        //设置字符颜色
        model->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
        //设置字符位置
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem("https://www.baidu.com"));
    }
    emit this->sendData(keyword,model);

}
