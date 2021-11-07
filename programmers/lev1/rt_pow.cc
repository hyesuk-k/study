#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    double sqrtN = sqrt(n);
    
    if ((sqrtN - (int)sqrtN) == 0) {
        answer = pow((int)sqrtN+1, 2);
    } else {
        answer = -1;
    }
    
    
    return answer;
}


//***
// n�� �ڿ����� ������ ���,
// n+1�� ������ ���ϱ�
// n�� �ڿ����� ������ �ƴ� ���, -1 return

