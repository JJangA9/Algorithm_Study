// 11652_Card.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int index = 0;
	int max = 0;
	int count = 1;
	cin >> n;
	vector<long long> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	for (int i = 0; i < n - 1; i++) {
		if (v[i] == v[i + 1]) {
			count++;
			if (max < count) {
				max = count;
				index = i;
			}
		}
		else {
			count = 1;
		}
	}
	cout << v[index];
    return 0;
}

