#include <string>
#include <vector>

// 첫 글자는 x
// -> 읽을껀데, x와 x가 아닌 다른 글자들
// 처음으로 같아지는순간 멈추고 분리
// s에서 분리한 문자열을 빼고 남은 부분 반복
// size() 만큼 갔으면 종료
// 다른 상태에서 끝까지 갔으면 종료

//
using namespace std;

int solution(string s) {
    char x = ' ';
    int cnt = 0;
    int answer = 0;
    for(auto c : s)
    {
        if(x == ' '){
            x = c;
            cnt++; // 카운트 
        }
        else if (x != c) // 최근꺼랑 다음꺼랑 같지않았을때
        {
            cnt--; // 줄이고
            if(cnt == 0) // 빼야되는지 체크
            {
                answer+=1;
                x = ' ';
            }
        }
        else // 같다면
            cnt++;
    }
    
    if(cnt != 0)
        answer++;
    
    return answer;
}