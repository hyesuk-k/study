#include <iostream>

#define MAX_NUM 2100000000

using namespace std;
int main() {
  int ret = 1;
  int a, b, c;

  cin >> a >> b >> c;

  if ((c - b) < 0) {
    cout << "-1" << endl;
    return 0;
  }

  while (1) {
    if ((c * ret)
        - (a + (b * ret)) > 0) {
      break;
    }
    ret++;
  }

  cout << ret << endl;
  return 0;
}
