#include <Windows.h>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
string getPresentDateTime() {
  time_t tt;
  struct tm *st;
  time(&tt);
  st = localtime(&tt);
  return asctime(st);
}
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string nowtime = getPresentDateTime();
    string hs = nowtime.substr(11, 2);
    string ms = nowtime.substr(14, 2);
    string ss = nowtime.substr(17, 2);
    int h = stoi(hs);
    int m = stoi(ms);
    int s = stoi(ss);
    int diff = 24*60*60 - (h*60*60+60*m+s);
    while (diff >= 0) {
        cout << "  " << setw(2) << setfill('0') << diff/3600 << ":" << setw(2) << setfill('0') << diff % 3600 / 60 << ":" << setw(2) << setfill('0') << diff % 60 ;
        cout << " |  " << 101 - (diff*100 )/(24*60*60 ) << " %   " ;
        cout << "\r" << flush;
        diff--;
        Sleep(1000);
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    cout << "Next day";
    SetConsoleTextAttribute(hConsole, 7);
}
