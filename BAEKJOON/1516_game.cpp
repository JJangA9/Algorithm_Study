#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n, result[501], time[501], inDegree[501];
vector<int> v[501];

void topology() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			result[i] = time[i];
			q.push(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		int y = q.front();
		q.pop();

		for (int k = 0; k < v[y].size(); k++) {
			int x = v[y][k];
			result[x] = max(result[x], result[y] + time[x]);
			if (--inDegree[x] == 0) {
				q.push(x);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", result[i]);
	}
}

int main()
{
	int t;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &t);
		time[i] = t;
		while(1) {
			scanf_s("%d", &t);
			if (t == -1) {
				break;
			}
			inDegree[i]++;
			v[t].push_back(i);
		}
	}
	topology();
    return 0;
}

