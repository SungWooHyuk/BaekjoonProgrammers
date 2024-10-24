#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    int left = 0;
    int right = distance;
    
    while(left <= right)
    {
        int mid = (left+right)/2;
        int count = 0; // 지울 바위 수
        int last_position = 0;
        
        for(auto rock : rocks)
        {
            if(rock - last_position < mid)
                count++;
            else
                last_position = rock;
        }
        
        if(distance - last_position < mid)
            count++;
        
        if(count <= n)
        {
            answer = mid; // 최솟값 유지
            left = mid+1; // left움직여서 더 큰 거리 시도
        }
        else
            right = mid-1; // 더 제거해야하니까 거리를 줄여본다.
    }
    return answer;
}