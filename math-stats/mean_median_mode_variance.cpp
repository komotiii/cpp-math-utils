#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	cout << "Enter the number of data\n";
	int n;
	cin >> n;

	cout << "Enter all data | ex) n = 4 -> 8 4 7 1\n";
	vector<int> S(n);
	rep(i, n) {
		cin >> S[i];
	}

	sort(S.begin(), S.end());
	cout << "\n" << "Result below;" << "\n" << "After sort: ";
	rep(i, n) {
		cout << S[i] << ' ';
	}
	cout << "\n";
	double sum = 0;
	rep(i, n) {
		sum += S[i];
	}

	cout << "Sum: " << sum << "\n";
	double average = sum / n;
	cout << "Average: " << average << "\n";
	cout << "Median: ";

	if (n % 2 == 1) {
		cout << S[(n + 1) / 2 - 1] << "\n";
	}
	else {
	double a2 = S[(n / 2 ) - 1] + S[n / 2] ;
		cout << a2 / 2 << "\n";
	}
	vector<int> A(n);
	vector<int> B(n);
	int j = 0;
	rep(i, n - 1) {
		if (S[i] == S[i + 1]) {
			A[j]++;
			B[j] = S[i];
		}
		else {
			j++;
		}
	}
	int max = -1;
	rep(i, n) {
		if (max < A[i]) {
			max = A[i];
		}
	}
	cout << "Mode: ";
	rep(i, n) {
		if (j == n - 1) {
			cout << S[i] << " ";
	}
	else if (max == A[i]) {
			cout << B[i] << " ";
		}
	}
	cout << "\n";
	cout << "Variance: ";
	sum = 0;
	rep(i, n) {
		sum += S[i] * S[i];
	}
	cout << sum / n - average * average;
    cout << endl << endl;
    cout << "Operation completed. Press any key to exit the program." << endl;
    cin.get();
    cin.get();
    return 0;
}
