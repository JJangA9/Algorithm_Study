// ConsoleApplication48.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int main()
{
	int a = 0;
	int i = 0;
	int arr[10];
	int temp = 0;

	scanf_s("%d", &a);
	
	while (i < 10)
	{
		if (a < 10)
		{
			arr[i] = a;
			break;
		}
		else
		{
			arr[i] = a % 10;
			a = a / 10;
		}
		i = i + 1;
	}

	for (int z = 0; z < i + 1; z++)
	{
		for (int t = 0; t < i - z; t++)
		{
			if (arr[t] < arr[t + 1])
			{
				temp = arr[t];
				arr[t] = arr[t+1];
				arr[t + 1] = temp;
			}
		}
	}

	for (int z = 0; z < i + 1; z++)
		printf("%d", arr[z]);
    return 0;
}

