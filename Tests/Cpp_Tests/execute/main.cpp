#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    FILE *fp;
    int status;

    fp = popen("ffmpeg -f dshow -i video=UScreenCapture output.mp4 ", "w");
    if (fp == NULL) return -1;
    Sleep(20000);

    fputs("q",fp);  ///Enviar "q" para encerrar captura
    status = pclose(fp);

    if (status == -1) return -2;

    return 0;
}
