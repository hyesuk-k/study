#include <iostream>
using namespace std;

#define DIV_NUM 42

int main() {
	int arr[10];
	int arrRet[DIV_NUM] = {0, };

	for (int i = 0 ; i < 10 ; i++) {
		cin >> arr[i];
	}

	int rest = 0;
	for (int i = 0 ; i < 10 ; i++) {
		rest = arr[i] % DIV_NUM;
		arrRet[rest] = 1;
	}

	int count = 0;
	for (int i = 0 ; i < DIV_NUM ; i++) {
		if (arrRet[i] == 1) {
			count++;
		}
	}

	cout << count << endl;	
	return 0;
}
