// 10814_SortByAge.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
typedef struct person {
	int age;
	char name[100];
	int r; // Order of registeration
}p;

void quickSort(p* data, int start, int end)
{
	if (start >= end)
		return;

	int i = start + 1;
	int j = end;
	int key = start;
	p temp;

	while (i <= j)
	{
		while (data[i].age <= data[key].age)
		{
			i++;
		}

		while (data[j].age >= data[key].age && j > start)
		{
			j--;
		}

		if (i <= j)
		{
			temp = data[i];
			data[j] = data[j];
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
}

void quickSort2(p* data, int start, int end)
{
	if (start >= end)
		return;

	int i = start + 1;
	int j = end;
	int key = start;
	p temp;

	while (i <= j)
	{
		while (data[i].r <= data[key].r)
		{
			i++;
		}

		while (data[j].r >= data[key].r && j > start)
		{
			j--;
		}

		if (i <= j)
		{
			temp = data[i];
			data[j] = data[j];
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
}

int main()
{
	int n;
	int count = 0;
	int c = 0;

	scanf_s("%d", &n);

	p* person = (p*)malloc(sizeof(p) * n);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d ", &person[i].age);
		gets_s(person[i].name);
		person[i].r = count;
		count++;
	}

	int j = 0;
	quickSort(person, 0, n - 1);

	while (c < n)
	{
		j = c;
		while (person[j].age == person[j+1].age)
		{
			j++;
		}
		quickSort2(person, c, j);
		c = j + 1;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n", person[i].age, person[i].name);
	}
    return 0;
}

