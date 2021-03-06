
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int, pair<int, int>>> home;
int parent[100001];
int result = 0;

int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;

		home.push_back({ cost, { a, b } });
	}

	sort(home.begin(), home.end());
	int last = 0;

	for (int i = 0; i < home.size(); i++) {
		int cost = home[i].first;
		int a = home[i].second.first;
		int b = home[i].second.second;

		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			result += cost;
			last = cost;
		}

	}

	cout << result - last;

    return 0;
}

