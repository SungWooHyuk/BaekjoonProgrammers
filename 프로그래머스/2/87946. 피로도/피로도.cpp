#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[8] { false, };
int answer = 0;

void DFS(int k, int s, vector<vector<int>> dungeons)
{
    if(answer < s) answer = s;
    
    for(int i = 0; i < dungeons.size(); ++i)
    {
        if(dungeons[i][0] <= k && visited[i] == false)
        {
            visited[i] = true;
            DFS(k - dungeons[i][1], s+1, dungeons);
            visited[i] = false;
            
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    DFS(k, 0, dungeons);
    return answer;
}