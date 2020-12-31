
#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;
int a[10000001], b[10000001];


int main()
{
	int n, k, sum = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(a, a + n);
	sort(b, b + n);

	for (int i = 0; i < k; i++) {
		if (a[i] < b[n - 1 - i]) {
			int temp = a[i];
			a[i] = b[n - 1 - i];
			b[n - 1 - i] = temp;
		}
		else break;
	}

	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	cout << sum;
    return 0;
}

