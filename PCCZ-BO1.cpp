
#include <iostream>
#include <Windows.h>
#include <synchapi.h>

int main() {

    LPCUWSTR gameWindow = L"Call of Duty®: BlackOps";
    HWND weed = FindWindow(0, gameWindow);
    
    if (weed == 0){
        printf("Couldn't find the game.\nPress enter to exit...");
        getchar();
        exit(-1);
    }

    DWORD process_ID;
    GetWindowThreadProcessId(weed, &process_ID);
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_ID);
    printf("Game was found\n");
    printf("Enjoy!\nLeave this program running in the background while playing\n");
    int money = 999999;
    int health = 999999;
    DWORD moneyDword = sizeof(money);
    DWORD healthDword = sizeof(health);
    WriteProcessMemory(hProcess, (LPVOID)0x01C0A6C8, &money, moneyDword, NULL);
    for (;;) {
        
        WriteProcessMemory(hProcess, (LPVOID)0x01A7987C, &health, healthDword, NULL);
        Sleep(0xFF);
    }
    return 0;
}

