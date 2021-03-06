#include "stdafx.h"
#include <iostream>

using namespace std;
int a[101][101];

void floyd(int m) {
	for (int i = 1; i <= m; i++) {
		for (int k = 1; k <= m; k++) {
			for (int j = 1; j <= m; j++) {
				if ((a[k][i] == 1) && (a[i][j] == 1)) {
					a[k][j] = 1;
				}
			}
		}
	}
}

int main()
{
	int n, m, t1, t2, cnt = 0;
	cin >> n;
	cin >> m;

	for (int i = 1; i <= m; i++) {
		cin >> t1 >> t2;
		a[t1][t2] = 1;
	}
	floyd(n);


	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int k = 1; k <= n; k++) {
			if (!a[i][k] && !a[k][i]) cnt++;
		}
		cout << cnt - 1 << '\n';
	}

    return 0;
}

