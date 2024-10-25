#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

bool visit[20001] {false,};
int graph[20001][20001];

int deep = 0;
int answer = 0;
void BFS(int n, vector<vector<int>>& edge, int depth)
{
    visit[n] = true;
    depth+=1;
    
    queue<pair<int,int>> q;
    q.push(make_pair(n,depth));
    
    while(!q.empty())
    {
        int n = q.front().first;
        int d = q.front().second;
        
        if(d == deep)
            answer++;
        else
        {
            deep = max(d, deep);
            answer = 1;    
        }
        
        q.pop();
        
        for(int i = 0; i < 20001; ++i)
        {
            if(graph[n][i] == 1 && !visit[i]){
                q.push(make_pair(i, d+1));
                visit[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {

    for(int i = 0; i < edge.size(); ++i)
    {
        graph[edge[i][0]][edge[i][1]] = 1;
        graph[edge[i][1]][edge[i][0]] = 1;
    }
    
    BFS(1, edge, 0);
    
    return answer;
}