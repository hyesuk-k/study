#include <iostream>
#include <cmath>

using namespace std;
int main() {
  double a, b, v;

  cin >> a >> b >> v;

  double total = ceil(v/a);
  double day = a * total;
  double night = b * total;

  if ((day - night) >= v) {
    cout << total << endl;
    return 0;
  }

  while (true) {
    total++;

    day = a * total;
    if ((day - night) >= v) {
      cout << total << endl;
      break;
    }
    night = b * total;
  }
 
  return 0;
}
