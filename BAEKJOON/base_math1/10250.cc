#include <iostream>

using namespace std;
int main() {
  int t; // 테스트 데이터

  cin >> t;

  for (int i = 0 ; i < t ; i++) {
    int h, w, n;
    // 호텔 층 수, 각 층의 방 수, 몇 번째 손님인지
    cin >> h >> w >> n;
    
    int y = n % h;
    int x = n / h;
    if (y == 0) {
      y = h;
    } else {
      x += 1;
    }
    y = y * 100;

    int ret = y + x;

    cout << ret << endl;
  }

  return 0;
}
