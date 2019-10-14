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

LL powX(LL x,LL n){
	LL y=1;
	for( ; n!=0 ; x=(x*x) , n/=2) if(n&1) y*=x;
	return y;
}
struct Trie{
	bool ispre;
	Trie* chd[2];
	Trie(){
		chd[0] = NULL; chd[1] = NULL;
		ispre = false;
	}
};
Trie* root;
LL res=0;
int n;
void dfs(Trie* nd,int dep){
	if(nd==NULL) return;
	if(nd->ispre){
		res-=powX(2,n-dep);
		return;
	}
	for(int i=0 ; i<2 ; i++) dfs(nd->chd[i],dep+1);
}
int main(){
	Sync_Off
	int t; cin >> t;
	int cas=1;
	while(t--){
		cout << "Case #" << (cas++) << ": ";
		root = new Trie();
		int p; cin >> n >> p;
		res = powX(2,n);
		for(int i=1 ; i<=p ; i++){
			string s; cin >> s;
			int m = s.size();
			Trie* itr = root;
			for(int j=0 ; j<m ;  j++){
				int bit = (s[j]=='R' ? 1 : 0);
				if(itr->chd[bit]==NULL) itr->chd[bit] = new Trie();
				itr = itr->chd[bit];
			}
			itr->ispre = true;
		}
		dfs(root,0);
		cout << res << "\n";
	}
}
