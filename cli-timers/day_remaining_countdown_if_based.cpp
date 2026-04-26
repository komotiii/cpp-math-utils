#include <Windows.h>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
// break付きのキーワード
string getPresentDateTime() {
  time_t tt;
  struct tm *st;
  time(&tt);
  st = localtime(&tt);
  return asctime(st);
}
int main() {
    while(1){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string nowtime = getPresentDateTime();
    string hs = nowtime.substr(11, 2);
    string ms = nowtime.substr(14, 2);
    string ss = nowtime.substr(17, 2);
    int h = 23 - stoi(hs);
    int m = 60 - stoi(ms);
    int s = 60 - stoi(ss);
    s--;
    cout << "   " << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s;
    cout << " |  " <<  "<= " << (h*3600+m*60+s)*100/(24*60*60) << " %   "  << "=> " << 100-(h*3600+m*60+s)*100/(24*60*60) << " %   " ;
    cout << "\r" << flush;
    while (!(h == 0 && m == 0 && s == 0)) {
        cout << "   " << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s;
        if(s == 0 && m == 0){
        h--;
        m = 59;
        s = 60;
        }
        else if(s == 0){
            if(m % 10 == 0)    cout << " |  " <<  "<= " << (h*3600+m*60+s)*100/(24*60*60) << " %   "  << "=> " << 100-(h*3600+m*60+s)*100/(24*60*60) << " %   " ;
            m--;
            s=60;
        }
        s--;
        cout << "\r" << flush;
        Sleep(1000);
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    cout << endl;
    cout << "Next day";
    cin.get();
    SetConsoleTextAttribute(hConsole, 7);
    system("cls");
    }
}

