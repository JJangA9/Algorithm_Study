#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int arr[3];
int sequence[3];

int main()
{
	string c;
	for (int i = 0; i < 3; i++)
		cin >> arr[i];
	cin >> c;

	for (int i = 0; i < 3; i++) {
		if (c[i] == 'A')
			sequence[i] = 0;
		else if (c[i] == 'B')
			sequence[i] = 1;
		else
			sequence[i] = 2;
	}

	sort(arr, arr + 3);

	for (int i = 0; i < 3; i++) {
		printf("%d ", arr[sequence[i]]);
	}

    return 0;
}

