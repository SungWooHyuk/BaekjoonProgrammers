#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int dx[4] {-1,1,0,0};
int dy[4] {0,0,1,-1};
bool visited[101][101] {false,};

int BFS(vector<vector<int>>& vec, vector<string>& b, vector<vector<bool>>& b_vec, pair<int,int>& p)
{
    b_vec[p.first][p.second] = true;
    queue<pair<int,int>> q;
    q.push(p);
    while(!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
       
        for(int i = 0; i < 4; ++i)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];
            if(rx < 0 || ry < 0 || rx >= vec.size() || ry >= vec[0].size() || b[rx][ry] == 'D')
            {
                // 그냥 못 움직임
            }
            else // 이게 아니라면 
            {
                while( rx >= 0 && ry >= 0 && rx < vec.size() && ry < vec[0].size() && b[rx][ry] != 'D' )
                {
                    rx += dx[i];
                    ry += dy[i];
                }
                rx -= dx[i];
                ry -= dy[i];

                if(!b_vec[rx][ry])
                {
                    vec[rx][ry] += vec[x][y] + 1;
                    b_vec[rx][ry] = true;
                    if(b[rx][ry] == 'G') // 골인
                    {
                        return vec[rx][ry];
                    }
                    else
                    {
                        q.push({rx,ry});
                    }
                }                
            }
        }
    }
    return -1;
}

int solution(vector<string> board) {
    int row = board[0].size();
    int col = board.size();
    pair<int,int> start;
    for(int i = 0; i < col; ++i)
    {
        for(int j = 0; j < row; ++j)
            if(board[i][j] == 'R')
                start = {i, j};
    }

    vector<vector<int>> v(col, vector<int>(row, 0));    
    vector<vector<bool>> b_v(col, vector<bool>(row, false));

    return BFS(v, board, b_v, start);
}