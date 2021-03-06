
#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;
char arr[1000][1000];
int check[1000][1000];
int dx[4] = { 0, 0, 1, -1 }, dy[4] = {1, -1, 0, 0};
int cnt = 0;
int n, m;

void dfs(int x, int y)
{
	queue<pair<int, int>> q;
	int xt, yt;

	q.push(make_pair(x, y));
	check[x][y] = 1;

	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			xt = q.front().first + dx[i];
			yt = q.front().second + dy[i];

			if (xt >= 0 && yt >= 0 && xt <= n && yt <= m && arr[xt][yt] == '0' && check[xt][yt] == 0) {
				q.push(make_pair(xt, yt));
				check[xt][yt] = 1;
			}
		}
		q.pop();		
	}
	cnt++;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> arr[i][k];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if(check[i][k] == 0 && arr[i][k] == '0')
				dfs(i, k);
		}
	}

	cout << cnt;
	return 0;
}

