
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
vector<int> ball;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		ball.push_back(weight);
	}

	int cnt = 0;
	for (int i = 0; i < ball.size() - 1; i++) {
		for (int k = i + 1; k < ball.size(); k++) {
			if (ball[i] != ball[k]) {
				cnt++;
			}
		}
	}

	cout << cnt;
    return 0;
}

