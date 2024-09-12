#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    vector<char> alpha;
    
    // 'a'부터 'z'까지 알파벳 중에서 skip에 포함되지 않은 문자만 남김
    for (char c = 'a'; c <= 'z'; ++c) {
        if (skip.find(c) == string::npos) {
            alpha.push_back(c);
        }
    }

    int size = alpha.size();  // 남은 알파벳의 개수

    // s의 각 문자를 변환
    for (auto& c : s) {
        int pos = find(alpha.begin(), alpha.end(), c) - alpha.begin();  // 현재 문자 위치 찾기
        int newPos = (pos + index) % size;  // index만큼 이동 후 알파벳 범위 내로 조정
        c = alpha[newPos];  // 새로운 문자로 변환
    }
    
    return s;
}
