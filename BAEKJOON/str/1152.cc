#include <iostream>
#include <string>

using namespace std;

int main() {
    string sentence;
    
    getline(cin, sentence);

    if(sentence.empty()) {
        cout << "0";
        return 0;
    }

    int count = 1;
    for (uint32_t i = 0 ; i < sentence.length(); i++) {
      if (sentence[i] == ' ') {
        count++;
      }
    }

    if (sentence[0] == ' ') count--;
    if (sentence[sentence.length()-1] == ' ') count--;

    cout << count << endl;
    return 0;
}

