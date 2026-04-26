#include <Windows.h>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
    FILE* outputfile;
    outputfile = fopen("output.txt", "w");
    if (outputfile == NULL) {
        printf("cannot open\n");
        exit(1);
    }
    unsigned long long int num = 0;
    unsigned long long int i = 2;
    unsigned long long int need;
    int p = 0;
    cout << "How many prime numbers do you want to generate?\n";
    cin >> need;
    cin.get();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    while (num < need) {
        int flag = 1;
        for (unsigned long long int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            num++;
            fprintf(outputfile, "%llu prime number: %llu \n", i, num);
        }
        i++;
    }
    SetConsoleTextAttribute(hConsole, 7);
    cout << endl << endl;
    fclose(outputfile);
    cout << "Operation completed." << endl;
    cout << "Press any key to exit the program." << endl;

    cin.get();
    return 0;
}
