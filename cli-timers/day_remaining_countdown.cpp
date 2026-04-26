#define _WIN32_WINNT 0x0601

#include <Windows.h>
#include <chrono>
#include <iostream>
#include <string>
#include <iomanip>
#include <thread>
using namespace std;
using namespace chrono;

string getPresentDateTime() {
    auto now = system_clock::now();
    auto now_c = system_clock::to_time_t(now);
    return ctime(&now_c);
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    string nowtime = getPresentDateTime();
    nowtime = getPresentDateTime();

    auto now = system_clock::now();
    time_t now_c = system_clock::to_time_t(now);
    tm* st = localtime(&now_c);

    int h = st->tm_hour;
    int m = st->tm_min;
    int s = st->tm_sec;

    int sum = h * 60 * 60 + 60 * m + s;
    int rsum = 24 * 60 * 60;
    int diff = rsum - sum;

    while (diff >= 0) {
        cout << setw(2) << setfill('0') << diff / 3600 << ":" << setw(2) << setfill('0') << diff % 3600 / 60 << ":" << setw(2) << setfill('0') << diff % 60;
        cout << "\r" << flush;
        diff--;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    cout << "Next day";
    SetConsoleTextAttribute(hConsole, 7);
}
