#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int N = land.size();
    
    for(int i = 1; i < N; ++i)
    {
        for(int j = 0; j < 4; ++j)
            land[i][j] += max({land[i-1][(j+1)%4], land[i-1][(j+2)%4], land[i-1][(j+3)%4]});
    }

    return *max_element(land[N-1].begin(), land[N-1].end());
}