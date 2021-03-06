
#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;
int d[501];
int time[501];
int minTime[501];
vector<int> lecture[501];

int main()
{
	int n;
	queue<int> pq;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		time[i] = t;
		minTime[i] = t;

		int lec;
		cin >> lec;
		while (lec != -1) {
			lecture[lec].push_back(i);
			d[i]++;

			cin >> lec;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int a = pq.front();
		pq.pop();

		for (int i = 0; i < lecture[a].size(); i++) {
			d[lecture[a][i]]--;
			minTime[lecture[a][i]] = max(minTime[lecture[a][i]], time[lecture[a][i]] + minTime[a]);

			if (d[lecture[a][i]] == 0) {
				
				pq.push(lecture[a][i]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << minTime[i] << endl;
	}
    return 0;
}

