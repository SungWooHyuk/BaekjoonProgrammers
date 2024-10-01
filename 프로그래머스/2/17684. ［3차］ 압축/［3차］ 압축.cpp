#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    unordered_map<string, int> m;
    // A부터 Z까지 초기화
    for (char c = 'A'; c <= 'Z'; ++c) {
        m[string(1, c)] = c - 'A' + 1; 
    }

    vector<int> answer; // 결과를 저장할 벡터
    string current; // 현재 문자열
    int index = 27; // 다음 색인 번호

    for (int i = 0; i < msg.size();) {
        current += msg[i]; // 현재 문자 추가

        // 현재 문자열이 사전에 존재하는지 확인
        if (m.find(current) != m.end()) {
            // 존재하는 경우 다음 문자로 진행
            i++;
        } else {
            // 존재하지 않는 경우
            answer.push_back(m[current.substr(0, current.size() - 1)]); // 마지막 문자 제거한 이전 문자열 색인 기록
            m[current] = index++; // 현재 문자열을 사전에 추가
            current.clear(); // 현재 문자열 비우기
        }
    }

    // 마지막 남은 문자열 처리
    if (!current.empty()) {
        answer.push_back(m[current]);
    }

    return answer;
}
