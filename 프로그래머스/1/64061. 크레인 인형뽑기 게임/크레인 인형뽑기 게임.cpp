#include <string>
#include <vector>
#include <stack>
// N*N
// 격자의 가장 아래 칸부터 쌓여있음
// 0~N-1 row로
// stack
// 같은 모양이면 poppop 해당 배열이 비어이으면 아무일도 X
// 바구니는 모든 인형이 다 들어갈만큼 크다.
// 터진 인형의 개수를 return 
// 0은 빈칸 1~100
// moves는 크레인을 작동시킨배열이고 moves의 크기만큼 움직일것.

// 00000        
// 00000        
// 00500        4
// 02402        2
// 05131        4
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    vector<vector<int>> bo (board.size(), vector<int>(board.size(), 0));
    
    for(int i = 0; i < board.size(); ++i)
        for(int j = 0; j < board[i].size(); ++j)
            bo[j][i] = board[i][j];
    
    for(int i = 0; i < moves.size(); ++i)
    {
        int col = moves[i]-1;
        
        for(int j = 0; j < bo[col].size(); ++j)
        {
            if(bo[col][j] != 0)
            {
                if(!s.empty())
                {
                    if(s.top() == bo[col][j])
                    {
                        s.pop();
                        answer+=2;
                        bo[col][j] = 0;
                        break;
                    }
                    else
                    {
                        s.push(bo[col][j]);
                        bo[col][j] = 0;
                        break;
                    }
                }
                else
                {
                    s.push(bo[col][j]);
                    bo[col][j] = 0;
                    break;
                }
            }
        }
    }
    
    
    return answer;
}