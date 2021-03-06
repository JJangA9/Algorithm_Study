#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

long long pill[30][30];

long long dp(int one, int half) {
	if (one == 0) return 1;

	if (pill[one][half] != 0) return pill[one][half];

	if (half > 0) {
		return pill[one][half] = dp(one - 1, half + 1) + dp(one, half - 1);
	}

	else if (half == 0) {
		return pill[one][half] = dp(one - 1, half + 1);
	}
}

int main()
{
	int n;

	while (1) {
		cin >> n;
		if (n == 0)
			break;

		cout << dp(n, 0) << '\n';
	}
    return 0;
}

