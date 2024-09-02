#include <iostream>

using namespace std;
int solution(int n)
{
    string num_str = std::to_string(n);
    int answer = 0;
    for (char c : num_str) {
        answer += (c - '0');  // 문자 '0'을 빼면 해당 숫자의 정수값이 나옴
    }

    return answer;
}