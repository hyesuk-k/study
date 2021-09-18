#include <iostream>

using namespace std;

#define MAX_NUM 10001

int d(int n);

int main() {
  bool nArr[MAX_NUM] = {false, };

  for (int i = 1 ; i < MAX_NUM ; i++) {
    int idx = d(i);
    if (idx < MAX_NUM)
      nArr[idx] = true;
  }

  for (int i = 1 ; i < MAX_NUM ; i++) {
    if (nArr[i] == false) {
      cout << i << endl;
    }
  }

  return 0;
}

int d(int n) {
  int ret = n;

  do {
    ret += n % 10;
  } while((n /= 10) != 0);

  return ret;
}
