// Floyd Warshall.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

int number = 4;
int INF = 1000000000;

//자료 배열을 초기화
int a[4][4] = {
	{0, 5, INF, 8},
{7, 0, 9, INF},
{2, INF, 0, 4},
{INF, INF, 3, 0}
};

void floydWarshall() {
	//결과 그래프를 초기화
	int d[4][4];

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k = 거쳐가는 노드
	for (int k = 0; k < number; k++) {
		//i는 출발노드
		for (int i = 0; i < number; i++) {
			//j = 도착 노드
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	//결과를 출력
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	floydWarshall();
    return 0;
}

