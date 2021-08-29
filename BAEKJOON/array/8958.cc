#include <iostream>
#include <cstring>

int main() {
  int caseNum;
  char ox[80];
  int ret, acc;

  std::cin >> caseNum;

  for (int i = 0; i < caseNum ; i++) {
    ret = acc = 0;
    memset(ox, 0, sizeof(ox));
    scanf("%s", ox);
    for (uint32_t j = 0 ; j < strlen(ox) ; j++) {
      if ((ox[j] == 'O') || (ox[j] == 'o')) {
        acc += 1;
        ret += acc;
      } else {
        acc = 0;
      }
    }

    printf("%d\n", ret);
  }
  return 0;
}
