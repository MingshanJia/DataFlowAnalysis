#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <map>

typedef long long llint;

using namespace std;

int N, Q;
llint X1, X2, A1, B1, C1, M1;
llint Y1, Y2, A2, B2, C2, M2;
llint Z1, Z2, A3, B3, C3, M3;
int L[400002], R[400002];
int K[100002];

map<int,int> mp;
vector<pair<int,int>> vec;
vector<int> kvec;

int main()
{
    int T;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0-output.txt", "w", stdout);

    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d %d", &N, &Q);
        scanf("%lld %lld %lld %lld %lld %lld", &X1, &X2, &A1, &B1, &C1, &M1);
        scanf("%lld %lld %lld %lld %lld %lld", &Y1, &Y2, &A2, &B2, &C2, &M2);
        scanf("%lld %lld %lld %lld %lld %lld", &Z1, &Z2, &A3, &B3, &C3, &M3);
        L[1] = min(X1, Y1) + 1;     R[1] = max(X1, Y1) + 1;
        L[2] = min(X2, Y2) + 1;     R[2] = max(X2, Y2) + 1;
        K[1] = Z1 + 1; K[2] = Z2 + 1;

        for(int i=3;i<=N;i++)
        {
            int tX, tY;
            tX = X2;
            X2 = (A1 * X2 + B1 * X1 + C1) % M1;
            X1 = tX;

            tY = Y2;
            Y2 = (A2 * Y2 + B2 * Y1 + C2) % M2;
            Y1 = tY;

            L[i] = min(X2, Y2)+1;
            R[i] = max(X2, Y2)+1;
        }

        for(int i=3;i<=Q;i++)
        {
            int tZ = Z2;
            Z2 = (A3 * Z2 + B3 * Z1 + C3) % M3;
            Z1 = tZ;
            K[i] = Z2 + 1;
        }
        mp.clear();

        vec.clear();
        for(int i=1;i<=N;i++)
        {
            vec.push_back({R[i], 1});
            vec.push_back({L[i]-1, -1});
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());

        kvec.clear();
        for(int i=1;i<=Q;i++)
            kvec.push_back(K[i]);
        sort(kvec.begin(), kvec.end());

        llint cnt, inc;
        int idx, idxK;

        cnt = inc = 0;
        idx = idxK = 0;
        for(int i=1000000000;i>=0;i--)
        {
            while(idx < vec.size() && vec[idx].first==i)
            {
                inc += vec[idx].second;
                idx++;
            }
            
            cnt += inc;

            while(idxK < kvec.size() && kvec[idxK] <= cnt)
            {
                mp[kvec[idxK]] = i;
                idxK++;
            }
        }
        while(idxK < kvec.size())
        {
            mp[kvec[idxK]] = 0;
            idxK++;
        }

        llint ans = 0;
        for(int i=1;i<=Q;i++)
            ans += i*mp[K[i]];

        printf("Case #%d: %lld\n", test_case, ans);
    }

    return 0;
}