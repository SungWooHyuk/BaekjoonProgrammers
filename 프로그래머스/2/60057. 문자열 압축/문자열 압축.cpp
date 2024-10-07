#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(string s) {
    if (s.empty()) return 0; // 빈 문자열 처리
    int answer = INT32_MAX; // 최대 정수로 초기화

    for (int i = 1; i <= s.size() / 2; ++i) { // i는 1부터 s의 절반까지
        string compressed = ""; // 압축된 문자열
        string prev = s.substr(0, i); // 첫 번째 패턴
        int count = 1; // 카운트 초기화

        for (int j = i; j < s.size(); j += i) { // j는 i만큼 증가
            string curr = s.substr(j, i); // 현재 패턴
            if (curr == prev) {
                count++; // 패턴이 같으면 카운트 증가
            } else {
                // 패턴이 다르면 압축 처리
                if (count > 1) {
                    compressed += to_string(count); // 카운트 추가
                }
                compressed += prev; // 이전 패턴 추가
                prev = curr; // 현재 패턴을 이전 패턴으로 업데이트
                count = 1; // 카운트 초기화
            }
        }
        // 마지막 패턴 처리
        if (count > 1) {
            compressed += to_string(count);
        }
        compressed += prev; // 마지막 패턴 추가

        answer = min(answer, (int)compressed.size()); // 최솟값 업데이트
    }
    return answer == INT32_MAX ? 1 : answer; // 압축된 길이 반환
}
