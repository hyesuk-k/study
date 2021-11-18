#include <iostream>
#include <cmath>

using namespace std;
int main() {
  int n;
  cin >> n;
  
  int ret = 0;
  for (int i = 0 ; i < n ; i++) {
    int num;
    cin >> num;

    bool isPrime;
    if (num == 1) isPrime = false;
    else isPrime = true;

    for (int j = 2 ; j <= sqrt(num) ; j++) {
      if (num % j == 0) {
        isPrime = false;
        break;
      }
    }
    
    if (isPrime) {
      ret++;
    }
  }

  cout << ret << "\n";

  return 0;
}
