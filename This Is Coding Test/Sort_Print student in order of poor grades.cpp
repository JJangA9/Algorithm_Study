
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<pair<int, string>> v;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int score;
		string name;

		cin >> name >> score;
		v.push_back(make_pair(score, name));
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].second << ' ';
	}

    return 0;
}

