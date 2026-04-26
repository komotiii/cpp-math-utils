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
    string nowtime = getPresentDateTime();
    string hs = nowtime.substr(11, 2);
    string ms = nowtime.substr(14, 2);
    string ss = nowtime.substr(17, 2);
    int h = stoi(hs);
    int m = stoi(ms);
    int max,now;
    cout << "Enter max reason : ";
    cin >> max ;
    cout << "Enter now reason : ";
    cin >> now;
    int diff = (max - now )*6;
    int time = h*60+m+diff;
    cout << diff << " minutes need" << endl;
    cout << "Estimated time : " << setw(2) << setfill('0') << (time/60)%24 << ":" << setw(2) << setfill('0') << time%60 ;
    cout << endl;
    cout << endl;
    cout << "Press Enter#";
    cin.get();
    cin.get();
}
