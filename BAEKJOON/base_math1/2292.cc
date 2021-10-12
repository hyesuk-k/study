#include <iostream>

using namespace std;
int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  int ret = 1;
  int count = 1;

  while (n > count) {
    count += (ret * 6);
    ret++;
  }

  cout << ret << endl;

  return 0;
}
