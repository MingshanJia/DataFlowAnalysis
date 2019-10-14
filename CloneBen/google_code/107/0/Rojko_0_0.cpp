#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define db(...) printf(__VA_ARGS__);
#else
#define db(...)
#endif

#define fst first
#define snd second
#define pb push_back
#define mp(x,y) make_pair(x,y)
#define For(i,n) for(int i = 0; i<n; ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
    int T;
    scanf("%d", &T);
    For(t,T) {
        int k;
        scanf("%d", &k);
        vl v(k);
        For(i,k) {
            scanf("%lld", &v[i]);
        }
        sort(v.begin(), v.end());
        ll suc = 0;
        For(i,k) {
            ll x = i/2;
            suc += (v[i]-x)*(v[i]-x);
        }

        printf("Case #%d: %lld\n", t+1, suc);
    }
    return 0;
}
