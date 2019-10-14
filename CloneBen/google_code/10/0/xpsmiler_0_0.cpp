#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <queue>
#include <list>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

string m[10];

string dosolve(int s,int state) {
	string answer = "0000000";
	for (int i = 0; i < 7; ++i) {
		if (state & (1 << i)) {
			answer[i] = '0';
		}
		else {
			answer[i] = m[s][i];
		}
	}
	return answer;
}

int possible(int s, int state,vector<string> &a) {
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < 7; ++j) {
			if ((a[i][j] == '1') && (state & (1 << j))) {
				return -1;
			}
			if (m[s][j] != a[i][j]) {
				if ((m[s][j] == '1') && ((state & (1 << j)) == 0)) {
					return -1;
				}
				if (m[s][j] == '0') {
					return -1;
				}
			}
		}
		if (--s < 0) {
			s = 9;
		}
	}
	return s;
}

string solve(vector<string> &a) {
	bool found = false;
	string answer = "ERROR";
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 128; ++j) {
			int temp = possible(i, j, a);
			if (temp >= 0) {
				string may = dosolve(temp, j);
				if (!found) {
					answer = may;
					found = true;
				}
				else if (may != answer) {
					return "ERROR";
				}
			}
		}
	}
	return answer;
}

int main() {
	m[0] = "1111110";
	m[1] = "0110000";
	m[2] = "1101101";
	m[3] = "1111001";
	m[4] = "0110011";
	m[5] = "1011011";
	m[6] = "1011111";
	m[7] = "1110000";
	m[8] = "1111111";
	m[9] = "1111011";
	int T;
	FILE *infp, *outfp;
	infp = fopen( "A-small-attempt0.in","r" );
	outfp = fopen( "output.txt","w" );
	fscanf(infp, "%d", &T);
	for (int z = 1; z <= T; ++z) {
		int n;
		fscanf(infp, "%d", &n);
		vector<string> vec;
		char s[10];
		for (int i = 0; i < n; ++i) {
			fscanf(infp, "%s", s);
			vec.push_back(s);
		}
		string answer = solve(vec);
		fprintf(outfp, "Case #%d: %s\n",z,answer.c_str());
	}
	fclose(infp);
	fclose(outfp);
	return 0;
}
