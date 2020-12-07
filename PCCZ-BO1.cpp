
#include <iostream>
#include <Windows.h>
#include <synchapi.h>
#include <vector>

int main() {

    int based_value = 999999;
    //offsets w/o pointers because COD uses mostly static addresses lmao
    std::vector<int*> changeAddrList = {
        (int*)0x01C0A6C8,
        (int*)0x01A7987C,
        (int*)0x01808F00,
        (int*)0x01C08F10
    };


    DWORD based_client0 = sizeof(based_value);
    DWORD process_ID;

    LPCUWSTR gameWindow = L"Call of Duty®: BlackOps";
    HWND weed = FindWindow(0, gameWindow);
    
    if (weed == 0){
        printf("Couldn't find the game.\nPress enter to exit...");
        getchar();
        exit(-1);
    }
    GetWindowThreadProcessId(weed, &process_ID);
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_ID);
    printf("Game was found\n");
    printf("Enjoy!\nLeave this program running in the background while playing\n");
    for (auto addr : changeAddrList) {
        WriteProcessMemory(weed, (LPVOID)addr, &based_value, based_client0, 0);
    }
    return 0;
}

