#include <iostream>
#include <vector>

long long sum(std::vector<int> &a);

int main() {
  int n;

  std::cin >> n;

  std::vector<int> a(n);

  for (int i = 1 ; i < (n+1) ; i++) {
    a.push_back(i);
  }

  std::cout << sum(a) << std::endl;


  return 0;
}

long long sum(std::vector<int> &a) {
  int ret = 0;

  for (auto i = a.begin(); i != a.end(); i++) {
    ret += *i;
  }

  return ret;
}
