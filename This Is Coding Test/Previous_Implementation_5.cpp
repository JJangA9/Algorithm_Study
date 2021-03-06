
#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int board[101][101];
queue<pair<int, char>> change;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

int snakeMove(int n) {
	queue<pair<int, int>> body;
	queue<pair<int, int>> temp;
	int currentDir = 1, i;
	int flag = 1;

	body.push({1, 1}); // 뱀 위치 초기화

	for (i = 1; i <= 10000; i++) {

		// 뱀 머리 현재 위치
		int x = body.back().first + dx[currentDir];
		int y = body.back().second + dy[currentDir];

		//몸을 만나면 끝나기
		temp = body;
		while (!temp.empty()) {
			int tempx = temp.front().first;
			int tempy = temp.front().second;
			temp.pop();

			if (x == tempx && y == tempy) {
				flag = 0;
				break;
			}
		}

		if (x < 1 || x > n || y < 1 || y > n || flag == 0) {
			//벽이나 몸을 만나면 끝나기
			break;
		}

		body.push({ x, y });

		if (board[x][y] == 0) // 사과가 없다면
			body.pop();
		else 
			board[x][y] = 0;

		//방향을 움직여야 한다면
		if (!change.empty()) {
			if (i == change.front().first) {
				char d = change.front().second;
				change.pop();

				if (d == 'D') currentDir = (currentDir == 3) ? 0 : currentDir + 1;
				else currentDir = (currentDir == 0) ? 3 : currentDir - 1;
			}
		}
	}

	return i;
}

int main()
{
	int n, k, m;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int s;
		char d;
		cin >> s >> d;
		change.push({ s, d });
	}

	cout << snakeMove(n);

    return 0;
}

