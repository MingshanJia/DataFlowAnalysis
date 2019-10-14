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

char s[5000005];
int a[5000005];
ll S[5000005];
int main()
{//IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t){
	    int n;
	    cin >> n;
	    FOR (i, 1, n){
	    	cin >> s[i];
	    	a[i] = s[i] - '0';
	    }
	    FOR (i, 1, n){
	    	S[i] = S[i-1] + a[i];
	    }
	    int m = (n + 1) / 2;
	    ll res = 0;
	    for (int i = 1; i + m - 1 <= n; i++){
	    	res = max(res, S[i + m - 1] - S[i-1]);
	    }
	    
	    cout << "Case #" << z << ": " << res << endl;
	}
		
         return 0;
}