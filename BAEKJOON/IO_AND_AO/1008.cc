#include <iostream>

int main() {
	double n1, n2;

	std::cin >> n1 >> n2;
	std::cout.precision(9);
	std::cout << std::fixed << n1/n2 << std::endl;
	
	return 0;

}
