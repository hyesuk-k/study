#include <iostream>
#include <algorithm>

using namespace std;

#define ARR_SIZE 9

int main() {

	int *arr = new int[ARR_SIZE];
	for (int i = 0 ; i < ARR_SIZE ; i++) {
		cin >> arr[i];
	}

	int maxValue = *max_element(arr, arr+ARR_SIZE);
	cout << maxValue << endl;
	cout << distance(arr, find(arr, arr+ARR_SIZE, maxValue)) + 1 << endl;

	return 0;
}
