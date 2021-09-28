#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define NUMBER_OF_ALPHA 26

int main() {
  string word;
  int alpha[NUMBER_OF_ALPHA] = {0, };

  cin >> word;

  transform(word.begin(), word.end(), word.begin(), ::toupper);

  for (auto &w : word) {
    int idx = w - 'A';
    alpha[idx] += 1;
  }

  int maxNum = 0;
  int maxAlpha = 0;

  for (int i = 0 ; i < NUMBER_OF_ALPHA ; i++) {
    if (maxNum < alpha[i]) {
      maxNum = alpha[i];
      maxAlpha = i;
    }
  }

  int dup = 0;
  for (int i = 0 ; i < NUMBER_OF_ALPHA ; i++) {
    if (maxNum == alpha[i]) {
      dup++;
    }
  }

  if (dup == 1) {
    cout << (char)(maxAlpha + 'A') << endl;
  } else {
    cout << "?" << endl;
  }


  return 0;
}
