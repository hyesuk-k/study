#include <iostream>

using namespace std;

int main() {
  int cNum;
  int students;
  float div;

  cin >> cNum;

  for (int i = 0 ; i < cNum ; i++) {
    cin >> students;
    int *arr = new int[students];

    for (int j = 0; j < students ; j++) {
      cin >> arr[j];
    }
    int sum = 0;
    for (int j = 0 ; j < students ; j++) {
      sum += arr[j];
    }
    div = sum/students;
    
    float count = 0.0;

    for (int j = 0 ; j < students; j++) {
      if (arr[j] > div) {
        count++;
      }
    }

    float ret = (float)(count / students);

    printf("%.3f%%\n", ret*100);
    delete arr;
  }

  return 0;

}
