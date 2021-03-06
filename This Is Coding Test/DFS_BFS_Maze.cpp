#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;

int maze[201][201];
int n, m;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int xt = q.front().first;
		int yt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xt + dx[i];
			int ny = yt + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (maze[nx][ny] == 0) continue;

			if (maze[nx][ny] == 1) {
				maze[nx][ny] = maze[xt][yt] + 1;
				q.push({ nx, ny });
			}
		}
	}

	return maze[n - 1][m - 1];
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			scanf_s("%1d", &maze[i][k]);
		}
	}

	cout << dfs(0, 0);
    return 0;
}

