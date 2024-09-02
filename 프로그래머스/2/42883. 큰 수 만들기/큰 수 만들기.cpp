#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> st; // 숫자를 저장할 스택
    
    for (char digit : number) {
        // 스택이 비어 있지 않고, 현재 문자가 스택의 마지막 문자보다 크고
        // 아직 제거해야 할 숫자(k)가 남아있는 경우
        while (!st.empty() && st.top() < digit && k > 0) {
            st.pop(); // 스택에서 마지막 문자를 제거
            k--;      // 제거해야 할 숫자를 하나 줄임
        }
        st.push(digit); // 현재 문자를 스택에 추가
    }
    
    // 제거할 숫자가 남아있는 경우, 스택의 맨 끝에서부터 제거
    while (k > 0) {
        st.pop();
        k--;
    }
    
    // 스택에 있는 숫자를 문자열로 변환
    while (!st.empty()) {
        answer = st.top() + answer; // 스택에서 문자열로 변환
        st.pop();
    }
    
    return answer;
}