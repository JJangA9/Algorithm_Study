
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> divideStr;
int num = 0;

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str[i]))
			divideStr.push_back(str[i]);
		else
			num += str[i] - '0';
	}

	sort(divideStr.begin(), divideStr.end());

	for (int i = 0; i < divideStr.size(); i++) {
		cout << divideStr[i];
	}

	cout << num;
    return 0;
}

