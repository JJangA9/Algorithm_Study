
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string s;
	int result = 1;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		s[i] -= '0';
	}

	for (int i = 0; i < s.size(); i++) {

		if (s[i] == 0) {
			continue;
		}
		else if (s[i] == 1) {
			result = result + 1;
		}
		else {
			result = result * s[i];
		}
	}

	cout << result;
    return 0;
}

