
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	int x = 1, y = 1;

	string move;

	cin >> n;
	cin.ignore();
	getline(cin, move);

	for (int i = 0; i < move.size(); i++) {
		char moving = move[i];

		switch (moving) {
		case('L'):
			if (y > 1) {
				y -= 1;
			}
			break;
		case('R'):
			if (y < n) {
				y += 1;
			}
			break;
		case('U'):
			if (x > 1) {
				x -= 1;
			}
			break;
		case('D'):
			if (x < n) {
				x += 1;
			}
		}
	}

	cout << x << ' ' << y;
    return 0;
}

