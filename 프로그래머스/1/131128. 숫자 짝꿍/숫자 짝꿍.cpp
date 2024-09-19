#include <string>
#include <vector>
#include <algorithm>
// 임의의 자리에서 공통으로 나타나는 정수들을 이용하여 만들 수 있는 가장 큰 정수를 두 수의 짝꿍
// 공통.
// 3403
// 13203

// 3 0 3

// 같은게 나오면 제거할것
// 하나씩 비교를 해보는게 제일 좋다 
// 그런데 길이가 3,000,000 까지 가니까 다 돌려보긴 좀 그런디 애초에
// sort를 진행해서 이제 A의 가장 큰 수가 B 의 가장 작은수면 종료
// 아 짝꿍. 해쉬맵을 사용하자.
#include <iostream>
#include <unordered_map>
using namespace std;

string solution(string X, string Y) {
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    for(auto n : X)
        m1[n - '0']++;
    for(auto n : Y)
        m2[n- '0']++;
    
    string answer = "";
    for(int i = 9; i >= 0; --i)
    {
        while(m1[i] > 0 && m2[i] > 0){
            answer += to_string(i);
            m1[i]--;
            m2[i]--;
        }
    }
    
    if(answer == "")
        return "-1";
    else if(answer[0] == '0')
        return "0";
    
    return answer;
}