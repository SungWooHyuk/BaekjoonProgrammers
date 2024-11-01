#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

// 상하좌우 네 방향을 나타내는 배열
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[101][101]; // 전역 배열 사용, 필요할 때마다 초기화

int cnt;  // 각 영역의 크기를 세기 위한 변수

void DFS(int row, int col, vector<vector<int>>& map, pair<int, int> p, int color) {
    int x = p.first;
    int y = p.second;

    // 영역을 벗어나거나 이미 방문했거나, 같은 색이 아닌 경우 리턴
    if (x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || map[x][y] != color) {
        return;
    }

    visited[x][y] = true; // 방문 표시
    cnt++; // 현재 영역 크기 증가

    // 상하좌우 탐색
    for (int i = 0; i < 4; ++i) {
        int px = x + dx[i];
        int py = y + dy[i];
        DFS(row, col, map, {px, py}, color);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer;
    int num = 0;       // 총 영역 수
    int max_cnt = 0;   // 가장 큰 영역의 크기
    
    // visited 배열 초기화
    fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(bool), false);

    // 모든 셀에 대해 DFS 수행
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j] && picture[i][j] != 0) { // 새로운 영역일 때만 DFS 수행
                cnt = 0; // 새로운 영역 시작 시 cnt 초기화
                DFS(m, n, picture, {i, j}, picture[i][j]);
                num++; // 영역 수 증가
                max_cnt = max(max_cnt, cnt); // 최대 영역 크기 갱신
            }
        }
    }

    answer.push_back(num);    // 총 영역의 수
    answer.push_back(max_cnt); // 가장 큰 영역의 크기
    return answer;
}
