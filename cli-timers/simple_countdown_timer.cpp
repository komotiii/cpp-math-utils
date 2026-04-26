#include <Windows.h>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
int main() {
  while(true){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  string name;
  cout << "## Enter name : ";
  SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
  cin >> name;
  SetConsoleTextAttribute(hConsole, 7);
  int alarm;
  cout << "## Enter time : ";
  cin >> alarm;
  int sum = alarm*60 - alarm * 4 / 60;
  while (sum >= 0) {
    cout << setw(2) << setfill('0') << sum/3600 << ":" << setw(2) << setfill('0') << sum % 3600 / 60 << ":" << setw(2) << setfill('0') << sum % 60 ;
    cout << " |  #"<<  sum << "s   ";
    cout << "\r" << flush;
    --sum;
    Sleep(1000);
  }
  MessageBeep( MB_ICONASTERISK );
  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
  cout << "Timer Done!            ";
  SetConsoleTextAttribute(hConsole, 7);// SystemAsterisk
  MessageBeep( MB_ICONHAND );
  cout << endl;
  cout << "Press Enter";
  cin.get();
  cin.get();
  system("cls");
}
}
