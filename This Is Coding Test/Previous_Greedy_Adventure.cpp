
#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;
int person[100001];

int main()
{
	int n, group = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> person[i];
	}

	sort(person, person + n);

	while (n > 0) {
		n = n - person[n - 1];
		group++;
	}

	cout << group;
    return 0;
}

