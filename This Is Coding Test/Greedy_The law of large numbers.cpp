
#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, k, iter, left;
	int sum = 0;
	int a[1000] = {};

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	iter = m / (k + 1);
	left = m % (k + 1);

	for(int b = 0; b < iter; b++) {
		for (int i = 0; i < k; i++) {
			sum += a[n - 1];
		}
		sum += a[n - 2];
	}
	sum += a[n - 1] * left;

	cout << sum;
	
    return 0;
}

