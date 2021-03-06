// ConsoleApplication52.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
typedef struct w{
	int len;
	int same = 0;
	char word[50];
}word;

int main()
{
	int count = 0;
	int num;
	int *arr;
	scanf_s("%d\n", &num);

	word temp;
	word* w = (word*)malloc(sizeof(word)*num);
	arr = (int*)malloc(sizeof(int)*num);

	for (int i = 0; i < num; i++) // scan string
	{
		gets_s(w[i].word);
		w[i].len = strlen(w[i].word);
		arr[i] = w[i].len;
	}

	int j = 0;

	for (int i = 0; i < num - 1; i++) //insertion sort
	{
		j = i;
		while (w[j].len > w[j + 1].len)
		{
			temp = w[j];
			w[j] = w[j + 1];
			arr[j] = arr[j + 1]; // array sorting
			w[j + 1] = temp;
			arr[j + 1] = temp.len;

			j--;

			if (j < 0)
				break;
		}
	}

	int x = 0;
	j = 0;

	for (int i = 0; i < num - 1; i++)
	{
		count = 0;
		j = i;

		while (arr[j] == arr[j + 1])
		{
			count++;
			j++;

			if (j == num) // end of array
				break;
		}

		if (count == 0)
		{
			continue;
		}

		else
		{
			for (int z = i + count; z >= i; z--) // sort same length
			{
				x = i;
				while (1)
				{
					if (strcmp(w[x].word, w[x + 1].word) == 1)
					{
						temp = w[x];
						w[x] = w[x + 1];
						w[x + 1] = temp;
					}

					else if (strcmp(w[x].word, w[x + 1].word) == 0)
					{
						if((w[x].word != 0)&&(w[x+1].word != 0))
							w[x + 1].len = 0;
					}

					x++;
					if (x >= z)
						break;
				}
			}
			i = i + count;
		}
	}

	for (int i = 0; i < num; i++)
	{
		if(w[i].len != 0)
			printf("%s\n", w[i].word);
	}
    return 0;
}

