
#include "stdafx.h"
#include <iostream>

using namespace std;
int num[8];

int main()
{
	long long n, divide = 10;
	int count = 0;

	cin >> n;

	while (true) {
		if (n / divide > 0) {
			num[count] = n % divide;
			n /= divide;
			count++;
		}

		else {
			num[count] = n;
			break;
		}
	}

	int sum = 0, sum2 = 0;
	for (int i = 0; i < count + 1; i++) {
		if (i >= (count + 1) / 2) {
			sum2 += num[i];
		}
		else {
			sum += num[i];
		}
	}

	if (sum == sum2) cout << "LUCKY";
	else cout << "READY";
    return 0;
}

