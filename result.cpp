#include "result.h"
#include "ui_result.h"
#include "play.h"
#include<QStandardItemModel>
#include<QDebug>

Result::Result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    Play *play = new Play();
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
    connect(ui->play, SIGNAL(clicked()), this, SLOT(onPlayClicked()));
    connect(this, SIGNAL(toPlay(QString)), play, SLOT(toPlay(QString)));

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
        QModelIndex Iindex = Imodel->index(index.row(),1);
        QVariant Urltemp=Imodel->data(Iindex);
         this->video_url=Imodel->data(index).toString();
    }
}

void Result::onPlayClicked(){
    this->hide();
    emit toPlay(this->video_url);
}
