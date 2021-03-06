
#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;
int d[30001];

int dynamic(int x) {
	if (x == 2 || x == 3 || x == 5) return 1;

	if (d[x] != 0) return d[x];

	int temp1 = INT_MAX, temp2 = INT_MAX, temp3 = INT_MAX, temp4 = INT_MAX;
	if (x % 2 == 0) temp1 = 1 + dynamic(x / 2);
	if (x % 3 == 0) temp2 = 1 + dynamic(x / 3);
	if (x % 5 == 0) temp3 = 1 + dynamic(x / 5);
	temp4 = 1 + dynamic(x - 1);

	return d[x] = min(min(temp1, temp2), min(temp3, temp4));
}

int main()
{
	int x;

	cin >> x;
	cout << dynamic(x);

    return 0;
}