#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

int countChar(string w, string word) {
  uint32_t pos = 0;
  uint32_t idx = 0;
  int count = 0;

  while((idx = word.find(w, pos)) != string::npos) {
    count++;
    pos = idx + 1;
  }

  return count;
}

int main() {
  string word;
  string mostFreqAlpha;

  cin >> word;

  transform(word.begin(), word.end(), word.begin(), ::toupper);

  int max = 0;

  for (auto &w : word) {
    string f = "";
    f = w;
    int ret = countChar(f, word);

    if ((max == ret)
        && (mostFreqAlpha != f)) {
      mostFreqAlpha = "?";
    }

    if (max < ret) {
      max = ret;
      mostFreqAlpha = f;
    }
  }
  cout << mostFreqAlpha << endl;

  return 0;
}
