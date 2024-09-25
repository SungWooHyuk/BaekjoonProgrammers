// 지나다니는 길을 O 장애물 X
// 공원 바운더리 + 장애물 체크 걸리면 다음 명령 수행
#include <string>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> pos;
    
    for(int i = 0; i < park.size(); ++i)
        for(int j = 0; j < park[i].size(); ++j)
            if(park[i][j] == 'S')
                pos = make_pair(i,j);
    
    for(int i = 0; i < routes.size(); ++i)
    {
        char c = routes[i][0];
        int move = routes[i].back() - '0';
        
        // 범위검사
        if(c == 'W'){
            if(pos.second - move < 0)
                continue;
        }
        else if(c== 'N'){
            if(pos.first - move < 0)
                continue;
        }
        else if(c== 'E'){
            if(pos.second + move > park[0].size()-1)
                continue;
        }
        else{
            if(pos.first + move > park.size() -1)
                continue;
        }
    
        int point = 0;
        
        while(move > 0)
        {
            if(c == 'W')
            {
                if(park[pos.first][pos.second-1] != 'X')
                {
                    point++;
                    pos.second -= 1;
                    move--;  
                }
                else{
                    pos.second += point;
                    break;
                }
            }
            else if(c == 'N')
            {
                if(park[pos.first-1][pos.second] != 'X')
                {
                    point++;
                    pos.first -= 1;
                    move--;
                }
                else
                {
                    pos.first += point;
                    break;
                }
            }
            else if(c == 'E')
            {
                if(park[pos.first][pos.second+1] != 'X')
                {
                    point++;
                    pos.second += 1;
                    move--;
                }
                else
                {
                    pos.second -= point;
                    break;
                }
            }
            else
            {
                if(park[pos.first+1][pos.second] != 'X')
                {
                    point++;
                    pos.first += 1;
                    move--;
                }
                else
                {
                    pos.first -= point;
                    break;
                }
            }
        }
    }
    
    answer.push_back(pos.first);
    answer.push_back(pos.second);
    return answer;
}