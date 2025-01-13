#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int dx[4] {-1, 1, 0, 0};
int dy[4] {0, 0, 1, -1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visited(101, vector<bool>(101, false));
    queue<pair<int,int>> q;

    for(int i = 0; i < maps.size(); ++i)
    {
        for(int j = 0; j < maps[i].size(); ++j)
        {
            if(maps[i][j] != 'X') // 무인도 일때
            {
                int sum = 0;
                if(!visited[i][j]) // 방문여부 체크
                { 
                    visited[i][j] = true;
                    sum += (maps[i][j]) - '0';
                    q.push({i,j});
 
                    while(!q.empty())
                    {
                        pair<int,int> p = q.front();
                        q.pop();
                       
                        for(int k = 0; k < 4; ++k)
                        {
                            int px = p.first + dx[k];
                            int py = p.second + dy[k];
                            
                            if(px < 0 || px >= maps.size() || py < 0 || py >= maps[i].size() || visited[px][py] || maps[px][py] == 'X')
                                continue;
                            
                            visited[px][py] = true;
                            sum += (maps[px][py]) - '0';
                            q.push({px,py});
                        }
                    }
                }
                
                if(sum != 0){
                    answer.push_back(sum);
                    sum = 0;
                }
            }
        }
    }
    if(!answer.empty())
        sort(answer.begin(), answer.end());
    else
        answer.push_back(-1);
    return answer;
}