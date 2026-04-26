#include <Windows.h>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Get current date and time
string getPresentDateTime() {
    time_t tt;
    struct tm* st;
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
    int s = stoi(ss);
    int sum = h * 60 * 60 + 60 * m + s;
    int rsum = 24 * 60 * 60;
    int diff = rsum - sum;

    while (diff >= 0) {
        cout << "Time remaining: " << setw(2) << setfill('0') << diff / 3600 << ":" << setw(2) << setfill('0') << diff % 3600 / 60 << ":" << setw(2) << setfill('0') << diff % 60;
        cout << "\r" << flush;
        diff--;
        Sleep(1000);
    }

    cout << "Next day" << endl;

    return 0;
}
