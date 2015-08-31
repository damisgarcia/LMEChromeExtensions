#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    vid = new video::VideoRecord(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

    if(!vid->isRecording())
    {
        QString str = ui->textBox->text();

        if(!str.isEmpty()) vid->setFileName(str,"mp4");
        else vid->setFileName("testando","mp4");
        vid->recordScreen();
        ui->pushButton->setText("Parar");
//        qDebug()<<vid->cmd->command;
    }
    else
    {
        vid->stopRecorder();
        ui->pushButton->setText("Iniciar");
//        close();
    }
}
