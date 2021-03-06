
#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int node[32001], result[32001], p = 1;
queue<int> q;
vector<int> v[32001];

void toplogy(int studentN) {
	for (int i = 1; i <= studentN; i++) {
		if (node[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 1; i <= studentN; i++) {
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			if (--node[y] == 0) {
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= studentN; i++) {
		printf("%d ", result[i]);
	}
}

int main()
{
	int n, m, t1, t2;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> t1 >> t2;
		node[t2]++;
		v[t1].push_back(t2);
	}

	toplogy(n);
    return 0;
}

