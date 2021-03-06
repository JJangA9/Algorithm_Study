#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int forest[501][501];
int check[501][501];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n;

int canLive(int x, int y) {

	if (check[x][y]) {
		return check[x][y];
	}
	check[x][y] = 1;

	for (int a = 0; a < 4; a++) {
		int nx = dx[a] + x;
		int ny = dy[a] + y;

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		
		if (forest[x][y] >= forest[nx][ny]) continue;

		check[x][y] = max(check[x][y], canLive(nx, ny)+ 1);
	}

	return check[x][y];
}

int main() 
{
	cin >> n;
	int m;

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			cin >> forest[a][b];
		}
	}

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			m = max(m, canLive(a, b));
		}
	}

	cout << m;
    return 0;
}

