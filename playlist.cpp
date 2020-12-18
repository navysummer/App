#include "playlist.h"
#include "ui_playlist.h"
#include "play.h"
#include <QUrl>
#include<QDebug>
#include<QMessageBox>
#include<QStandardItemModel>
#include <QDesktopServices>
#include <QUrl>

PlayList::PlayList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayList)
{
    ui->setupUi(this);
    Play *play = new Play();
    connect(this, SIGNAL(toPlay(QString)), play, SLOT(toPlay(QString)));
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
    connect(this, SIGNAL(toPlay(QString)), play, SLOT(toPlay(QString)));

}

PlayList::~PlayList()
{
    delete ui;
}

void PlayList::onTableClicked(const QModelIndex &index){
    if (index.isValid()) {
        QAbstractItemModel  *Imodel=ui->tableView->model();
        const int row = index.row();
//        QString name = Imodel->data(Imodel->index(row,0)).toString();
        QString video_url = Imodel->data(Imodel->index(row,1)).toString();
        this->video_url = video_url;

    }
}

void PlayList::toPlaylist(QString name,QString video_url){
    ui->videoName->setText(name);
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,QString("剧集"));
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
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->show();
}

void PlayList::on_playBtn_clicked()
{
    const bool check = QUrl(this->video_url).isValid();
    qWarning() << check<<endl;
    if(check){
//        this->hide();
//        emit toPlay(this->video_url);
        QDesktopServices::openUrl(QUrl(this->video_url));

    }else{
        QMessageBox box(QMessageBox::Warning,"警告","未选中剧集或者剧集地址无效");
        box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.setButtonText (QMessageBox::Cancel,QString("取 消"));
        box.exec ();
    }

}

void PlayList::tagToshow(){
    this->show();
}
