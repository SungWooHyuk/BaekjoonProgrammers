#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    queue<pair<int,int>> q;
    vector<vector<char>> v(m, vector<char>(n));
    
    for(int i = 0; i <m; ++i)
        for(int j = 0; j <n; ++j)
            v[i][j] = board[i][j];
    
    bool valid = true;
    
    while(valid){
        valid = false;
        while(!q.empty())
        {
            q.pop();
        }
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(v[i][j] == '0')
                    continue;
                
                if(j+1 < n && v[i][j+1] == v[i][j] &&
                  i+1 < m && v[i+1][j] == v[i][j] &&
                  i+1 < m && j+1 < n && v[i+1][j+1] == v[i][j]) 
                {
                    q.push(make_pair(i,j));
                    q.push(make_pair(i+1,j));
                    q.push(make_pair(i,j+1));
                    q.push(make_pair(i+1,j+1));
                }
            }
        }
    
        while(!q.empty())
        {
            valid = true;
            v[q.front().first][q.front().second] = '0';
            q.pop();
        }
    
        if(!valid)
            break;
    
        for(int i = 0; i < n; ++i)
        {
            for(int j = m-1; j >=0; --j)
            {
                if(v[j][i] == '0')
                {
                    for(int k = j-1; k >= 0; --k)
                    {
                        if(v[k][i] != '0'){
                            swap(v[j][i], v[k][i]);
                            break;
                        }
                    }
                }
            }
        }
        
    }
    
    
    for(int i =0 ; i < m; ++i)
        for(int j = 0; j <n; ++j)
            if(v[i][j] == '0')
                answer++;
    

    return answer;
}