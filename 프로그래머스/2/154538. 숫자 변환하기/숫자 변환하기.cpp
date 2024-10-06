#include <queue>
#include <vector>

using namespace std;

int solution(int x, int y, int n) {
    
    vector<int> visited(y + 1, -1);
    queue<pair<int, int>> q; // 현재 숫자, 연산 횟수

    q.push({x, 0});
    visited[x] = 0;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // y에 도달하면 연산 횟수 반환
        if (cur == y)
            return cnt;

        // 가능한 다음 단계 (n 더하기, 2 곱하기, 3 곱하기)
        if (cur + n <= y && visited[cur + n] == -1) {
            visited[cur + n] = cnt + 1;
            q.push({cur + n, cnt + 1});
        }
        if (cur * 2 <= y && visited[cur * 2] == -1) {
            visited[cur * 2] = cnt + 1;
            q.push({cur * 2, cnt + 1});
        }
        if (cur * 3 <= y && visited[cur * 3] == -1) {
            visited[cur * 3] = cnt + 1;
            q.push({cur * 3, cnt + 1});
        }
    }

    // y에 도달하지 못했으면 -1 반환
    return -1;
}
