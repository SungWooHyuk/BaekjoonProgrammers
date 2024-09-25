#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// 날짜를 '년도*336 + (달-1)*28 + 일' 형식으로 일수로 변환하는 함수
int trans(string fday) {
    int year = stoi(fday.substr(0, 4));
    int month = stoi(fday.substr(5, 2));
    int day = stoi(fday.substr(8, 2));

    // 년도를 기준으로 일수로 변환
    return year * 336 + (month - 1) * 28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> term_map;
    
    // 오늘 날짜를 일수로 변환
    int today_days = trans(today);

    // terms를 파싱해서 약관 종류별 유효기간(개월)을 저장
    for (const auto& term : terms) {
        char term_type = term[0];
        int duration = stoi(term.substr(2));
        term_map[term_type] = duration * 28; // 28일 기준으로 월을 곱하여 일수로 저장
    }

    // privacies 파싱 및 유효기간 계산
    for (int i = 0; i < privacies.size(); ++i) {
        string privacy_date = privacies[i].substr(0, 10); // 날짜 부분
        char term_type = privacies[i].back(); // 약관 타입 (마지막 문자)

        // 개인정보 수집 날짜를 일수로 변환
        int privacy_days = trans(privacy_date);

        // 해당 약관의 유효기간을 더함
        int expiry_days = privacy_days + term_map[term_type];

        // 유효기간이 지났는지 확인 (현재 날짜와 비교)
        if (expiry_days <= today_days) {
            answer.push_back(i + 1); // 파기해야 할 경우, 1-based 인덱스 추가
        }
    }

    return answer;
}
