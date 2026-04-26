#include <Windows.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

unsigned long long int num = 0;
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double rtNum = sqrt(num);
    for(int i = 3; i <= rtNum; i += 2) if (num % i == 0)return false;
    return true;
}

int main (){
    FILE *outputfile;
    outputfile = fopen("outputfast.txt", "w");
    if (outputfile == NULL) {
    printf("cannot open\n");
    exit(1);
    }
    unsigned long long int i = 2;
    unsigned long long int need;
    int p = 0;
    cout << "How many prime numbers do you want to generate?\n";
    cin >> need;
    cin.get(); // 改行文字を無視
    while(num < need){
        if(IsPrime(i)){
        num++;
        fprintf(outputfile,"%llu prime number: %llu \n",i,num);
        }
        i++;
    if(num * 100 / need == p){
    cout << "------ [ " << p  << "% complete ] ------\r" << flush;
    p++;
    }
    }
    cout << endl << endl;
    cout << "Operation completed. Press any key to exit the program." << endl;
    fclose(outputfile);
    cin.get();
    return 0;

}
