
#include "stdafx.h"
#include <iostream>

using namespace std;
int p[100001];

int find_parent(int a) {
	if (a == p[a]) return a;

	return p[a] = find_parent(p[a]);
}

void union_parent(int a, int b) {

	int x = find_parent(a);
	int y = find_parent(b);

	if (x < y) p[b] = x;
	else if (x > y) p[a] = y;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x, a, b;
		cin >> x >> a >> b;

		if (x == 0) { // 팀 합치기
			union_parent(a, b);
		}
		else { // 같은 팀인지 확인
			int x = find_parent(a);
			int y = find_parent(b);

			if (x == y) cout << "YES";
			else cout << "NO";
		}
	}

    return 0;
}

