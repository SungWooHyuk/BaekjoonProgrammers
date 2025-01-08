#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isSafe(vector<string>& place, int x, int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    visited[x][y] = true;
    
    while(!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int distance = abs(nx - x) + abs(ny - y);
            
            if(nx<0 || ny<0 || nx >=5 || ny >= 5 || visited[nx][ny] || distance > 2)
                continue;
            
            visited[nx][ny] = true;
            
            if(place[nx][ny] == 'P')
                return false;
            
            if(place[nx][ny] == 'O')
                q.push({nx,ny});
        }
    }
    
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
     for (auto& place : places) {
        bool valid = true;

        for (int i = 0; i < 5 && valid; ++i) {
            for (int j = 0; j < 5 && valid; ++j) {
                if (place[i][j] == 'P') {
                    // 사람이 있는 위치에서 거리두기 확인
                    if (!isSafe(place, i, j)) {
                        valid = false;
                    }
                }
            }
        }

        // 거리두기가 지켜졌으면 1, 아니면 0
        answer.push_back(valid ? 1 : 0);
    }

    return answer;
}