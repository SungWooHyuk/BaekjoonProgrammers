#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visit[1001]{ false, };
bool visited[1001]{ false, };
int graph[1001][1001] = {0,};
vector<int> dfs;
vector<int> bfs;

void DFS(int s, int vertex)
{
	visit[s] = true; // 방문체크
	dfs.push_back(s);

	if (dfs.size() == vertex) // 종료조건
		return;

	for (int i = 1; i <= vertex; ++i)
	{
		if (graph[s][i] == 1 && !visit[i])
		{
			DFS(i, vertex);
		}
	}
}

void BFS(int s, int vertex)
{
	visited[s] = true;
	bfs.push_back(s);

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int num = q.front();
		q.pop();

		for (int i = 1; i <= vertex; ++i) {
			if (graph[num][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;  // 방문 체크
				bfs.push_back(i);
			}
		}
	}
}

int main()
{
	int n, m, v;

	cin >> n >> m >> v;

	for (int i = 0; i < m; ++i)
	{
		int to, from;
		cin >> to >> from;

		graph[to][from] = 1;
		graph[from][to] = 1;
	}

	DFS(v, n);
	BFS(v, n);

	for (auto n : dfs)
		cout << n << ' ';

	cout << endl;

	for (auto n : bfs)
		cout << n << ' ';

	cout << endl;
}