#include "playlist.h"
#include "ui_playlist.h"

PlayList::PlayList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayList)
{
    ui->setupUi(this);
    connect(this,
            SIGNAL(toPlay(QString)),
            play,
            SLOT(playVideo(QString)));
}

PlayList::~PlayList()
{
    delete ui;
}

void PlayList::receiveVideos(QString name,QStandardItemModel* model){
    ui->vidoeName->setText(name);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->show();
}

void PlayList::on_tableView_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
            QAbstractItemModel  *model=ui->tableView->model();
            const int row = index.row();
            QString episode = model->data(model->index(row,0)).toString();
            QString video_url = model->data(model->index(row,1)).toString();
            ui->Episode->setText(episode);
            this->episode = episode;
            this->video_url = video_url;
        }
}

void PlayList::on_toPlay_clicked()
{
    const bool check = QUrl(this->video_url).isValid();
    if(check){
        this->hide();
//        qWarning()<<this->video_url<<endl;
        emit toPlay(this->video_url);
    }else{
        QMessageBox box(QMessageBox::Warning,"Warning","no selected or invalid url");
        box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
        box.setButtonText (QMessageBox::Ok,QString("Ok"));
        box.setButtonText (QMessageBox::Cancel,QString("Cancel"));
        box.exec ();
    }
}
