#include <iostream>

int main() {
	int h, m;
	int rh, rm;
	std::cin >> h >> m;

	if ((m - 45) > -1) {
		rh = h;
		rm = m - 45;  // more than 45m
	} else {
		if ((h - 1) < 0) {
			rh = 23;
		} else {
			rh = h - 1;
		}
		rm = (60 + m) - 45;
	}

	std::cout << rh << " " << rm << std::endl;
	return 0;
}
