
#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
bool check[300001];
vector<int> result;
vector<int> city[300001];
int n, m, k, startCity;

void bfs(int x) {
	queue<pair<int, int>> q;

	q.push({ x, 0 });
	check[x] = true;
	
	while (!q.empty()) {
		int y = q.front().first;
		int count = q.front().second;
		q.pop();

		if (count == k) result.push_back(y);

		for (int i = 0; i < city[y].size(); i++) {
			int a = city[y][i];
			if (!check[a]) {
				q.push({ a, count + 1 });
				check[a] = true;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k >> startCity;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		city[a].push_back(b);
	}

	bfs(startCity);

	if (result.size() != 0) {
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
		}
	}
	else cout << -1;
    return 0;
}

