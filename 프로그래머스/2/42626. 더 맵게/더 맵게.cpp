#include <string>
#include <vector>
#include <queue>
#include <algorithm>
// 일단 계속 낮은 애들을 섞고 섞고 해야함.

using namespace std;
int mix = 0;

int Sum(int first, int second)
{
    mix++;
    return first + ( second * 2);
}

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while(pq.size() > 1)
    {
       int first = pq.top();
        pq.pop();
        
        if(first >= K)
            return mix;
        
        int second = pq.top();
        pq.pop();
        
        int mixNum = first + (second*2);
        pq.push(mixNum);
        mix++;
    }
    
    if(pq.top() >= K)
        return mix;
    else
        return -1;
}