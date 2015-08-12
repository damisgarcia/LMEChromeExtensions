#include "fcommand.h"

FCommand::FCommand(QObject * parent = 0)
{
    process = new QProcess(parent);
}

FCommand::~FCommand()
{

}

void FCommand::setProgram(QString str)
{
    program = str;
}

void FCommand::setArguments(QStringList list)
{
    arguments = list;
}

QString FCommand::program()
{
    return program;
}

QStringList FCommand::arguments()
{
    return arguments;
}

void FCommand::run()
{
    process->setProcessChannelMode(QProcess::MergedChannels);
    process->start(program,arguments);
    isRuning = true;
}

void FCommand::write(const char *str)
{
    process->write(str);
}

//mata o processo
bool FCommand::kill()
{
    return process->kill();
}

//Finaliza o processo
bool FCommand::finish(int time)
{
    return process->waitForFinished(time)
}


