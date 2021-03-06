// 11650.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
typedef struct ar {
	int x;
	int y;
}Arr;

void quickSort(Arr* data, int start, int end)
{
	if (start >= end)
		return;

	int key = start;
	int i = start + 1;
	int j = end;
	Arr temp;

	while (i <= j)
	{
		while (data[i].x <= data[key].x)
		{
			i++;
		}
		while (data[j].x >= data[key].x && j > start)
		{
			j--;
		}

		if (i <= j)
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
		else
		{
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
};

void quickSort2(Arr* data, int start, int end)
{
	if (start >= end)
		return;

	int key = start;
	int i = start + 1;
	int j = end;
	Arr temp;

	while (i <= j)
	{
		while (data[i].y <= data[key].y)
		{
			i++;
		}
		while (data[j].y >= data[key].y && j > start)
		{
			j--;
		}
		if (i <= j)
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
		else
		{
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
	}
	quickSort2(data, start, j - 1);
	quickSort2(data, j + 1, end);
};

int main()
{
	int n;
	int c = 0;
	int z;
	scanf_s("%d", &n);
	scanf_s("");

	Arr *arr = (Arr*)malloc(sizeof(Arr)*n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &arr[i].x, &arr[i].y);
	}

	quickSort2(arr, 0, n - 1);

	while (c < n)
	{
		z = c;

		if (arr[c].x == arr[c + 1].x)
		{
			while (arr[z].x == arr[z + 1].x)
			{
				z++;
			}
			quickSort(arr, c, z);
		}
		c = z + 1;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", arr[i].x, arr[i].y);
	}

	return 0;
}

