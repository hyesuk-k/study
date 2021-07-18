#include <iostream>

int main() {
	int ret = 0;
	int x, y;

	std::cin >> x >> y;

	if ((x > 0) && (y > 0)) {
		ret = 1;
	} else if ((x < 0) && (y > 0)) {
		ret = 2;
	} else if ((x < 0) && (y < 0)) {
		ret = 3;
	} else {
		ret = 4;
	}
	
	std::cout << ret << std::endl;

	return 0;
}
