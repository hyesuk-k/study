#include <iostream>

using namespace std;
int main() {
  int x;
  cin >> x;

  int num = 1;
  while (x > num) {
    x -= num;
    num++;
  }

  if (num % 2 == 0) {
    // ORDER BY denominator ASC
    cout << x << "/" << num - x + 1 << endl;
  } else {
    // ORDER BY denominator DESC
    cout << num - x + 1 << "/" << x << endl;
  }
  return 0;
}
