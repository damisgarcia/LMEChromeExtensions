#-------------------------------------------------
#
# Project created by QtCreator 2015-08-06T15:45:46
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

#INCLUDEPATH += D:\FFmpeg
INCLUDEPATH += D:\ffmpeg2\include
#INCLUDEPATH += D:\ffmpeg3
LIBS += D:\ffmpeg2\lib\libavcodec.dll.a
LIBS += D:\ffmpeg2\lib\libavdevice.dll.a
LIBS += D:\ffmpeg2\lib\libavfilter.dll.a
LIBS += D:\ffmpeg2\lib\libavformat.dll.a
LIBS += D:\ffmpeg2\lib\libavutil.dll.a
LIBS += D:\ffmpeg2\lib\libpostproc.dll.a
LIBS += D:\ffmpeg2\lib\libswresample.dll.a
LIBS += D:\ffmpeg2\lib\libswscale.dll.a
