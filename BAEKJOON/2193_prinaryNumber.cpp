
#include "stdafx.h"
#include <iostream>

using namespace std;

long long result[91];

long long getCount(int n) {
	if (n == 1 || n == 2) return 1;

	if (result[n] != 0) return result[n];
	return result[n] = getCount(n - 1) + getCount(n - 2);
} 

int main()
{
	int n;
	cin >> n;

	cout << getCount(n);
    return 0;
}

