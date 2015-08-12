#include "videorecord.h"

VideoRecord::VideoRecord(QObject *parent):FCommand(parent)
{
    recording = false;
    program = "ffmpeg";
    arguments << "-f" << "dshow" << "-i" << "video=UScreenCapture";
}

VideoRecord::~VideoRecord()
{

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
    arguments.clear();
    defaultArguments();
    arguments << fileName;
    run();
    recording = true;
}

void VideoRecord::defaultArguments()
{
    arguments << "-f" << "dshow" << "-i" << "video=UScreenCapture";
}

void VideoRecord::stopRecorder()
{
    write("q"); //Parar captura
    finish();   //Finaliza o processos
}


