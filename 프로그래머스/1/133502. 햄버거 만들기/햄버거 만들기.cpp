#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    stack<int> s;
    int answer = 0;
    
    for(int i = 0; i < ingredient.size(); ++i)
    {
        s.push(ingredient[i]);  // 무조건 push

        // 스택의 크기가 4 이상일 때만 패턴 확인
        if(s.size() >= 4) {
            // 최근 4개의 원소가 1-2-3-1인지 확인
            int third = s.top(); s.pop();
            int second = s.top(); s.pop();
            int first = s.top(); s.pop();
            int bread = s.top(); s.pop();
            
            if(bread == 1 && first == 2 && second == 3 && third == 1) {
                answer++;  // 햄버거 하나 완성
            } else {
                // 패턴이 아니면 다시 스택에 원소들을 쌓아놓음
                s.push(bread);
                s.push(first);
                s.push(second);
                s.push(third);
            }
        }
    }
    
    return answer;
}

