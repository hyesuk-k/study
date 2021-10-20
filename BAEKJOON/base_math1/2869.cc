#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
  double a, b, v;

  cin >> a >> b >> v;

  // 하루에 올라갈 수 있는 길이
  double dayRiseLen = a - b;
  // 올라가야할 총 길이 - 하루 미끄러지는 길이
  double totalRiseLen = v - b;

  double day = totalRiseLen / dayRiseLen;

  cout.precision(0);
  cout << fixed << ceil(day) << endl;
 
  return 0;
}
