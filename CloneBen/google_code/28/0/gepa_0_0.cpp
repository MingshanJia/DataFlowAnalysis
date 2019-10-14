#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int W, B;

string res;

void parse() {
	cin >> W >> B;
}

void doit() {
	if (B % 2 == 0) res = "WHITE";
	else res = "BLACK";
}

void printResult() {
	printf("%s\n", res.c_str());
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parse();
		doit();
		printf("Case #%d: ", i);
		printResult();
	}
	return 0;
}

