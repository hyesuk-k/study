#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    int j = 0;
    for (int i = 0 ; i < participant.size() ; i++, j++) {
        if(participant[i] != completion[j]) {
            answer += participant[i];
            j--;
        }
    }
    
    return answer;
}
