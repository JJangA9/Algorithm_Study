
#include "stdafx.h"
#include <iostream>

using namespace std;

int p[1000001];
char t[1000001];

int main()
{
	int l, j = 0;
	cin >> l >> t;

	for (int i = 1; i < l; i++) {
		while (t[j] != t[i] && j > 0) {
			j = p[j - 1];
		}
		if (t[j] == t[i]) {
			p[i] = ++j;
		}
	}

	cout << l - p[l - 1];
    return 0;
}

