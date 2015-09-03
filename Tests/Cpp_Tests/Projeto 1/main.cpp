#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#undef NO_OLDNAMES

using namespace std;

int main()
{
    FILE *fp;
    int status;

    fp = popen("ffmpeg -t 00:00:10 -f dshow -i video=UScreenCapture output.mp4 ", "w");
    if (fp == NULL) return -2;
    Sleep(15000);

    fputs("q",fp);  ///Enviar "q" para encerrar captura
    status = pclose(fp);

    if (status == -1) return -1;

    return 0;
}
