
#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int c[2] = { 0, 0 };

int main()
{
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		c[s[i] - '0']++;

		for (int j = i + 1; j < s.size(); j++) {
			if (s[i] != s[j]) {
				i = j - 1;
				break;
			}

			if (j == s.size() - 1) {
				i = j;
			}
		}
	}

	cout << min(c[0], c[1]);

    return 0;
}

