#include <string>
#include <vector>

using namespace std;

string str[4] = { "aya", "ye", "woo", "ma" };

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (const string& s : babbling) {
        int pos = 0;
        string lastMatch = "";  // 마지막 매칭된 발음을 저장
        bool isValid = true;
        
        while (pos < s.size()) {
            bool matched = false;
            for (int i = 0; i < 4; ++i) {
                string current = str[i];
                if (s.substr(pos, current.size()) == current) {
                    if (lastMatch == current) {
                        // 연속된 발음이 나오는 경우
                        isValid = false;
                        break;
                    }
                    lastMatch = current;
                    pos += current.size();
                    matched = true;
                    break;
                }
            }
            if (!matched) {
                // 발음을 찾지 못한 경우
                isValid = false;
                break;
            }
        }
        
        if (isValid) {
            ++answer;
        }
    }
    
    return answer;
}