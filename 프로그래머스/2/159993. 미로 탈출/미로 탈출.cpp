#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// BFS 함수: 시작점에서 특정 목적지까지 거리 계산
int BFS(int _x, int _y, char _dest, const vector<string>& _maps) {
    int n = _maps.size();
    int m = _maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1)); // 거리 저장 배열
    queue<pair<int, int>> q;

    dist[_x][_y] = 0;
    q.push({_x, _y});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 체크 및 방문 가능 여부 확인
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || _maps[nx][ny] == 'X' || dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[x][y] + 1;

            // 목적지에 도달하면 거리 반환
            if (_maps[nx][ny] == _dest) 
                return dist[nx][ny];

            q.push({nx, ny});
        }
    }

    return -1; // 목적지에 도달할 수 없는 경우
}

int solution(vector<string> maps) {
    int s_x, s_y, l_x, l_y, e_x, e_y;

    // 시작점(S), 레버(L), 출구(E) 좌표 찾기
    for (int i = 0; i < maps.size(); ++i) {
        for (int j = 0; j < maps[i].size(); ++j) {
            if (maps[i][j] == 'S') {
                s_x = i;
                s_y = j;
            } else if (maps[i][j] == 'L') {
                l_x = i;
                l_y = j;
            } else if (maps[i][j] == 'E') {
                e_x = i;
                e_y = j;
            }
        }
    }

    // S -> L 거리 계산
    int toLever = BFS(s_x, s_y, 'L', maps);
    if (toLever == -1) 
        return -1;

    // L -> E 거리 계산
    int toExit = BFS(l_x, l_y, 'E', maps);
    if (toExit == -1) 
        return -1;

    // 총 거리 반환
    return toLever + toExit;
}
