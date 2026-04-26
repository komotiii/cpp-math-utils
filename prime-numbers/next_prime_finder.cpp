#include <Windows.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

unsigned long long int num = 0;
bool IsPrime(unsigned long long int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
    double rtNum = sqrt(num);
    for(unsigned long long int i = 3; i <= rtNum; i += 2) if (num % i == 0)return false;
    return true;
}

int main (){
    FILE *outputfile;
    outputfile = fopen("outputfast.txt", "w");
    if (outputfile == NULL) {
    printf("cannot open\n");
    exit(1);
    }
    unsigned long long int start;
    cout << "what number do you start to search prime number?\n";
    cin >> start;
    cin.get(); // 改行文字を無視
    while(true){
        if(IsPrime(start)){
        cout << endl << "!!!!min prime number is " << start << endl;
        }
        cout << "#";
        start++;
    }
}
