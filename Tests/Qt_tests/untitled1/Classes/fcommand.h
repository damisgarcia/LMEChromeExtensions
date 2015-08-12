#ifndef FCOMMAND_H
#define FCOMMAND_H

#include <QString>
#include <QProcess>

//Classe base para executar programas externos
class FCommand
{
private:
    QString program;
    QStringList arguments;
    QProcess *process;
    bool isRuning;
public:
    explicit FCommand(QObject * parent = 0);
    ~FCommand();
    //Métodos sets
    void setProgram(QString str);
    void setArguments(QStringList list);
    //Métodos gets
    QString program();
    QStringList arguments();
    bool isRuning();
    //Métodos
    void run();
    void write(const char *str);
    virtual void write(QByteArray *str);
    bool kill();
    bool finish(int time = -1);
};

#endif // FCOMMAND_H
