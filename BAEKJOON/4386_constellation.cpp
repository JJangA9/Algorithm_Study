#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#define MAX 275

using namespace std;
int DP[MAX];

int getCount(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (DP[n] != 0) return DP[n];
	return DP[n] = getCount(n - 1) + getCount(n - 2) + getCount(n - 3);
}

int main()
{
	int t, n;
	cin >> t;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (int i = 0; i < t; i++) {
		scanf_s("%d", &n);
		getCount(n);
		printf("%d\n", DP[n]);
	}
    return 0;
}

