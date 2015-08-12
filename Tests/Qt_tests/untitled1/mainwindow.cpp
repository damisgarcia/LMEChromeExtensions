#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    recording = false;
    process = new QProcess(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    QString program = "ffmpeg";

//    QStringList arguments;
    if(!recording)
    {
        ui->pushButton->setText("Parar");
        process->setProcessChannelMode(QProcess::MergedChannels);
        process->start("ffmpeg -f dshow -i video=UScreenCapture output.mp4");
        recording = true;
    }
    else
    {
        stop();
        recording = false;
        ui->pushButton->setText("Iniciar");
//        close();
    }
}


void MainWindow::stop()
{
    if(this->recording)
    {
        process->write("q");
        process->waitForFinished(-1);
    }
}
