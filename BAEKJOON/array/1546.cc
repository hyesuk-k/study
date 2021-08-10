#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int *score = new int[n];
	for (int i = 0 ; i < n ; i++) {
		scanf("%d", &score[i]);
	}

	int m = *max_element(score, score + n);

	float modi = 0.00;

	for (int i = 0 ; i < n ; i++) {
		modi += (float)score[i] / m * 100;
	}

	printf("%02f\n", modi/n);

	delete score;

	return 0;
}
