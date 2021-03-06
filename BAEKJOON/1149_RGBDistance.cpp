
#include "stdafx.h"
#include <iostream>

using namespace std;

int DP[1001][3];
int a[1001][3];

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int fmin(int a, int b, int c) {
	if ((a <= b) && (a <= c)) return a;
	else if ((b <= a) && (b <= c)) return b;
	else if ((c <= a) && (c <= b)) return c;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	for (int i = 1; i <= n; i++) {
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + a[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + a[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + a[i][2];
	}

	cout << fmin(DP[n][0], DP[n][1], DP[n][2]);

    return 0;
}

