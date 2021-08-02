#include <iostream>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	int array[n];
	for (int i = 0 ; i < n ; i++) {
		std::cin >> array[i];
	}

	int numOfElements = sizeof(array) / sizeof(int);

	std::cout << *std::min_element(array, array + numOfElements) << " " << *std::max_element(array, array + numOfElements) << std::endl;

	return 0;
}
