
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int notFin;

int binarySearch(int start, int end, vector<int> v) {
	if (start == end) {
		notFin = start;
		return 0;
	}

	int mid = (start + end) / 2;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] - v[mid] > 0)
			sum += (v[i] - v[mid]);
	}

	if (sum == m) return v[mid];
	else if (sum < m) return binarySearch(start, mid - 1, v);
	else return binarySearch(mid + 1, end, v);
}

int main()
{
	vector<int> v;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int t = binarySearch(0, n - 1, v);
	if (t) {
		cout << t;
	}

	else {
		int sum = 0, max = 0, maxH = 0;

		if (notFin == 0) {
			for (int i = 0; i < v[notFin + 1]; i++) {
				for (int k = 0; k < n; k++) {
					if (v[k] > i) {
						sum += v[k] - i;
					}
				}
				if(max < sum && sum >= m) {
					max = sum;
					maxH = i;
				}
			}
		}
		else if (notFin == n - 1) {
			for (int i = v[n - 1]; i > v[notFin - 1]; i--) {
				for (int k = 0; k < n; k++) {
					if (v[k] > i) {
						sum += v[k] - i;
					}
				}
				if (max < sum && sum >= m) {
					max = sum;
					maxH = i;
				}
			}
		}
		else {
			for (int i = v[notFin - 1]; i < v[notFin + 1]; i++) {
				for (int k = 0; k < n; k++) {
					if (v[k] > i) {
						sum += v[k] - i;
					}
				}
				if (max < sum && sum >= m) {
					max = sum;
					maxH = i;
				}
			}
		}

		cout << maxH;
	}
    return 0;
}