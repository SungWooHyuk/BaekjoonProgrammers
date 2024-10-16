#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
int graph[51][51]; // 1~50의 마을까지.
int cost[51];

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    memset(graph, -1, sizeof(graph));
    memset(cost, 0x3f, sizeof(cost));  // 초기값을 충분히 큰 값으로 설정
    
    // 그래프 초기화
    for(auto &r : road) {
        int u = r[0], v = r[1], w = r[2];
        if(graph[u][v] == -1 || graph[u][v] > w) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    // 우선순위 큐 사용 (비용, 마을)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    cost[1] = 0;

    while(!pq.empty()) {
        int currentCost = pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if(currentCost > cost[from]) continue;

        for(int to = 1; to <= N; ++to) {
            if(graph[from][to] == -1) continue;
            int nextCost = currentCost + graph[from][to];
            if(nextCost < cost[to]) {
                cost[to] = nextCost;
                pq.push({nextCost, to});
            }
        }
    }

    // K 시간 이내 도착 가능한 마을 카운트
    for(int i = 1; i <= N; ++i) {
        if(cost[i] <= K) answer++;
    }
    
    return answer;
}
