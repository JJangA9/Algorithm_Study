
#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;
int store[1000001], client[1000001];

void binarySearch(int start, int end, int m) {
	for (int i = 0; i < m; i++) {
		bool isExist = false;

		int tstart = start;
		int tend = end;

		while (tstart <= tend) {
			int mid = (tstart + tend) / 2;

			if (store[mid] == client[i]) {
				isExist = true;
				break;
			}
			else if (store[mid] < client[i]) tstart = mid + 1;
			else tend = mid - 1;
		}

		if (isExist) cout << "yes" << ' ';
		else cout << "no" << ' ';
	}

}

int main()
{
	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> store[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> client[i];
	}

	sort(store, store + n);
	
	binarySearch(0, n, m);
    return 0;
}

