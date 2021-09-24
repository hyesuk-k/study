#include <iostream>
#include <string>

using namespace std;

int main() {
  string S, P;
  int R, T;

  cin >> T;

  for (int i = 0 ; i < T ; i++) {
    cin >> R >> S;
    for (uint32_t j = 0 ; j < S.length() ; j++) {
      for (int k = 0 ; k < R ; k++) {
        P += S.at(j);
      }
    }
    cout << P << endl;
    P.clear();
  }

  return 0;
}
