#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int t, end = 0;
	float count = 0;
	string s;
	int temp = 0;
	cin >> t;
	vector<string> v(t);

	for (int i = 0; i < t; i++) {
		cin >> v[i];
	}

	while (temp < t) {
		for (int i = 0; i < v[temp].length(); i++) {
			if (v[temp][i] == '(') {
				count++;
			}
			else {
				count--;
				if (count < 0) {
					end = 1;
					break;
				}
			}
		}
		if ((count != 0) ||(end == 1))
			printf("NO\n");
		else
			printf("YES\n");
		temp++;
		count = 0;
		end = 0;
	}

	return 0;
}
