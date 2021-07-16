#include <iostream>
#include <string>

int main() {
	int n, m;

	std::cin >> n >> m;

	std::string str_m = std::to_string(m);

	for (int i = str_m.length()-1 ; i >= 0 ; i--) {
		int result = n * std::stoi(str_m.substr(i, 1)); 
		std::cout << result << std::endl;
	}

	// 6
	std::cout << n * m << std::endl;

	return 0;
}
