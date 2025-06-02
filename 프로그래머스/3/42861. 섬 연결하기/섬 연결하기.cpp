#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];  // 최대 100개의 섬

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);  // 경로 압축
}

void Union(int a, int b) {
    int rootA = Find(a);
    int rootB = Find(b);
    if (rootA < rootB)
        parent[rootB] = rootA;
    else
        parent[rootA] = rootB;
}

int solution(int n, vector<vector<int>> costs) {
    // 1. 부모 배열 초기화
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    // 2. 비용 기준으로 정렬
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    int answer = 0;
    int edges = 0;

    // 3. 간선 선택 (비용이 낮은 것부터)
    for (const auto& c : costs) {
        int a = c[0], b = c[1], cost = c[2];

        // 사이클이 생기지 않는 경우만 선택
        if (Find(a) != Find(b)) {
            Union(a, b);
            answer += cost;
            edges++;

            if (edges == n - 1) break;  // MST 완성
        }
    }

    return answer;
}
