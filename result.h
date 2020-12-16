#ifndef RESULT_H
#define RESULT_H

#include <QWidget>

namespace Ui {
class Result;
}

class Result : public QWidget
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();
public slots:
    void inforeceive(QString name);

private:
    Ui::Result *ui;
};

#endif // RESULT_H
