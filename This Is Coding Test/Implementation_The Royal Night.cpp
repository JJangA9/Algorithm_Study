
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int can_go[8][2] = { {2,1}, {-1,2}, {-2, -1}, {1, -2}, {2, -1}, {1, 2}, {-2, 1}, {-1, - 2} };
	char a;
	int t, count = 0;

	cin >> a >> t;

	for (int i = 0; i < 8; i++) {
		int x = (int(a) - 96) + can_go[i][0];
		int y = t + can_go[i][1];

		if (x >= 1 && x <= 8 && y >= 1 && y <= 8) {
			count++;
		}
	}

	cout << count;
    return 0;
}