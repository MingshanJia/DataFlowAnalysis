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
        vector<pair<ll, ll>> v;
        For(i, L) {
            ll n, e;
            scanf("%lld %lld", &n, &e);
            v.pb({e, n});
        }
        sort(v.rbegin(), v.rend());
        ll N = v.size();
        ll cnt = 0;
        vector<ll> mam(N, 0);
        For(j, N) {
            if (mam[j] == v[j].snd) continue;
            queue<ll> q;
            q.push(j);
            // db("aaa %d %lld\n", j, v[j].snd-mam[j]);
            cnt += v[j].snd - mam[j];
            while (!q.empty()) {
                ll kde = q.front();
                q.pop();
                ll c = v[kde].fst*v[kde].snd;
                ll first = kde+1;
                while (c > 0 && first < N) {
                    if (mam[first]<v[first].snd) {
                        ll kok = min(v[first].snd-mam[first], c);
                        // db("beriem: %d %lld\n", first, kok);
                        mam[first] += kok;
                        if (mam[first] == v[first].snd) q.push(first);
                        c -= kok;
                    }
                    first++;
                }
            }
        }

        // db("%lld %lld\n", cnt, v[0].fst);
        ll res = max(cnt, v[0].fst+1);

        printf("Case #%d: %lld\n", t+1, res);
    }
    return 0;
}
