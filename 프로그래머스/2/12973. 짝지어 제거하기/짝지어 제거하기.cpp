#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    stack<char> st;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            // 짝이 맞으면 스택에서 제거
            st.pop();
        } else {
            // 짝이 안 맞으면 스택에 추가
            st.push(c);
        }
    }

    // 스택이 비어있으면 모두 짝을 맞춘 것
    return st.empty() ? 1 : 0;
}