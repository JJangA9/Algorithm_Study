// MergeSort.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
int arr[8];
int number = 8;

void merge(int a[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) // 작은 순서대로 배열에 삽입
	{
		if (a[i] <= a[j])
		{
			arr[k] = a[i];
			i++;
		}
		else
		{
			arr[k] = a[j];
			j++;
		}
		k++;
	}

	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			arr[k] = a[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			arr[k] = a[t];
			k++;
		}
	}
	for (int t = m; t <= n; t++)
	{
		a[t] = arr[t];
	}
}

void mergeSort(int a[], int m, int n)
{
	if (m < n)
	{
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main()
{
	int arra[8] = { 7, 6, 5, 8, 3, 5, 9, 1 };
	mergeSort(arra, 0, 7);

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arra[i]);
	}
    return 0;
}

