#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    connect(ui->tableView,
            SIGNAL(clicked(const QModelIndex &)),
            this,
            SLOT(onTableClicked(const QModelIndex &)));
    connect(this,
            SIGNAL(sendVideos(QString,QStandardItemModel*)),
            playlist,
            SLOT(receiveVideos(QString,QStandardItemModel*)));
}

Result::~Result()
{
    delete ui;
}

void Result::receiveData(QString name,QStandardItemModel *model){
    ui->KeyWord->setText(name);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->show();
}


void Result::onTableClicked(const QModelIndex &index){
    if (index.isValid()) {
            QAbstractItemModel  *model=ui->tableView->model();
            const int row = index.row();
            QString name = model->data(model->index(row,0)).toString();
            QString video_url = model->data(model->index(row,1)).toString();
            ui->videoName->setText(name);
            this->name = name;
            this->video_url = video_url;
        }
}

void Result::on_getVideos_clicked()
{
    const bool check = QUrl(this->video_url).isValid();
//    qWarning() << check<<endl;
    if(check){
        QStandardItemModel *model = new QStandardItemModel();
        model->setColumnCount(2);
        model->setHeaderData(0,Qt::Horizontal,QString("series"));
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
         emit sendVideos(this->name, model);
         this->hide();
    }else{
        QMessageBox box(QMessageBox::Warning,"Warning","no selected or invalid url");
        box.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
        box.setButtonText (QMessageBox::Ok,QString("ok"));
        box.setButtonText (QMessageBox::Cancel,QString("cancel"));
        box.exec ();
    }
}
