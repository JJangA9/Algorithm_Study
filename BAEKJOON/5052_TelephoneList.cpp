#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int t, n;
	n = 0;
	string temp;
	cin >> t;

	for (int k = 0; k < t; k++) {
		cin >> n;
		vector<string> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			cout << v[i] << '\n';
		}
		/*for (int z = 1; z < v.size(), z++) {
			temp = v[2];
			if(v[0] == v[i])
		}*/
		v.clear();
	}
    return 0;
}

