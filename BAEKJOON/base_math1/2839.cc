#include <iostream>

using namespace std;
int main() {
  int n;
  cin >> n;

  int ret = 0;

  while (true) {

    if ((n % 5 == 0)) {
      ret += n / 5;
      break;
    } 

    n = n - 3;
    if (n < 0) {
      ret = -1;
      break;
    } else {
      ret++;
    }
  }

  cout << ret << endl;

  return 0;
}
