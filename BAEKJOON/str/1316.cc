#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
  int caseNum;

  cin >> caseNum;

  int ret = 0;
  for (int i = 0 ; i < caseNum ; i++) {
    string input;
    cin >> input;

    bool isGWord = true;
    int sIdx = 0;
    vector<char> v;
    for (auto &a : input) {
      auto it = find(v.begin(), v.end(), a);
      if (it == v.end()) {
        v.push_back(a);
      } else {
        if (input[sIdx-1] != a) {
          isGWord = false;
        }
      }
      sIdx++;
    }
    if (isGWord) ret++;
  }

  cout << ret << endl;
  return 0;
}
