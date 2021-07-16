#include <iostream>

int main() {
	int i;
	char ret = 'F';

	std::cin >> i;

	if ((i > 89) && (i < 101)) {
		ret = 'A';
	} else if ((i > 79) && (i < 90)) {
		ret = 'B';
	} else if ((i > 69) && (i < 80)) {
		ret = 'C';
	} else if ((i > 59) && (i < 70)) {
		ret = 'D';
	}
	std::cout << ret << std::endl;

	return 0;
}
