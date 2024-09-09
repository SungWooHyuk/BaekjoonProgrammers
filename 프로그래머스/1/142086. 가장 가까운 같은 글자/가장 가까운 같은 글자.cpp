#include <string>
#include <vector>

using namespace std;


vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;  // 현재 위치를 추적하는 카운터
    int bpos[26];
    for(int i = 0; i < 26; ++i)
        bpos[i] = -1;
    
    for (auto n : s) {
        int pos = n - 'a';  // 문자의 위치 계산 ('a' -> 0, 'b' -> 1, ...)

        if (bpos[pos % 26] == -1) {  // 방문한 적 없는 경우
            bpos[pos % 26] = cnt;  // 현재 위치 저장
            answer.push_back(-1);  // 방문한 적 없으므로 -1 추가
        } else {
            int temp = bpos[pos % 26];  // 이전 위치 가져옴
            bpos[pos % 26] = cnt;  // 현재 위치로 업데이트
            answer.push_back(cnt - temp);  // 현재 위치와 이전 위치의 차이 추가
        }

        cnt++;
    }
    return answer;
}