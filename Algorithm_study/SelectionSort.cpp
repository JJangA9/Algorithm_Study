#include <stdio.h>

int main(void) {
	int min, index, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	for (int a = 0; a < 10; a++)
	{
		min = 9999;
		for (int t = a; t < 10; t++)
		{
			if (min > array[t])
			{
				min = array[t];
				index = t;
			}
		}
		temp = array[a];
		array[a] = array[index];
		array[index] = temp;

		for (int a = 0; a < 10; a++)
		{
			printf("%d", array[a]);
		}
	}


	return 0;
}