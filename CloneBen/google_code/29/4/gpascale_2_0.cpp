#include <queue>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <fstream>
using namespace std;
#define FOR(a,b,c) for(int a(b);a<(c);a++)
#define LL long long
#define NMAX 1005

LL ans[NMAX][NMAX];
bool neg1;

LL solve(int D, int B){
	LL &ret = ans[D][B];
	if(ret != -1) return ret;
	if(B == 0 || D == 0) return 0;
	if(D == 1) return 1;
	ret = 1 + solve(D-1,B-1) + solve(D-1,B);
	if(ret > 4294967296LL) neg1 = 1;
	return ret;
}

int tcase = 0;

int main(){
	ifstream fin("C.in");
	ofstream fout("C.out");
	int N; fin >> N;
	FOR(i,0,N){
		memset(ans,0xff,sizeof(ans));
		neg1 = 0;
		LL F, D, B;
		fin >> F >> D >> B;
		LL Fp = solve(D, B);
		if(neg1) Fp = -1;
		cout << neg1 << " " << Fp << endl;
		LL Bp = INT_MAX, Dp = INT_MAX;
		FOR(i,0,1005){
			if(solve(D, i) >= F){
				Bp = i;
				break;
			}
		}
		FOR(i,0,1005){
			if(solve(i, B) >= F){
				Dp = i;
				break;
			}
		}
		fout << "Case #" << ++tcase << ": " << Fp << " " << Dp << " " << Bp << endl;
	}
	return 0;
}
