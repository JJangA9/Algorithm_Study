
#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;
int arr[101];
int d[101];

int main()
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	d[0] = arr[0];
	d[1] = max(arr[0], arr[1]);
	for (int i = 2; i < n; i++) {
		d[i] = max(d[i - 1],  d[i - 2] + arr[i]);
	}

	cout << d[n - 1];
    return 0;
}

