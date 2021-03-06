
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;
vector <pair<int, int>> city[30001];
int d[30001];

int main()
{
	int n, m, c;
	priority_queue<pair<int, int>> pq;

	cin >> n >> m >> c;
	fill_n(d, 30001, INF);
	d[c] = 0;
	pq.push({ 0, c });

	for (int i = 0; i < m; i++) {
		int x, y, time;
		cin >> x >> y >> time;
		city[x].push_back({y, time});
	}

	while (!pq.empty()) {
		int t = -pq.top().first; // 전달되는 시간
		int now = pq.top().second;
		pq.pop();

		if (d[now] < t) continue;

		for (int i = 0; i < city[now].size(); i++) {
			int cost = t + city[now][i].second;

			if (d[city[now][i].first] > cost)
				d[city[now][i].first] = cost;

			pq.push({ -cost, city[now][i].first });
		}
	}

	int cnt = 0, maxDistance = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] != INF) {
			cnt++;
			maxDistance = max(maxDistance, d[i]);
		}
	}

	cout << cnt - 1 << ' ' << maxDistance;
    return 0;
}

