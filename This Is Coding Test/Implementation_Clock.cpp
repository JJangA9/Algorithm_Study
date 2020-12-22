
#include "stdafx.h"
#include <iostream>

using namespace std;

bool check(int i, int j, int k, int num) {
	if (i % 10 == num || j / 10 == num || j % 10 == num || k / 10 == num || k % 10 == num)
		return true;
	return false;
}

int main()
{
	int n;
	int cnt = 0;

	cin >> n;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				if(check(i, j, k, n)) cnt++;
			}
		}
	}

	cout << cnt;
    return 0;
}

