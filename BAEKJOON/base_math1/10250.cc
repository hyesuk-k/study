#include <iostream>

using namespace std;
int main() {
  int t; // �׽�Ʈ ������

  cin >> t;

  for (int i = 0 ; i < t ; i++) {
    int h, w, n;
    // ȣ�� �� ��, �� ���� �� ��, �� ��° �մ�����
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
