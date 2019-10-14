#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll K = 1e9 + 7;

ll mu(ll a, ll n){
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

ll gt[200005], rev[200005];

ll combi(ll n, ll k){
	if (k < 0 || k > n) return 0;
	return gt[n] * rev[k] % K * rev[n-k] % K;
}

int main()
{//IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    gt[0] = rev[0] = 1;
    FOR (i, 1, 200000){
    	gt[i] = gt[i-1] * 1ll * i % K;
    	rev[i] = mu(gt[i], K-2);
    }
    int t;
    cin >> t;
    FOR (z, 1, t){
	    int n, m;
	    cin >> n >> m;
	    ll res = gt[2 * n];

	    FOR (i, 1, m){
	    	ll Q = 0;
	    	Q = combi(2 * n - i, i) * gt[i] % K * mu(2, i) % K * gt[2 * n - 2 * i] % K * combi(m, i) % K;
	    	if (i % 2 == 0){
	    		res = (res + Q) % K;
	    	}
	    	else{
	    		res = (res - Q + K) % K;
	    	}
	    }
	    cout << "Case #" << z << ": " << res << endl;
	}

        
        return 0;
}