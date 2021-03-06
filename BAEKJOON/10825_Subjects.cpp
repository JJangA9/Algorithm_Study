
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Student {
	string name;
	int korean;
	int english;
	int math;
};

bool cmp(Student s1,Student s2) {
	if (s1.korean != s2.korean)
		return s1.korean > s2.korean;
	else {
		if (s1.english != s2.english)
			return s1.english < s2.english;
		else {
			if (s1.math != s2.math)
				return s1.math > s2.math;
			else {
				return s1.name < s2.name;
			}
		}
	}

}

int main()
{
	int n;
	cin >> n;
	vector<Student> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i].name >> vec[i].korean >> vec[i].english >> vec[i].math;
	}

	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << vec[i].name << '\n';
	}
    return 0;
}

