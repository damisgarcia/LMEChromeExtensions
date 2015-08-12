#ifndef FCOMMAND_H
#define FCOMMAND_H

#include <QString>
#include <QProcess>

//Classe base para executar programas externos
namespace CMD
{
class FCommand
{
private:  
    QProcess *process;
    bool running;
public:
    QString command;
    QString program;
    QString arguments;
    explicit FCommand(QObject * parent = 0);
    ~FCommand();

    //Métodos gets
    bool isRunning();
    //Métodos
    void clearArguments();
    void run();
    void write(const char *str);
    //virtual void write(QByteArray *str);
    void kill();
    bool finish(int time = -1);
};
}

#endif // FCOMMAND_H
