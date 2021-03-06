
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool checkBalance(string p) {
	int cnt = 0;
	int correct = 1;

	//올바른 문자열인지 확인
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') cnt += 1;
		else cnt -= 1;

		if (cnt < 0) {
			correct = 0;
			break;
		}
	}

	if (cnt == 0 && correct == 1)
		return true;
	else
		return false;
}

string divide(string p) {
	if (p == "") { return ""; }

	string u, v, temp;
	int c1 = 0, c2 = 0;

	//균형잡힌 문자열 u, v로 분리
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(')
			c1++;
		else
			c2++;

		if (c1 == c2) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}

	if (checkBalance(u)) { //올바른 문자열이면
		return u + divide(v);
	}
	else {
		temp = "(" + divide(v) + ")";
		u = u.substr(1, u.size() - 2);
		for (int i = 0; i < u.size(); i++) {
			u[i] = (u[i] == '(') ? ')' : '(';
		}

		temp = temp + u;
		return temp;
	}
}

string solution(string p) {

	//올바른 문자열인지 확인
	if (checkBalance(p))
		return p;
	else
		return divide(p);
}

int main() {
	// your code goes here

	string s = "(()))(";
	cout << solution(s);
	return 0;
}
