
#include "stdafx.h"
#include <iostream>

using namespace std;
int location;
int arr[3][50], check[3][50];

void turn() {
	location--;
	if (location == -1) location = 3;
}

int main()
{
	int n, m, count = 1;
	int x, y, checked = 0;
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};

	cin >> n >> m;
	cin >> x >> y >> location;
	check[x][y] = 1;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> arr[i][k];
		}
	}

	while (true) {
		turn();

		//네 곳을 다 확인했는데 갈 곳이 없다면
		if (checked == 4) {
			//뒤가 바다가 아니라면
			if (arr[x - dx[location]][y - dy[location]] == 0) {
				x -= dx[location];
				y -= dy[location];
			}
			// 뒤가 바다라면
			else {
				break;
			}
			checked = 0;
		}

		//만약 왼쪽 방향이 안가본 육지면
		if (arr[x + dx[location]][y + dy[location]] == 0 && check[x + dx[location]][y + dy[location]] == 0) {
			x += dx[location];
			y += dy[location];
			check[x][y] = 1;
			count++;
			checked = 0;

		}
		//바다거나 갔던 곳이면
		else {
			turn();
			checked++;
		}
	}

	cout << count;
    return 0;
}

