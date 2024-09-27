#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int size = s.size();

    for (int i = 0; i < size; ++i) {
        stack<char> st;
        bool isValid = true;

        // 회전된 문자열을 생성하고 유효성 검사
        for (int j = 0; j < size; ++j) {
            char current = s[(i + j) % size]; // 회전된 문자열

            // 열린 괄호일 경우 스택에 추가
            if (current == '(' || current == '[' || current == '{') {
                st.push(current);
            }
            // 닫는 괄호일 경우
            else {
                if (st.empty()) {
                    isValid = false;
                    break; // 스택이 비어있다면 유효하지 않음
                }
                
                char top = st.top();
                // 짝이 맞는지 확인
                if ((current == ')' && top == '(') ||
                    (current == ']' && top == '[') ||
                    (current == '}' && top == '{')) {
                    st.pop(); // 짝이 맞으면 제거
                } else {
                    isValid = false;
                    break; // 짝이 맞지 않으면 유효하지 않음
                }
            }
        }

        // 스택이 비어있으면 유효한 문자열
        if (isValid && st.empty()) {
            answer++;
        }
    }

    return answer;
}
