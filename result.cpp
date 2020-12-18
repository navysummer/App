#include "result.h"
#include "ui_result.h"
//#include "play.h"
#include "playlist.h"
#include<QStandardItemModel>
#include<QUrl>
#include<QMessageBox>
#include<QDebug>

Result::Result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    PlayList *playlist = new PlayList();
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
    connect(ui->play, SIGNAL(clicked()), this, SLOT(onPlaylistClicked()));
    connect(this, SIGNAL(toPlaylist(QString,QString)), playlist, SLOT(toPlaylist(QString,QString)));

}

Result::~Result()
{
    delete ui;
}
void Result::inforeceive(QString name,QStandardItemModel *model){
    ui->videoName->setText(name);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->show();
}

void Result::onTableClicked(const QModelIndex &index){
    if (index.isValid()) {
        QAbstractItemModel  *Imodel=ui->tableView->model();
        const int row = index.row();
        QString name = Imodel->data(Imodel->index(row,0)).toString();
        QString video_url = Imodel->data(Imodel->index(row,1)).toString();
        this->name = name;
        this->video_url = video_url;
    }
}

void Result::onPlaylistClicked(){

    const bool check = QUrl(this->video_url).isValid();
    qWarning() << check<<endl;
    if(check){
        this->hide();
        emit toPlaylist(this->name, this->video_url);
    }else{
        QMessageBox box(QMessageBox::Warning,"警告","未选中剧集或者剧集地址无效");
        box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.setButtonText (QMessageBox::Cancel,QString("取 消"));
        box.exec ();
    }
//
}
