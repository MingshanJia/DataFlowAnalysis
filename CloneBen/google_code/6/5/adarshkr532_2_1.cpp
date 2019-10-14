#include<bits/stdc++.h>
using namespace std;

#define ld double
#define int long long int
#define pi pair<ld,ld>
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define inf 1e9
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#ifndef LOCAL
#define endl'\n'
#endif

const int N = 200005;

int f[N];

int power(int a, int b){
	int ans = 1;
	while(b > 0){
		if(b&1)
			ans = (ans*a)%mod;
		a = (a*a) % mod;
		b >>= 1;
	}
	return ans;
}

int C(int n, int r){
	int num = f[n];
	int den = (f[r]*f[n-r])%mod;
	num = (num*power(den, mod-2))%mod;
	return num;
}

signed main()
{
	freopen("C-large.in","r",stdin);
	freopen("out1.txt","w",stdout);
	IOS;
	int t, n;
	f[0] = 1;
	for(int i = 1; i < N; i++)
		f[i] = (f[i-1]*i) % mod;
	cin >> t;
	for(int z = 1; z <= t; z++){
		int n, m;
		cin >> n >> m;
		int ans = f[2*n];
		int sub = 0;
		for(int i = 1; i <= m; i++){
			int p = (C(m, i)*power(2, i))%mod;
			p = (p*f[2*n-i]) % mod;
			if(i&1)
				sub = (sub + p)%mod;
			else
				sub = (sub - p + mod)%mod;
		}
		cout << "Case #" << z << ": " << (ans - sub + mod)%mod << endl;
	}
 	return 0;
}