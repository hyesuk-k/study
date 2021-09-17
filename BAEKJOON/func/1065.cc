#include <iostream>

using namespace std;
#define MAX_NUM 1001

bool diffV(int num);

int main() {
  int num;
  cin >> num;

  int count = 0;

  for (int i = 1 ; i <= num ; i++) {
    if (diffV(i) == true) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}

bool diffV(int num) {
  int arr[3] = {0, };
  int n;
  int i = 0;

  if ((num > 0) && (num < 100)) return true;
  if (num == 1000) return false;

  do {
    n = num % 10;
    arr[i++] = n;
  } while ((num /= 10) != 0);

  int diff1, diff2;

  diff1 = arr[0] - arr[1];
  diff2 = arr[1] - arr[2];

  if (diff1 != diff2) return false;

  return true;
}
