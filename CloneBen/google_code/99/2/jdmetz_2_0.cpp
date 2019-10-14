#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

int dbg;

string readLine() {
	char sz[1000];
	fgets(sz, 1000, stdin);
	int l = strlen(sz);
	if (sz[l-1] == '\n') sz[l-1] = 0;
	return sz;
}

int readIntLine() {
	string s = readLine();
	return atoi(s.c_str());
}

vector<int> readVI() {
	int n;
	scanf("%d ", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d ", &v[i]);
	return v;
}

double solveIt(vector<vector<double> > &p, int M) {
/*	for (int i = 0; i < p.size(); i++) sort(p[i].rbegin(), p[i].rend());
	sort(p.rbegin(), p.rend());

	double pc = 1.0, ip;
	for (int i = 0; i < p.size(); i++) pc *= p[i][0];
*/	
if (dbg)	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < 4; j++) printf("%.6lf ", p[i][j]);
		printf("\n");
	}
	int ct = 1<<(p.size()*2);
	vector<double> ps(ct, 0.0);

	for (int i = 0; i < ct; i++) {
		double q = 1.0;
		for (int j = 0; j < p.size(); j++) q *= p[j][(i>>(j*2))&3];
		ps[i] = q;
	}
	sort(ps.rbegin(), ps.rend());

	double pc = 0.0;
	if (M > ct) M = ct;
	for (int i = 0; i < M; i++) {
		pc += /*(1.0-pc)**/ps[i];
	}

	return pc;
}

int main(int argc, char ** /*argv*/) {
	dbg = argc-1;
	int CCT = readIntLine();
	for (int cn = 1; cn <= CCT; cn++) {
		int Q, M;
		scanf("%d %d ", &M, &Q);
		vector<vector<double> > p(Q, vector<double>(4));
		for (int i = 0; i < Q; i++) scanf("%lf %lf %lf %lf", &p[i][0], &p[i][1], &p[i][2], &p[i][3]);

		double res = solveIt(p, M);
		printf("Case #%d: %.15lf\n", cn, res);
	}
	return 0;
}

