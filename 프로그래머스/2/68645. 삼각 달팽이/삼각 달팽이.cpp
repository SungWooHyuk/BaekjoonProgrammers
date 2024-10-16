#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> graph(n, vector<int>(n, -1));
    
    bool ch = false;
    int cnt = 0;
    int p_d = 0, p_r = 0;
    int step = 0;
    int sum = 0;
    
    for(int i = 1; i <= n; ++i)
        sum += i;

    while(1)
    {
        cnt++;
        if(step == 0)
        {
            graph[p_d][p_r] = cnt;
            
            if(p_d >= n-1 || graph[p_d+1][p_r] != -1){
                step = 1;
                p_r++; // 31
            }
            else
                p_d++;
        }
        else if(step == 1)
        {
            graph[p_d][p_r] = cnt;
            if(p_r >= n-1 || graph[p_d][p_r+1] != -1){
                p_r -=1;
                p_d -=1;
                step = 2;
            }
            else
                p_r++;
        }
        else // 2
        {
           
           if(graph[p_d][p_r] == -1){
                graph[p_d][p_r] = cnt;
                p_d--;
                p_r--;
               if(graph[p_d][p_r] != -1)
               {
                   p_d += 2;
                    p_r += 1;
                    step = 0;
               }
           }
           
        }
        
        
        if(cnt == sum)
            break;
    }
    
    
    for(int i = 0; i < graph.size(); ++i)
    {
        for(int j = 0; j < graph[i].size(); ++j)
            if(graph[i][j] != -1)
                answer.push_back(graph[i][j]);
    }
    
    return answer;
}