#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
#define INF 1000000007
typedef long long int lli;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef vector<int> VI;

#define MAXN 1007

int N,W,L,resx[MAXN],resy[MAXN],roz[MAXN];
vector<P> V;

bool col1d(int x, int s, int xx, int ss){
	return !(x + s <= xx - ss || xx + ss <= x - s);
}

bool col(int x, int y, int s, int xx, int yy, int ss){
	return col1d(x,s,xx,ss) && col1d(y,s,yy,ss);
}

bool ok(int n, int x, int y) {
	if(x < 0 || x > W || y < 0 || y > L)
		return false;
	REP(i,n) {
		int nr = V[i].Y;
		if(col(x, y, V[n].X, resx[nr], resy[nr], roz[nr]))
			return false;
	}
	return true;
}

int main(){ 
	int T;
	cin >> T;
	FOR(t,1,T){
		//in
		V.clear();
		cin >> N >> W >> L;
		FOR(i,1,N){
			cin >> roz[i];
			V.PB(P(roz[i], i));
		}
		sort(ALL(V));
		reverse(ALL(V));
		//sol
		priority_queue<P> Q;
		Q.push(P(0,0));
		REP(n,N){
			while(1){
				if(Q.empty()){
					cout << "fail" << endl;
					return 1;
				}
			P p = Q.top(); Q.pop();
			int x = -p.X, y=-p.Y;
			int s = V[n].X;
			int nr = V[n].Y;
			if(x) x += s;
			if(y) y += s;
			if(ok(n,x,y)) {
				resx[nr] = x;
				resy[nr] = y;
				//cout << "put " << s << " at " << x << " " << y << endl;
				Q.push(P(-max(0, x+s), -max(0, y-s)));
				Q.push(P(-max(0, x-s), -max(0, y+s)));
				break;
			}
			}
		}
		//res
		cout << "Case #" << t << ": ";
		FOR(i,1,N) cout << resx[i] << " " << resy[i] << " ";
		cout << endl;
	}
    return 0;
}
