#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int r = 0 ; r < commands.size() ; r++) {
        vector<int> v;
        
        for (int c = commands[r][0] - 1 ; c < commands[r][1] ; c++) {
            v.push_back(array[c]);
        }
        
        sort(v.begin(), v.end());
        
        answer.push_back(v[commands[r][2] - 1]);
    }
    
    return answer;
}
