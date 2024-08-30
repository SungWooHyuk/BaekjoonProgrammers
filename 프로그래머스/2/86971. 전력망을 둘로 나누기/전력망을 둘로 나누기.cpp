// n개의 송전탑이 전선을 통해서 하나의 트리
// n, wires
// 송전탑은 2 <= n <= 100
// wires는 길이가 n-1
// 1 <= v1 < v2 <= n
// 9개면 전선은 8개

// 만약 2차원 배열로 표현한다고 하면?
// 그래프는 [n-1][n-1]이 되겠고
// 예시 3을 그래프로 처리한다면

// 0 1 0 0 0 0
// 1 0 0 0 0 1
// 0 0 0 0 0 0
// 0 0 1 1 1 0
// 0 0 0 1 0 1
// 0 1 0 0 1 0

// 그래프는 감이 안오니 다른걸로 찾아보자

// 트리를 직접 만드는건??
//          [1]
//      [2]     [3]     
//  [7]      [7]   [4]
//               [6]  [5]
//             [7]

// 트리는 더 애매하네.. 그러면 연결되는걸 어떻게 파악하지
// [1] - 2 = 1
// [2] - 7 1 = 2
// [3] - 7 4 = 2
// [4] - 5 3 = 2
// [5] - 4 = 1
// [6] - 7 = 1
// [7] - 2 3 6 = 3
// 7-3이 끊기면???
// [1] - 2 = 1
// [2] - 7 1 = 2
// [3] - 4 = 2

// 답 보기전까지 한것
// DFS를 만들어서 연결된것들(결국엔 다 이어져있어서) 을 타고 들어가면서 또 다른 DFS 전에 조건을 검색해서 업데이트 해주고
// 모든 경우의수를 다 판단하면 return - 종료조건 - 을 해줘서 마무리 계획 방문여부는 중요하지않음.

#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int cnt = 0;
bool visit[101];

void DFS(vector<vector<int>>& wires, int num)
{
    cnt++;
    visit[num] = true;
    
    for(int i = 0; i < wires[num].size(); ++i)
    {
        if(!visit[wires[num][i]])
            DFS(wires, wires[num][i]);
    }
}
int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for(int i = 0; i < n-1; ++i)
    {
        vector<vector<int>> v(n+1, vector<int>());
        memset(visit, 0, sizeof(visit));
        cnt =0;
        
        for(int j = 0; j < n-1; ++j)
        {
            if(i==j)
                continue;
            else
            {
                v[wires[j][0]].push_back(wires[j][1]);
                v[wires[j][1]].push_back(wires[j][0]);
            }
        }
        
        DFS(v,1);
        if(abs(cnt - abs(n-cnt)) <= answer)
            answer = abs(cnt - abs(n-cnt));
        
    }
    
    return answer;
}

// 문제의 답을 보니 일단 서로 연결되어있으면 둘이 같이 묶어줘야하며, 전체를 돌아볼때
// 이제 조건을 다르게 줘야하니 이어진곳 즉, i==j continue 이 부분이 매우 컸다.
// 그 후 나머지는 내가 생각한 조건과 같았다. 