// 9020_Goldbach.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int num[10001];

void isPrime() {
	for (int i = 1; i <= 10000; i++) {
		num[i] = i;
	}

	for (int i = 2; i <= 10000; i++) {
		if (num[i] == 0) continue;
		for (int k = i + i; k <= 10000; k += i) {
			num[k] = 0;
		}
	}
}

int main()
{
	int n, temp, sub, index = 0;
	cin >> n;

	isPrime();
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sub = temp;

		for (int k = 1; k <= (temp / 2); k++) {
			if (num[k] == 0) continue;

			if (num[temp - k] != 0) {
				if (sub >(temp - num[k])) {
					sub = temp - num[k];
					index = k;
				}
			}
		}

		cout << index << ' ';
		cout << temp - index << '\n';
	}
    return 0;
}

