#include <iostream>
#include <cmath>

using namespace std;

int main () {
  uint32_t x, y;
  int t;
  cin >> t;

  for (int i = 0 ; i < t ; i++) {
    cin >> x >> y;

    int distance = y - x - 1;

    int maxK = ceil(sqrt(distance));
    cout << maxK << endl;
  }

  return 0;
}

/*
 풀이

  distance = y - x;
  caseNum : 이동 횟수 (최소)
  maxK : k의 최대값

  > 규칙을 찾아보기

  |d |CN|maxK|etc|
  |1 |1 |1   |1  |
  |2 |2 |1   |1 1|
  |3 |3 |1   |111|
  |4 |3 |2   |maxK가 2로 변경됨, 121|
  |5 |4 |2   |caseNum이 1 증가, 1211|
  |6 |4 |2   |1221|
  |7 |5 |2   |caseNum이 1 증가 12211|
  |8 |5 |2   |12221|
  |9 |5 |3   |maxK가 3으로 변경, 12321|
  |10|6 |3   |caseNum이 1 증가, 123211|
  |11|6 |3   |123221|
  |12|6 |3   |123321|
  |13|7 |3   |caseNum이 1 증가, 1233211|
  |14|7 |3   |1233221|
  |15|7 |3   |1233321|
  |16|7 |4   |maxK가 4로 변경, 1234321|
  |17|8 |4   |caseNum이 1 증가, 12343211|
  ...

  >> square root가 튀어나옴...ㄷㄷㄷ

  root 1, 2, 3        >> about 1
  root 4, 5, 6, 7, 8  >> about 2
  root 9, 10, 11 ~ 15 >> about 3
  root 16 ~ 24        >> about 4

  maxK = ceil(sqrt(distance)); 
 
  규칙 1. maxK는 sqrt(d) 이하.
  규칙 2. sqrt(d)가 이전의 sqrt(d-1)과 다를 때, n이 +1이 됨
*/
