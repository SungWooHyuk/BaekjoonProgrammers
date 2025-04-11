#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    
int solution(vector<int> sticker)
{
    int n = sticker.size();
    if(n==1) return sticker[0];
    
    //case1 : 0번째 스티커를 뜯었을 때 -> N-1 사용불가
    vector<int> dp1(n,0);
    dp1[0] = sticker[0]; // 0을 뜯었으니까
    dp1[1] = max(sticker[0], sticker[1]); // 둘 중 큰거 떼기
    for(int i = 2; i < n - 1; ++i)
        dp1[i] = max(dp1[i-1], dp1[i-2] + sticker[i]);
    
    //case2 : 0번째 스티커를 안 뜯고 -> 1 ~ N-1 사용
    vector<int> dp2(n,0);
    dp2[1] = sticker[1];
    for(int i = 2; i < n; ++i)
        dp2[i] = max(dp2[i-1], dp2[i-2]+sticker[i]);
    
    return max(dp1[n-2], dp2[n-1]);
}