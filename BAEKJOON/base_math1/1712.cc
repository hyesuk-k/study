#include <iostream>

#define MAX_NUM 2100000000

using namespace std;
int main() {
  int ret = 1;
  int a, b, c;

  cin >> a >> b >> c;

  int benefit = c - b;
  if (benefit <= 0) {
    cout << "-1" << endl;
    return 0;
  }

  ret += a / benefit;

  cout << ret << endl;
  return 0;
}
