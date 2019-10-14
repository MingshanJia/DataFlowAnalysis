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

string s[105];

int main()
{//IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t){
		int n, p;
		cin >> n >> p;
		FOR (i, 1, p){
			cin >> s[i];
		}    

		ll res = 0;

		FOR (i, 1, p){
			bool q = 0;
			FOR (j, 1, p){
				if (j == i || s[j].length() > s[i].length()) continue;
				bool qq = 0;
				FOR (k, 0, s[j].length()-1){
					if (s[i][k] != s[j][k]){
						qq = 1; break;
					}
				}
				if (qq) continue;
				else {
					q = 1;
					break;
				}
			}
			if (!q) res += (1LL<<(n-s[i].length()));
		}
		res = (1LL<<n) - res;
		cout << "Case #" << z << ": " << res <<endl;
	}
	
         return 0;
}