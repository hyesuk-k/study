#include <iostream>
#include <string>

using namespace std;

#define NUM_OF_ALPHABET 26

int main() {
  string S;

  cin >> S;

  string alpha = "abcdefghijklmnopqrstuvwxyz";

  for (uint32_t i = 0 ; i < alpha.length() ; i++) {
    cout << (int)S.find(alpha[i]) << " ";    
  }

  return 0;
}
