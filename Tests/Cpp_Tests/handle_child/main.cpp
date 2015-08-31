#include <iostream>
#define WINDOWS_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <thread>
#include <cassert>
#include <stdio.h>

using namespace std;

enum { ParentRead, ParentWrite, ChildWrite, ChildRead, NumPipeTypes };

int main()
{
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(sa);
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL;

    HANDLE pipes[NumPipeTypes];
    if (!CreatePipe(&pipes[ParentWrite], &pipes[ChildRead], &sa, 0))
        return 0;
    if (!CreatePipe(&pipes[ParentRead], &pipes[ChildWrite], &sa, 0))
        return 0;

    // make sure the handles the parent will use aren't inherited.
    SetHandleInformation(pipes[ParentRead], HANDLE_FLAG_INHERIT, 0);
    SetHandleInformation(pipes[ParentWrite], HANDLE_FLAG_INHERIT, 0);

    STARTUPINFO si;
    ZeroMemory(&si, sizeof(STARTUPINFO));

    si.cb = sizeof(STARTUPINFO);
    //si.wShowWindow = SW_SHOW;
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.dwFlags |= STARTF_USESTDHANDLES;
//    si.dwFlags = STARTF_USEHOTKEY;
    si.hStdOutput = pipes[ChildWrite];
    si.hStdError = pipes[ChildWrite];
    si.hStdInput = pipes[ChildRead];
    //si.hStdInput = stdout;
    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

    TCHAR cmd[] = "ffmpeg -f dshow -i video=UScreenCapture output.mp4";
    if (!CreateProcess(NULL, cmd, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
        return 0;

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    Sleep(20000);
    cout<<"Fim"<<endl;
    CHAR chBuf[] = "q\n";
    WriteFile(pipes[ParentWrite], chBuf, 3, NULL, NULL);
    Sleep(5000);

    CloseHandle(pipes[ChildRead]);
    CloseHandle(pipes[ChildWrite]);
    CloseHandle(pipes[ParentWrite]);
    CloseHandle(pipes[ParentRead]);
    return 0;
}
