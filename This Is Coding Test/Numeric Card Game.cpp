
#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, t;
	int result = 0;

	cin >> n >> m;

	for (int a = 0; a < n; a++) {
		int min_value = 10001;

		for (int k = 0; k < m; k++) {
			cin >> t;
			min_value = min(min_value, t);
		}

		result = max(result, min_value);
	}

	cout << result;
    return 0;
}

