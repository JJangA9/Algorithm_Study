
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n, k;
	int count = 0;

	cin >> n >> k;
	while (n > 1) {
		if (n % k != 0) {
			n -= 1;
			count++;
		}
		else {
			n /= k;
			count++;
		}
	}

	cout << count;

    return 0;
}

