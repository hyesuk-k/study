#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	int ret;
	char arr[10] = {0, };
	int arrOcc[10] = {0, };

	cin >> a >> b >> c;

	ret = a*b*c;

	sprintf(arr, "%d", ret);

	for (int j = 0 ; j < 10 ; j++) {
		for (int i = 0 ; i < 10 ; i++) {
			if (i == ((int)arr[j]-'0')) {
				arrOcc[i] += 1;
				break;
			}
		}
	}

	for (int i = 0 ; i < 10 ; i++) {
			cout << arrOcc[i] << endl;
	}

	return 0;
}
