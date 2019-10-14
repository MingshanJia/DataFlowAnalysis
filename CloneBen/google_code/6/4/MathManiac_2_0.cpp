#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long double ld;
typedef long long int LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define Sync_Off ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define X first
#define Y second
#define trace(x) cout << #x" is " << (x) << endl
#define trace2(x,y) cout << #x" is " << (x) << ","#y" is " << (y) << endl

LL MOD = 1000000007;
LL powM(LL x,LL n){
	LL y=1;
	for( ; n!=0 ; x=(x*x)%MOD , n/=2) if(n&1) y = (y*x)%MOD;
	return y;
}
inline LL inv(LL x){ return powM(x,MOD-2); }
inline LL mul(LL x,LL y){ return (x*y)%MOD; }
inline LL divd(LL x,LL y){ return (x*inv(y))%MOD; }

const int N = 300005;
LL fac[N];
void pre(){
	fac[0]=1;
	for(int i=1 ; i<N ; i++) fac[i] = (fac[i-1]*i)%MOD;
}
LL nCr(LL n,LL r){
	if(r>n) return 0;  
	return divd(fac[n],mul(fac[r],fac[n-r]));
}
int main(){
	Sync_Off
	pre();
	int t; cin >> t;
	int cas=1;
	while(t--){
		cout << "Case #" << (cas++) << ": ";
		LL res=0;
		LL n,m; cin >> n >> m;
		for(int k=0 ; k<=m ; k++){
			LL val = mul(mul(powM(2,k),nCr(m,k)),fac[2*n-k]);
			if(k&1) res = (res+MOD-val)%MOD;
			else res = (res+val)%MOD;
		}
		cout << res << "\n";
	}
}
