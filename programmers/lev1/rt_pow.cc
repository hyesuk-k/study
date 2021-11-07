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
// n이 자연수의 제곱인 경우,
// n+1의 제곱을 구하기
// n이 자연수의 제곱이 아닌 경우, -1 return

