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
        ll L;
        scanf("%lld", &L);
        vector<ll> v;
        For(i, L) {
            ll n, e;
            scanf("%lld %lld", &n, &e);
            For(j, n) v.pb(e);
        }
        sort(v.rbegin(), v.rend());
        ll N = v.size();
        ll cnt = 0;
        vector<bool> mam(N, false);
        For(j, N) {
            if (mam[j]) continue;
            queue<ll> q;
            q.push(j);
            ll first = j+1;
            cnt++;
            while (!q.empty()) {
                ll kde = q.front();
                q.pop();
                ll c = 0;
                while (c < v[kde] && first < N) {
                    if (!mam[first] && v[first] < v[kde]) {
                        mam[first] = true;
                        q.push(first);
                        c++;
                    }
                    first++;
                }
            }
        }

        ll res = max(cnt, v[0]+1);

        printf("Case #%d: %lld\n", t+1, res);
    }
    return 0;
}
