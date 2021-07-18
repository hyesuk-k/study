#include <iostream>

int main() {
	int year;
	int ret;
	
	std::cin >> year;

	if (((year % 4) == 0) && (!((year % 100) == 0) || ((year % 400) == 0))) {
	 	ret = 1;
	} else {
		ret = 0;
	}

	std::cout << ret << std::endl;

	return 0;
}
