#include <cstdio>
#include <string>

using namespace std;

long long to10(string s, string dig) {
	int b = dig.size();
	long long n = 0, d = 1;
	for (int i = s.size()-1; i >= 0; i--) {
		int p = dig.find(s[i]);
		n += d*p;
		d *= b;
	}
	return n;
}

string from10(long long i, string dig) {
	int b = dig.size();

	string r;
	while (i) {
		r += dig[i%b];
		i /= b;
	}
	reverse(r.begin(), r.end());
	return r;
}

int main(int argc, char **argv) {
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char nm[50], d0[100], d1[100];
		scanf(" %49s %99s %99s", nm, d0, d1);
		long long n = to10(nm, d0);
		string r = from10(n, d1);
		printf("Case #%d: %s\n", i+1, r.c_str());
	}
	return 0;
}

