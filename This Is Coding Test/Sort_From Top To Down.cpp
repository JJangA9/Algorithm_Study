
#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int arr[501];

int main()
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	sort(arr, arr + n);

	for (int i = n -1; i >= 0; i--) {
		cout << arr[i] << ' ';
	}
    return 0;
}

