#include <Windows.h>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
// break付きのキーワード
#define CASE        break;case
#define DEFAULT     break;default
// 記号定数
#define ESC         (0x1B)
string getPresentDateTime() {
  time_t tt;
  struct tm *st;
  time(&tt);
  st = localtime(&tt);
  return asctime(st);
}
int main() {
  ofstream file("record.txt", ios::app);
  while(true){
  int alarm;
  bool flag = false;
  string nowtime = getPresentDateTime();
  string nt = nowtime.substr(11,8);
  cout << nt << " now time" << endl;
  cout << "## Enter time : ";
  cin >> alarm;
  cout << "## Enter title : ";
  cin.get();
  string tittle;
  getline(cin, tittle);
  cout << "-------------------------------------------" << endl;
  nowtime = getPresentDateTime();
  string hs = nowtime.substr(11, 2);
  string ms = nowtime.substr(14, 2);
  string ss = nowtime.substr(17, 2);
  string timest = to_string(alarm);
  cout << "Time start  : " << hs << ":" << ms << ":" << ss <<  endl;
  cout << "Time end    : " << timest[0] << timest[1] << ":" << timest[2] << timest[3] << ":00" << endl;
  int h = stoi(hs);
  int m = stoi(ms);
  int s = stoi(ss);
  int sum = h*60 + m;
  int rsum = alarm / 100 * 60 + alarm % 100;
  int diff = (rsum - sum)*60 - s;
  int p = -1;
  int fdiff = diff;
  if(diff < 0) {
    diff = 0;
    fdiff = 1;
  }
  file << hs << ":" << ms << ":" << ss << " => " << timest[0] << timest[1] << ":" << timest[2] << timest[3] << ":00" << " | " <<  setw(2) << setfill('0') << diff/3600 << ":" << setw(2) << setfill('0') << diff % 3600 / 60 << ":" << setw(2) << setfill('0') << diff % 60 << " # ";
  file << tittle << endl;
  cout <<   "Time set up : " << setw(2) << setfill('0') << diff/3600 << ":" << setw(2) << setfill('0') << diff % 3600 / 60 << ":" << setw(2) << setfill('0') << diff % 60 ;
  cout << " |  #"<< diff/3600 << "h " <<  " #"<< diff / 60 << "m " << " #"<< diff << "s " << endl;
  cout << "-------------------------------------------" << endl << endl;
  while (diff >= 0) {
  if(diff / 60 % 5 == 0 && diff > 0){
  nowtime = getPresentDateTime();
  hs = nowtime.substr(11, 2);
  ms = nowtime.substr(14, 2);
  ss = nowtime.substr(17, 2);
  h = stoi(hs);
  m = stoi(ms);
  s = stoi(ss);
  sum = h*60 + m;
  diff = (rsum - sum)*60 - s;
  flag = true;
  }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (flag) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        cout << "Time adjust";
    } else {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        cout << "Time remain";
    }

    SetConsoleTextAttribute(hConsole, 7); // デフォルトの色に戻す
    flag = false;
    cout << " : " <<  setw(2) << setfill('0') << diff/3600 << ":" << setw(2) << setfill('0') << diff % 3600 / 60 << ":" << setw(2) << setfill('0') << diff % 60 ;
    cout << " |  #"<< diff/3600 << "h " <<  " #"<< diff / 60 << "m " << " #"<< diff << "s   "  /*<< " : " + getPresentDateTime()*/ ;
      int new_p = 100 - diff * 100 / fdiff;
        if (new_p != p) {
            p = new_p;
            cout << "[";
            for (int k = 0; k < 25; k++) {
                if (k < p / 4) cout << "#";
                else cout << " ";
            }
            cout << "] " << p << "%   ";
        }
    cout << "\r" << flush;
    if(diff == 0) break;
    diff--;
    Sleep(1000);
  }
  MessageBeep( MB_ICONASTERISK );
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
  cout << "Timer Done!";
  SetConsoleTextAttribute(hConsole, 7);
  cout << " : " << setw(2) << setfill('0') << diff/3600 << ":" << setw(2) << setfill('0') << diff % 3600 / 60 << ":" << setw(2) << setfill('0') << diff % 60 ;
  cout << " |  #"<< diff/3600 << "h " <<  " #"<< diff / 60 << "m " << " #"<< diff << "s" ;
  cout << endl;
  //Sleep(1000);         // SystemAsterisk
  MessageBeep( MB_ICONHAND );
  cout << endl;
  cout << "Press Enter";
  cin.get();
  system("cls");
  }
  file.close();
}
