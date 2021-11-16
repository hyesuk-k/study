#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> us;
    // set¿∫ O(1), multiset¿∫ O(logN)
    
    for(const auto& p : participant) {
        us.insert(p);
    }
    
    for(const auto& c : completion) {
        unordered_multiset<string>::iterator it = us.find(c);
        us.erase(it);
    }
    
    answer = *us.begin();
    
    return answer;
}

