#include <iostream>
#include <string>

using namespace std;

int main() {
  string num;
  cin >> num;

  int ret = 0;
  for (auto &n : num) {
    ret += (n - 'A') / 3 + 3;
    switch (n) {
      case 'S': case 'V': case 'Y': case 'Z':
        ret -= 1;
        break;
      default:
        break;
    }
  }

  cout << ret << endl;

  return 0;
}
