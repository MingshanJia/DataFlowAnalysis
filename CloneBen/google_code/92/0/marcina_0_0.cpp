#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORD(i,a,b) for (int i=(a); i>=(b); --i)
#define FORE(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define debug(x) cerr << #x << " = " << x << "\n";
#define debugv(x) cerr << #x << " = "; FORE(it,(x)) cerr<< *it <<","; cerr<<"\n";
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset(x,0,sizeof x)
#define xx first
#define yy second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> vi;
#define MAXN 53
int T,N,p[MAXN];
int last[MAXN];
string s;
bool wol[MAXN];

int main(){
	cin >> T;
	FOR(cas,1,T){
	cin >> N;
	//in
	REP(i,N){
		last[i]=0;
		cin >> s;
		REP(j,N) if(s[j] == '1') last[i]=j;
	}
	//rozw
	REP(i,N) wol[i]=true;
	REP(i,N){
		FOR(j,last[i],N-1) if(wol[j]){
			wol[j]=false;
			p[i]=j;
//			cout << i << " -> " << j << endl;
			break;
		}
	}
	int res=0;
	REP(i,N) REP(j,i) if(p[i] < p[j]) res++;
	//out
		cout << "Case #" << cas << ": " << res << endl;
	}
	return 0;
}
