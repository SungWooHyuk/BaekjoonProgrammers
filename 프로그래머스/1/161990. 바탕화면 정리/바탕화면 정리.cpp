#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 세로,가로
// . # 
// S ~ E로 드래그 Start End 드래그한거리 절대값
// S는 좌측 최대 위로 최대 (위,좌)
// E는 우측 최대 아래로 최대 (아래, 우)

vector<int> solution(vector<string> wallpaper) {
    
    vector<vector<int>> v(wallpaper.size(), vector<int>(wallpaper[0].size(), 0));
    for(int i = 0; i < wallpaper.size(); ++i)
    {
        int cnt = 0;
        for(auto n : wallpaper[i])
        {
            if(n == '#')
                v[i][cnt] = 1;

            cnt++;
        }
    }
    
    int top = 99999;
    int left = 99999;
    int down = -1;
    int right = -1;
    
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v[i].size(); ++j)
        {
            if(v[i][j] != 0) // 있을 때 + 가장 처음발견은 top
            {
                if(i < top) // 최소 
                    top = i; 
                
                if(j < left) // 최소
                    left = j;
                
                if(i > down)
                    down = i;
                
                if(j > right)
                    right = j;
            }
        }
    }
    vector<int> answer;
    answer.push_back(top);
    answer.push_back(left);
    answer.push_back(down+1);
    answer.push_back(right+1);
    return answer;
}