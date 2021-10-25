#include <iostream>

using namespace std;

int calcPersons(int k, int n) {
  if (k == 0) return n;
  if (n == 1) return 1;

  return (calcPersons(k-1, n) + calcPersons(k, n-1));
}

int main() {
  int t;
  cin >> t;

  for (int i = 0 ; i < t ; i++) {
    int k, n;
    // kÃþ, nÈ£
    cin >> k >> n;
    cout << calcPersons(k, n) << endl;
  }
  return 0;
}
