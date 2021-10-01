#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> ca{"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

  string input;
  cin >> input;

  size_t idx;
  for (size_t i = 0 ; i < ca.size() ; i++) {
    while (1) {
      idx = input.find(ca[i]);
      if (idx == string::npos) break;
      input.replace(idx, ca[i].length(), ".");
    }
  }

  cout << input.length() << endl;
  return 0;
}
