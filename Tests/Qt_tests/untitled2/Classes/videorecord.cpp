#include "videorecord.h"
namespace video
{
VideoRecord::VideoRecord(QObject *parent)
{
    cmd = new CMD::FCommand(parent);
    recording = false;
    cmd->program = "ffmpeg ";
    defaultArguments();
}

VideoRecord::~VideoRecord()
{
    cmd->~FCommand();
}

bool VideoRecord::setFileName(QString file, QString format)
{
    if(format == "mp4")
    {
        fileName = file + "." + format;
        return true;
    }
    else
    {
        return false;
    }
}

bool VideoRecord::isRecording()
{
    return recording;
}

void VideoRecord::recordScreen()
{
    cmd->clearArguments();
    this->defaultArguments();
    cmd->arguments += fileName;
    cmd->run();
    recording = true;
}

void VideoRecord::defaultArguments()
{
    cmd->arguments = "-f dshow -i video=UScreenCapture ";
}

void VideoRecord::stopRecorder()
{
    cmd->write("q"); //Parar captura
    cmd->finish();   //Finaliza o processos
}
}

