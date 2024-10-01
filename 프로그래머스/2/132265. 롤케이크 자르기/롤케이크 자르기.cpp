// 각 조각에 동일한 가짓수의 토핑이 올라가야만 공평한것
// 아 자르고나서 가짓수를 세기
// 처음부터 계속 잘라보고 공평하게 나뉠때의 값을 return 

// 문제의 요는 
// 카운트를 어떻게 셀것인가에 달렸네
// 처음부터 끝까지 잘라볼껀데
// 한번 자를때마다 0~i 랑 i~topping.size() 각각을 비교하기
// 아무래도 중복은 필요없으니까 unordered_set을 사용해서 count를 한다?
// 걱정은 토핑의 길이가 길어서 효율성부분이 걸릴것같음
// unordered_set을 계속계속 만들어서 카운트 카운트 ? -> 첫번째 방법

// 시간초과가 당연히 뜬다.
// for문안에서 작업이 너무 길기때문에 
// 일단 첫번째로 다 돌때까지 기다리는건 사이즈가 너무 크다.
// 함수로 일단 빼보자 -> 약간 빨라지긴했지만 역시 실패

// 이 방법말고 아예 다른 방법을 찾아봐야할듯
// 아 지금 계속 새로 만들고 clear를 반복하니까 이걸 줄이는
// 일단 map에 해당 int가 몇개있는지 체크해
// 그리고 0번부터 나가는데 
// 어차피 size가 있으니까
// 

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> m, add_m;
    
    for(auto n : topping)
        m[n]++;
    
    for(int i = 0; i < topping.size(); ++i)
    {
        add_m[topping[i]]++;
        m[topping[i]]--;
        if(m[topping[i]] == 0)
            m.erase(topping[i]);
        
        if(add_m.size() == m.size())
            answer++;
        
    }
    
    return answer;
}