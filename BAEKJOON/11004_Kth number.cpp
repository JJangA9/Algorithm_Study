// 11004_Kth number.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	int num;
	cin >> n >> k;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	cout << v[k - 1];
    return 0;
}

