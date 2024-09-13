// 같은 색깔로 칠해진 칸의 개수.
// 상하좌우 체크
// 
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[4] { -1, 1 , 0 , 0};
int dy[4] { 0, 0, -1, 1};
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    string color = board[h][w];

    for(int i = 0; i < 4; ++i)
    {
        int x = w + dx[i];
        int y = h + dy[i];

        if(x >= 0 && x < board.size() && y >= 0 && y < board.size())
        {
            if(color.compare(board[y][x]) == 0)
                answer++;
        }
     
    }
    return answer;
}