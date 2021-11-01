#include <iostream>
#include <string>

using namespace std;

int main() {
  string a,b;
  cin >> a >> b;

  uint32_t maxLen = a.size();
  if (a.size() > b.size()) maxLen = a.size();
  else if (b.size() > a.size()) maxLen = b.size();

  string ret(maxLen, '0');
  bool carry = false;
  int tmp = 0;

  for (uint32_t i = 0 ; i < maxLen ; i++) {
    if (i < a.size()) {
      tmp += a[a.size() - i - 1] - '0';
    }

    if (i < b.size()) {
      tmp += b[b.size() - i - 1] - '0';
    }

    if (tmp >= 10) {
      carry = true;
      tmp -= 10;
      ret[maxLen - i - 1] = tmp + '0';
      tmp = 1;
    } else {
      carry = false;
      ret[maxLen - i - 1] = tmp + '0';
      tmp = 0;
    }    
  }

  if (carry) ret.insert(ret.begin(), '1');

  cout << ret << endl;

  return 0;
}
