#include <string>
#include <vector>
#include <queue>
// 야근을 시작한 시점에서 남은 일의 작업량을 제곱
// N시간 동안 야근 피로도를 최소화

// [4,3,3] , 4 -> [2, 2, 2] 
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for(auto num : works)
        pq.push(num); // 내림차순으로 넣어준다.
    
    while(n>0 && !pq.empty())
    {
        int k = pq.top();
        pq.pop();
        if(k > 1)
            pq.push(k-1); // 1내려주기
        n--;
    }
    
    while(!pq.empty())
    {
        int num = pq.top();
        answer += (num * num);
        pq.pop();
    }
    return answer;
}