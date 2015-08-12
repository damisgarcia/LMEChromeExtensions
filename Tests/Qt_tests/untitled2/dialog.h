#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <Classes/videorecord.h>

namespace Ui {
class Dialog;
}

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    video::VideoRecord *vid;
};

#endif // DIALOG_H
