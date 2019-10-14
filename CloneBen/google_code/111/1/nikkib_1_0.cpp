#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

#define ull unsigned long long
void func(int T) {
	ull  A, B, alpha, beta, Y;
	cin >> A >> B>>alpha>>beta>> Y;

	for (int i = 0; i < Y; ++i) {
		ull K =A;
		if (B<A) K = B;
		
		ull baby = K / 50;
		ull babyA = baby * alpha / 100;
		ull babyB = baby* beta/100;
		ull remaining= baby - babyA - babyB;
		babyA += remaining/2;
		babyB += remaining/2;
		if (remaining % 2 == 1) babyB ++;

		A = A  - A/100 + babyA;
		B = B - B /100 + babyB;
	}

	cout << "Case #"<<T<< ": " << A << " " << B << endl;
}

int main() {
	int tcase;
	cin >> tcase;
	string temp;
	getline(cin, temp);
	for (int i = 1; i <=tcase; ++i) {
		func(i);
	}
	return 0;
}
