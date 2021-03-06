
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;
int arr[101][101];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 101; i++) {
		fill(arr[i], arr[i] + 101, INF);
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			if (i == k) arr[i][k] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	int x, k;
	cin >> x >> k;

	for (int i = 1; i <= n; i++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				arr[a][b] = min(arr[a][b], arr[a][i] + arr[i][b]);
			}
		}
	}

	if (arr[1][k] + arr[k][x] >= INF) cout << -1;
	else cout << arr[1][k] + arr[k][x];
    return 0;
}

