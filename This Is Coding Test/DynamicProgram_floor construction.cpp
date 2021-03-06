
#include "stdafx.h"
#include <iostream>

using namespace std;

int d[1001];

int dynamic(int n) {
	if (n == 1) return 1;
	if (n == 2) return 3;

	return d[n] = dynamic(n - 1) + 2 * dynamic(n - 2);
}

int main()
{
	int n;

	cin >> n;
	dynamic(n);

	cout << (d[n] % 797796);
    return 0;
}

