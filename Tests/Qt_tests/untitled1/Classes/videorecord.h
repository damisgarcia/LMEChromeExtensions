#ifndef VIDEORECORD_H
#define VIDEORECORD_H
#include "fcommand.h"
#include <QString>
//#include <QProcess>

class VideoRecord : public FCommand
{
private:
    QString fileName;
    bool recording;
public:
    VideoRecord(QObject *parent=0);
    ~VideoRecord();

    //Métodos set
    bool setFileName(QString file, QString format);
    //Métodos get
    bool isRecording();//Esta gravando?
    //Métodos
    void recordScreen();
    void defaultArguments();
    void stopRecorder();
};

#endif // VIDEORECORD_H
