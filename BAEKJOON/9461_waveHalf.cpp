
#include "stdafx.h"
#include <iostream>

using namespace std;
int a[100];

int getLength(int n) {
	if (n == 1) {
		a[1] = 1;
		return 1;
	}
	if (n == 2) {
		a[2] = 1;
		return 1;
	}
	if (n == 3) {
		a[3] = 1;
		return 1;
	}

	if (a[n] != 0) return a[n];
	return a[n] = getLength(n - 2) + getLength(n - 3);

}

int main()
{
	int n, t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		cin >> n;
		getLength(n);
		cout << a[n] << '\n';
	}
    return 0;
}

