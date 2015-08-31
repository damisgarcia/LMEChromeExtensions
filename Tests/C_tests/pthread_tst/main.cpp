#include <pthread.h>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <sstream>  // Required for stringstreams

/* this function is run by the second thread */
bool flag = true;

std::string IntToString ( int number )
{
  std::ostringstream oss;

  // Works just like cout
  oss<< number;

  // Return the underlying string
  return oss.str();
}


void *rotina(void *a)
{
    std::string base = "ffmpeg -f dshow -i video=UScreenCapture -t 0:0:59 ";
    std::string name = "output";
    std::string format = ".mp4";
    int counter = 0;
    while(counter<5)
    {
        //system("ffmpeg -f dshow -i video=UScreenCapture -t 0:0:15 output.mp4 ");
        std::string number = IntToString(counter);
        std::string command = base + name + number + format;
        std::cout<< command<<std::endl;
        system(command.c_str());
        counter++;
    }
    /* the function must return something - NULL will do */
    return NULL;
}

int main()
{
    int x;
    pthread_t rotina_thread;
    /* create a second thread which executes inc_x(&x) */
    if(pthread_create(&rotina_thread, NULL, rotina, &x)){
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    Sleep(20000);
    fprintf(stdin,"q\n");
    /* wait for the second thread to finish */
    if(pthread_join(rotina_thread, NULL))

    return 0;

}
