#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

// 시간 차이를 분 단위로 계산하는 함수
int Ch(string s, string e) {
    int start_h = stoi(s.substr(0, 2));
    int start_m = stoi(s.substr(3, 2)); // ":" 이후 분 부분
    int end_h = stoi(e.substr(0, 2));
    int end_m = stoi(e.substr(3, 2)); // ":" 이후 분 부분
    return (end_h - start_h) * 60 + (end_m - start_m);
}

// 멜로디에서 # 처리 함수
string ReplaceSharp(string melody) {
    unordered_map<string, string> sharp_map = {
        {"C#", "H"}, {"D#", "I"}, {"F#", "J"},
        {"G#", "K"}, {"A#", "L"}, {"B#", "M"}
    };
    for (auto& pair : sharp_map) {
        size_t pos = 0;
        while ((pos = melody.find(pair.first, pos)) != string::npos) {
            melody.replace(pos, 2, pair.second);
            pos += 1;
        }
    }
    return melody;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int max_duration = 0; // 가장 긴 재생 시간 저장용 변수

    // 입력 멜로디 # 처리
    m = ReplaceSharp(m);

    for (auto info : musicinfos) {
        // 쉼표로 문자열 파싱
        stringstream ss(info);
        string start_time, end_time, title, melody;
        getline(ss, start_time, ',');
        getline(ss, end_time, ',');
        getline(ss, title, ',');
        getline(ss, melody, ',');

        // 재생 시간 계산
        int length = Ch(start_time, end_time);

        // 멜로디 # 처리
        melody = ReplaceSharp(melody);

        // 재생된 멜로디 생성
        string played_melody = "";
        for (int i = 0; i < length; ++i) {
            played_melody += melody[i % melody.size()];
        }

        // 멜로디에 입력된 m이 포함되어 있는지 확인
        if (played_melody.find(m) != string::npos) {
            if (length > max_duration) { // 가장 긴 재생 시간의 곡 선택
                max_duration = length;
                answer = title;
            }
        }
    }

    return answer.empty() ? "(None)" : answer;
}
