
#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int n, count = 0;
	int a[4] = { 500, 100, 50, 10 };
	
	cin >> n;
	for (int i = 0; i < 4; i++) {
		if (n >= a[i]) {
			count += n / a[i];
			n %= a[i];
		}
	}

	cout << count;
    return 0;
}

