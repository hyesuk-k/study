#include <iostream>

int main() {
	int n, i, j;

	scanf("%d", &n);

	for(i = 1 ; i <= n ; i++) {
		for (j = n ; j > 1 ; j--) {
			if (j > i) {
				printf(" ");
			} else {
				printf("*");
			}
		}
		printf("*\n");
	}
	return 0;
}

