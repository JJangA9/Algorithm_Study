#include "stdafx.h"
#include <stack>
#include <string>
#include <iostream>

using namespace std;
stack <char> s;

int main()
{
	int n, count = 0;
	string str;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		
		for (int k = 0; k < str.length(); k++) {
			if (!s.empty() && (str[k] == s.top()))
				s.pop();
			else
				s.push(str[k]);
		}

		if (s.empty())
			count++;
		else {
			while (!s.empty())
				s.pop();
		}
	}
	cout << count;
	
    return 0;
}

