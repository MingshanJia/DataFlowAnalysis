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

#define MAXM 100
int T,n,k,res;
int pom[MAXM][MAXM];
bool kraw[MAXM][MAXM];

template<int MAXN>
struct MaxFlow1{
const static int INF=((int)1E9);
typedef vector<int>::iterator iter;
int C,N,x,y;
vector<int> kraw[MAXN+7];
int n,vis[MAXN+7],in,out;
int f[MAXN+7][MAXN+7],c[MAXN+7][MAXN+7];
MaxFlow1(int n,int in,int out):n(n+1),in(in),out(out){CLR(f); CLR(c); CLR(vis);}

inline void add(int a,int b){kraw[a].PB(b); kraw[b].PB(a); c[a][b]++;}

bool go(int x){
        vis[x]=true;
        if(x == out) return true;
        FORE(i,kraw[x]) if(f[x][*i]<c[x][*i] && !vis[*i] && go(*i)){f[x][*i]++; f[*i][x]--; return true;}
        return false;
        }

        int flow(){
                int res=0;
                while(go(in)){CLR(vis); res++;}
                return res;
        }
};

int main(){
	cin >> T;
	FOR(cas,1,T){
		//in
		cin >> n >> k;
		REP(i,n) REP(j,k) cin >> pom[i][j];
		//kraw
		REP(i,n) REP(j,n){
			kraw[i][j]=true;
			REP(x,k) if(pom[i][x] <= pom[j][x]) kraw[i][j]=false;
		}
		//rozw
		FOR(ile,0,n){
			int in=2*n+1,out=2*n+2,spe=2*n+3;
			MaxFlow1<207> flow(spe+1,in,out);
			FOR(i,1,n) flow.add(in,i);
			FOR(i,1,n) flow.add(spe,n+i);
			FOR(i,1,n) FOR(j,1,n) if(kraw[i-1][j-1]) flow.add(i,n+j);
			FOR(i,1,n) flow.add(n+i,out);
			REP(q,ile) flow.add(in,spe);
			int f=flow.flow();
//			cout << "f " << f << endl;
			if(f == n){
				res=ile;
				break;
			}
		}
		cout << "Case #" << cas << ": " << res << endl;
	}
	return 0;
}
