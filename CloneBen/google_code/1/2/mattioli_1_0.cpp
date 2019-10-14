#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 4e5 + 5;
int L[MAX];
int R[MAX];
int K[MAX];
int X[MAX], Y[MAX], Z[MAX], A[MAX], B[MAX], C[MAX], M[MAX];
ll PL[MAX], PR[MAX];
int n, q;

inline int add(int a, int b, int m) {
    a += b;
    if(a >= m) {
        a -= m;
    }
    return a;
}

inline int mult(int a, int b, int m) {
    return (1LL * a * b) % m;
}

int main() {
    int t;
    scanf("%d", &t);
    int kase = 1;
    while(t--) {
        scanf("%d %d", &n, &q);
        scanf("%d %d %d %d %d %d", &X[1], &X[2], &A[1], &B[1], &C[1], &M[1]);
        scanf("%d %d %d %d %d %d", &Y[1], &Y[2], &A[2], &B[2], &C[2], &M[2]);
        scanf("%d %d %d %d %d %d", &Z[1], &Z[2], &A[3], &B[3], &C[3], &M[3]);
        fori(i, 3, n + 1) {
            X[i] = add(mult(A[1], X[i - 1], M[1]), add(mult(B[1], X[i - 2], M[1]), C[1], M[1]), M[1]);
            Y[i] = add(mult(A[2], Y[i - 1], M[2]), add(mult(B[2], Y[i - 2], M[2]), C[2], M[2]), M[2]);
            Z[i] = add(mult(A[3], Z[i - 1], M[3]), add(mult(B[3], Z[i - 2], M[3]), C[3], M[3]), M[3]);
        }
        ll total = 0;
        fori(i, 1, n + 1) {
            L[i] = min(X[i], Y[i]) + 1;        
            R[i] = max(X[i], Y[i]) + 1;        
            total += R[i] - L[i] + 1;
        }
        fori(i, 1, q + 1) {
            K[i] = Z[i] + 1;
        }
        sort(L + 1, L + n + 1);
        sort(R + 1, R + n + 1);
        fori(i, 1, n + 1) {
            PL[i] = PL[i - 1] + L[i];
        }
        fori(i, 1, n + 1) {
            PR[i] = PR[i - 1] + R[i];
        }
        ll ans = 0;
        fori(i, 1, q + 1) {
            if(K[i] > total) {
                continue;
            }
            ll Q = total - K[i] + 1;
            ll left = 1, right = (ll) 1e9;
            ll now = -1;
            while(left <= right) {
                ll mid = (left + right) / 2;
                int Lpos = upper_bound(L + 1, L + n + 1, mid) - L - 1;
                int Rpos = upper_bound(R + 1, R + n + 1, mid) - R - 1;
                ll S = (mid + 1) * Lpos - PL[Lpos];
                ll T = mid * Rpos - PR[Rpos];
                ll qty = S - T; 
                if(Q <= qty) {
                    now = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            ans += i * now;
        }
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}
