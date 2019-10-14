#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sc second
#define fs first
#define mod 1000000007
using namespace std;

long long fakt[200005];
long long inv[200005];
long long dua[200005];
string baca;

long long pang(long long a,int b){
	if(b == 0) return 1;
	if(b == 1) return a;
	long long ret = pang(a, b/2);
	ret = (ret * ret) % mod;
	if(b % 2 == 1){
		ret = (ret * a) % mod;
	}
	return ret;
}

int main(){
	fakt[0] = 1;
	inv[0] = 1;
	fakt[1] = 1;
	inv[1] = 1;
	dua[0] = 1;
	dua[1] = 2;
	for(int i = 2; i <= 200000; i++){
		fakt[i] = (fakt[i - 1] * i) % mod;
		inv[i] = pang(fakt[i], mod - 2);
		dua[i] = (dua[i - 1] * 2) % mod;
	}

	int t; cin >> t;

	for(int i = 1; i <= t; i++){
		int n,m; cin >> n >> m;
		long long ret = fakt[2 * n];
		for(int j = 1; j <= m; j++){
			long long nyak = (fakt[m] * inv[j]) % mod;
			nyak = (nyak * inv[m - j]) % mod;
			nyak = (nyak * fakt[2 * n - j]) % mod;
			nyak = (nyak * dua[j]) % mod;
			if(j % 2 == 1){
				ret = (ret - nyak) % mod;
				ret = (ret + mod) % mod;
			}else{
				ret = (ret + nyak) % mod;
			}
		}
		printf("Case #%d: %lld\n",i,ret);
	}
}