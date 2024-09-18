#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// "mm:ss" 형식의 시간을 초로 변환하는 함수
int timeToSeconds(const string& time) {
    int minutes = stoi(time.substr(0, 2));
    int seconds = stoi(time.substr(3, 2));
    return minutes * 60 + seconds;
}

// 초를 "mm:ss" 형식으로 변환하는 함수
string secondsToTime(int total_seconds) {
    int minutes = total_seconds / 60;
    int seconds = total_seconds % 60;
    string mm = (minutes < 10) ? "0" + to_string(minutes) : to_string(minutes);
    string ss = (seconds < 10) ? "0" + to_string(seconds) : to_string(seconds);
    return mm + ":" + ss;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int videoLength = timeToSeconds(video_len);
    int position = timeToSeconds(pos);
    int opStart = timeToSeconds(op_start);
    int opEnd = timeToSeconds(op_end);

    for (const string& command : commands) {
        // 오프닝 구간에 있으면 오프닝 끝으로 이동
        if (opStart <= position && position <= opEnd) {
            position = opEnd;
        }

        if (command == "next") {
            position = min(position + 10, videoLength);  // 10초 후로 이동, 비디오 길이 초과하지 않음
        } else if (command == "prev") {
            position = max(position - 10, 0);  // 10초 전으로 이동, 0초 미만 방지
        }

        // 다시 오프닝 구간에 들어갔으면 오프닝 끝으로 이동
        if (opStart <= position && position <= opEnd) {
            position = opEnd;
        }
    }

    return secondsToTime(position);
}
