// ConsoleApplication50.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"

int main()
{
	int s, index, maxIndex, min, max,temp;
	int sum = 0;
	int end = 0;
	int state = 1;
	int *arrA, *arrB, *arrEnd;
	scanf_s("%d", &s);

	arrA =(int *) malloc(sizeof(int) * s);
	arrB = (int *)malloc(sizeof(int) * s);
	arrEnd = (int *)malloc(sizeof(int) * s);

	for (int i = 0; i < s; i++)
	{
		scanf_s("%d", &arrA[i]);

		if (i == s - 1)
			break;
		scanf_s(" ");
	}

	for (int i = 0; i < s; i++)
	{
		scanf_s("%d", &arrB[i]);

		if (i == s - 1)
			break;
		scanf_s(" ");
	}

	for (int i = 0; i < s; i++)
	{
		max = -1;
		min = 200;


		for (int t = 0; t < s; t++) //find min
		{
			for (int a = 0; a < end; a++)
			{
				if (arrEnd[a] == t)
				{
					state = 0;
					break;
				}
			}

			if (state == 0)
			{
				state = 1;
				continue;
			}

			else
			{
				if (min > arrB[t])
				{
					min = arrB[t];
					index = t;
				}
			}
		}

		for (int t = 0; t < s; t++) //find max
		{
			for (int a = 0; a < end; a++)
			{
				if (arrEnd[a] == t)
				{
					state = 0;
					break;
				}
			}

			if (state == 0)
			{
				state = 1;
				continue;
			}

			else
			{
				if (max < arrA[t])
				{
					max = arrA[t];
					maxIndex = t;
				}
			}
		}

		temp = arrA[maxIndex];
		arrA[maxIndex] = arrA[index];
		arrA[index] = temp;

		arrEnd[end] = index;
		end = end + 1;
	}

	for (int i = 0; i < s; i++)
	{
		sum = sum + (arrA[i] * arrB[i]);
	}
	printf("%d",sum);

    return 0;
}
