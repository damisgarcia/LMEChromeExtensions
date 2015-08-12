#include "fcommand.h"
#include <QDebug>
namespace CMD
{
FCommand::FCommand(QObject * parent)
{
    process = new QProcess(parent);
}

FCommand::~FCommand()
{
    process->~QProcess();
}

bool FCommand::isRunning()
{
    return running;
}

void FCommand::clearArguments()
{
    arguments.clear();
}

void FCommand::run()
{
    process->setProcessChannelMode(QProcess::MergedChannels);
    command = program + arguments;
    qDebug()<<command;
    process->start(command);
    running = true;
}

void FCommand::write(const char *str)
{
    process->write(str);
}

//mata o processo
void FCommand::kill()
{
    running = false;
    process->kill();
}

//Finaliza o processo
bool FCommand::finish(int time)
{
    running = false;
    return process->waitForFinished(time);
}
}
