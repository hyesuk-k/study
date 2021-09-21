#include <iostream>

using namespace std;

int main() {
  int count = 0;

  cin >> count;

  char *c = new char[count];
  cin >> c;

  int ret = 0;
  for (int i = 0 ; i < count ; i++) {
    ret += (int)(c[i]-'0');
  }

  cout << ret << endl;

  delete[] c;
  
  return 0;
}
