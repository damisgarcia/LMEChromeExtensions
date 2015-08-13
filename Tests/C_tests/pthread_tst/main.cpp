//#include <pthread.h>
//#include <stdio.h>
//#include <windows.h>
//
//void *process(void *aux)
//{
//    system("ffmpeg -f dshow -i video=UScreenCapture output.mp4");
//}
//
//int main()
//{
//    pthread_t myThread;
//    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
//    if(pthread_create(&myThread, NULL, process, NULL)) {
//        fprintf(stderr, "Error creating thread\n");
//        return 1;
//    }
//    printf("Aguardando...");
//    Sleep(20000);
//    //pthread_kill(myThread,0);
//    pthread_cancel(myThread);
//    return 0;
//
//}

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void process( )
{
    char command[]= "ffmpeg -f dshow -i video=UScreenCapture output.mp4";

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    // Start the child process.
    if( !CreateProcess( NULL,   // No module name (use command line)
        command,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory
        &si,            // Pointer to STARTUPINFO structure
        &pi )           // Pointer to PROCESS_INFORMATION structure
    )
    {
        printf( "CreateProcess failed (%d).\n", GetLastError() );
        return;
    }

    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}
int main()
{
    process();
}
