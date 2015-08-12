#ifndef VIDEORECORD_H
#define VIDEORECORD_H
#include "fcommand.h"
#include <QString>
//#include <QProcess>

namespace video
{
class VideoRecord
{
private:
    QString fileName;
    bool recording;

    //Métodos
    void defaultArguments();
public:
    CMD::FCommand *cmd;
    VideoRecord(QObject *parent=0);
    ~VideoRecord();

    //Métodos set
    bool setFileName(QString file, QString format);
    //Métodos get
    bool isRecording();//Esta gravando?
    //Métodos
    void recordScreen();
    void stopRecorder();
};
}
#endif // VIDEORECORD_H
