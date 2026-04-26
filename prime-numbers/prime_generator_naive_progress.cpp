#include <Windows.h>
#include <iostream>
using namespace std;

int main (){
    FILE *outputfile;
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
    cin.get(); // 改行文字を無視
    while(num < need){
        int flag = 1;
        for(unsigned long long int j = 2;j<i;j++){
            if(i%j==0){
                flag = 0;
                break;
            }
        }
        if(flag){
        num++;
        fprintf(outputfile,"%llu prime number: %llu \n",i,num);
        }
        i++;
        int new_p = num * 100 / need;
        if (new_p != p) {
            p = new_p;
            cout << "\r[";
            for (int k = 0; k < 50; k++) {
                if (k < p / 2) {
                    cout << "=";
                }
                else {
                    cout << " ";
                }
            }

            cout << "] " << p << "% Completed\r" << flush;
        }
    }
    //     if(num * 100 / need == p){
    //         cout << "------  " << p  << "% complete  ------\r" << flush;
    //         p++;
    //     }
    cout << "[==================================================] 100% Done      \r" << endl;
    cout << endl;
    cout << "Operation completed. Press any key to exit the program." << endl;
    fclose(outputfile);
    cin.get();
    return 0;
}
