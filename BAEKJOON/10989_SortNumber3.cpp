// ConsoleApplication49.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int main(void) {
	int num, index;
	int n, temp, min, arr[100];
	scanf_s("%d", &num);
	
	for (int a = 0; a < num; a++)
	{
		scanf_s("%d", &n);
		arr[a] = n;
	}

	for (int a = 0; a < num; a++)
	{
		min = 9999;
		for (int t = a; t < num; t++)
		{
			if (min > arr[t])
			{
				index = t;
				min = arr[t];
			}
		}

		temp = arr[a];
		arr[a] = arr[index];
		arr[index] = temp;
	}

	for (int a = 0; a < num; a++)
	{
		printf("%d\n", arr[a]);
	}
	return 0;
}

