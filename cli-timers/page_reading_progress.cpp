#include <Windows.h>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <conio.h>
using namespace std;
string getPresentDateTime() {
  time_t tt;
  struct tm *st;
  time(&tt);
  st = localtime(&tt);
  return asctime(st);
}

int main() {
    ofstream file("record.txt", ios::app);
    int num = 0;
    int i = 2;
    int need;
    int current;
    int all;
    int p = 0;
        cin >> current >> all;
    if(current > all) swap(current, all);
    cout << "current pages : " << current << endl;
    cout << "all pages : " << all << endl;
    need = all - current + 1;
    int remain = need;
    string nowtime = getPresentDateTime();
    string hs = nowtime.substr(11, 2);
    string ms = nowtime.substr(14, 2);
    int h = stoi(hs);
    int m = stoi(ms);
    cin.get();
    cout << "start time: " << nowtime.substr(11, 8) << endl<< endl<< endl;
    file << "start time: " << nowtime.substr(11, 8) << endl ;
    while (need != 0) {
        cout << "now : " << current<< " pages" << "  | "  << 100 -need * 100 /remain <<" %"<<  " | "<<  "remain : " << need << " pages               " ;
        cout << "\r";
        _getch();
        need--;
        current++;
    }
    cout << "DONE                                                   ";
    cout << endl << endl;
    int time = h*60+m;
    nowtime = getPresentDateTime();
    hs = nowtime.substr(11, 2);
    ms = nowtime.substr(14, 2);
    h = stoi(hs);
    m = stoi(ms);
    time = h*60+m -time;
    cout << "Escaped time : " << setw(2) << setfill('0') << (time/60)%24 << ":" << setw(2) << setfill('0') << time%60 << endl;
    file << "Escaped time : " << setw(2) << setfill('0') << (time/60)%24 << ":" << setw(2) << setfill('0') << time%60 << endl;
    cin.get();
    return 0;
}
