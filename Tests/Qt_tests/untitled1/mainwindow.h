#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setFilename();
    void stop();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString filename;
    QString Dir;
    QString format;
    QStringList arguments;

    bool recording;
    QProcess *process;
};

#endif // MAINWINDOW_H
