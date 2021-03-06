
#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int map[8][8]; // 초기 맵
int temp[8][8]; //벽 설치한 후 맵

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = {0, 1, 0, -1};
int result;

void virus(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (temp[nx][ny] == 0) {
				temp[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}

//현재 맵에서 안전 영역 크기 계산
int getScore() {
	int score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				score += 1;
			}
		}
	}
	return score;
}

void dfs(int count) {
	if (count == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 2) {
					virus(i, j);
				}
			}
		}

		result = max(result, getScore());
		return;
	}

	//빈공간에 울타리 설치
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				count += 1;
				dfs(count);
				map[i][j] = 0;
				count -= 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
		}
	}

	dfs(0);

	cout << result;

    return 0;
}

