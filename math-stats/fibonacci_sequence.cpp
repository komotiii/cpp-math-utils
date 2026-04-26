#include <Windows.h>
#include <iostream>
using namespace std;

int main (){
    unsigned long long int x = 1;
    unsigned long long int y = 1;
    unsigned long long int t = 2;
    cout << x << endl;
    Sleep(50);
    cout << y << endl;
    Sleep(50);
    int n=1;
    while(n<=91){
        cout << t << endl;
        x = y;
        y = t;
        t = x+y;
        n++;
    }
    cout << "size over" << endl;
    cout << endl;
    cout << "Operation completed. Press any key to exit the program." << endl;
    cin.get();
    return 0;
}