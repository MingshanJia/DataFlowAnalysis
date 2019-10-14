#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <sstream>
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
typedef vector<int> vi;
#define MAXN 53
int T,R,C,F;
char pl[MAXN][MAXN];
#define INF 10000

int naj[MAXN][MAXN][MAXN][MAXN],res;

struct S{
	int w,c,l,r;
	S(int w,int c,int l,int r):w(w),c(c),l(l),r(r){};
	int& war(){return naj[w][c][l][r];}
	bool operator<(const S& s) const{return false;}
};
typedef pair<int, S> P;

priority_queue<P> Q;

void relaks(S s,int war){
	if(s.war() > war){
		s.war()=war;
		Q.push(P(-s.war(),s));
	}
}

bool zak(int l,int c,int r){
	return l<=c && c<=r && l != 0;
}

bool ok(int w,int c,int l,int r){
	return pl[w][c] == '#' && (pl[w-1][c] == '.' || zak(l,c,r));
}

int main(){
	cin >> T;
	FOR(cas,1,T){
		//in
		REP(i,MAXN) REP(j,MAXN) pl[i][j]='#';
		cin >> R >> C >> F;
		FOR(i,1,R) {cin >> &pl[i][1]; pl[i][C+1]='#';}
	//	cout << R << " " << C << " " << F << endl;
	//	REP(i,R+2){
	//		REP(j,C+2) cout << pl[i][j];
	//		cout << endl;
	//	}
		//rozw
		res=INF;
		while(!Q.empty()) Q.pop();
		REP(i,MAXN) REP(j,MAXN) REP(k,MAXN) REP(l,MAXN) naj[i][j][k][l]=INF;
		Q.push(P(0,S(1,1,0,0)));
		naj[1][1][0][0]=0;
		while(!Q.empty()){
			P p=Q.top(); Q.pop();
			S v=p.yy;
			if(-v.war() != p.xx) continue;
//			cout << v.w << " " << v.c << " " << v.l << "-" << v.r << "=" << v.war() << endl;
			if(v.w == R){res=v.war(); break;}
			//ruch zwykly
			FOR(c,v.c-1,v.c+1){
				if(pl[v.w][c] == '#' && !zak(v.l,c,v.r)) continue;
				int w=v.w;
				while(pl[w+1][c] == '.') w++;
				if(w-v.w > F) continue;
				int l=v.l,r=v.r;
				if(w != v.w) l=r=0;
				relaks(S(w,c,l,r),v.war());
			}
			//kopanie
			FOR(c,v.c-1,C){
				if(!ok(v.w+1,c,v.l,v.r)) break;
				if(!ok(v.w+1,c+1,v.l,v.r)) break;
				int w=v.w+1;
				while(pl[w+1][c] == '.') w++;
				if(w-v.w > F) continue;
				//cout << "OK"<< w << " " << c << endl;
				int l=v.c-1,r=c;
				if(w != v.w+1) l=r=0;
				relaks(S(w,c,l,r),v.war()+c-v.c+2);
			}
			FORD(c,v.c+1,1){
				if(!ok(v.w+1,c,v.l,v.r)) break;
				if(!ok(v.w+1,c-1,v.l,v.r)) break;
				int w=v.w+1;
				while(pl[w+1][c] == '.') w++;
				if(w-v.w > F) continue;
				int l=c,r=v.c+1;
				if(w != v.w+1) l=r=0;
				relaks(S(w,c,l,r),v.war()+v.c-c+2);
			}
		}
		cout << "Case #" << cas << ": ";
		if(res == INF) cout << "No" << endl;
		else cout << "Yes " << res << endl;
//		return 0;
	}
	return 0;
}
