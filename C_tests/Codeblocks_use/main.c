#define __STDC_CONSTANT_MACROS
//extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavdevice/avdevice.h>
//}

#include <windows.h>
#include <stdio.h>
#include <time.h>
//#include <iostream>

//using namespace std;

int main() {
  //cout<<"Numero de dispositivos"<<endl;
//	struct AVDeviceInfoList* list=NULL;
//	struct AVDeviceInfo* info=NULL;
//  	avdevice_free_list_devices(&list);
//  	if(list == NULL)return -1;
//	printf("Numero de dispositivos: %d",list->nb_devices);
	//system("script.bat");
//	clock_t t1 = clock();
//	Sleep(1000);
//	clock_t t2 = clock();
//	printf("Tempo %f",(float)t2-t1);

	system("ffmpeg -framerate 25 -f dshow -i video=\"UScreenCapture\" output.mp4");
	printf("\n####################Querendo sair############################\n");
	system("q");
  return 0;
}


