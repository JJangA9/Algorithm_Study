
#include "stdafx.h"
#include <iostream>
#define INF 1e9;

using namespace std;
int arr[201][201];
int check[201][201];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = {0, 1, 0, -1};
int n, k, s;

void dfs(int x, int y, int c) {
	check[x][y] = 1;
	if (c == s) {
		return;
	}

	c += 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx > 0 && nx <= n && ny > 0 && ny <= n && arr[nx][ny] == 0) {
			arr[nx][ny] = arr[x][y];
			dfs(nx, ny, c);
		}
	}
	return;

}

int main()
{
	int x, y;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			cin >> arr[i][k];
		}
	}
	cin >> s >> x >> y;

	int min = INF;
	int minx, miny;
	
	for (int a = 0; a < k; a++) {
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= n; k++) {
				if (arr[i][k] != 0 && min > arr[i][k] && check[i][k] == 0) {
					min = arr[i][k];
					minx = i;
					miny = k;
					
				}
			}
		}
		dfs(minx, miny, 0);
		min = INF;
	}

	cout << arr[x][y];
    return 0;
}

