#include <cstdio>
#include <tuple>
#include <cassert>
#include <algorithm>
using namespace std;

const int N = 5050;
int E[N][2];
int out[N][2];
int inT[N][2];
int inE[N][2];
int inpt[N];
int L[N][2], D[N][2];
bool used[N][2];

int n;

struct dsu {
    vector<int> par;
    vector<int> rnk;
    dsu(int n) {
        par.resize(n);
        rnk.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    bool merge(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return false;
        }
        if (rnk[a] == rnk[b]) {
            rnk[b]++;
        }
        if (rnk[a] > rnk[b]) {
            swap(a, b);
        }
        par[a] = b;
        return true;
    }
    int get(int x) {
        return (x == par[x]) ? x : (par[x] = get(par[x]));
    }
};

int zaz(int a, int b) {
    assert(0 <= a && a < 24);
    assert(0 <= b && b < 24);
    return (a <= b) ? b - a : 24 + b - a;
}

int go(int x, int vis = 0, int curt = 0)
{
    if (x == 0 && vis == 2 * n) {
        return curt;
    }
    int best = 1000 * 1000 * 1000;
    for (int e = 0; e < 2; e++) {
        if (used[x][e])
            continue;
        int z = curt % 24;
        int ncurt = 0;
        if (z <= L[x][e]) {
            ncurt = curt + L[x][e] - z + D[x][e];
        } else {
            ncurt = curt + L[x][e] - z + D[x][e] + 24;
        }
        used[x][e] = true;
        best = min(best, go(out[x][e], vis + 1, ncurt));
        used[x][e] = false;
    }
    return best;
}

int mat[N][2];
int curm[N];
int add[N];

void solve(int cs) {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        inpt[i] = 0;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d %d %d", &out[i][j], &L[i][j], &D[i][j]);
            --out[i][j];
            int k = out[i][j];
            inT[k][inpt[k]] = (L[i][j] + D[i][j]) % 24;
            inE[k][inpt[k]] = 2 * i + j;
            inpt[k]++;
            sum += D[i][j];
        }
    }
    //int ans = go(0);

    dsu D(2 * n);

    vector<tuple<int, int, int>> prs;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (i != 0)
                mat[i][j] = zaz(inT[i][0 ^ j], L[i][0]) + zaz(inT[i][1 ^ j], L[i][1]);
            else {
                int v1 = zaz(inT[i][0 ^ j], L[i][0]) + L[i][1];
                int v2 = zaz(inT[i][1 ^ j], L[i][1]) + L[i][0];
                mat[i][j] = min(v1, v2);
            }
        }
        if (mat[i][0] < mat[i][1])
            curm[i] = 0, sum += mat[i][0];
        else
            curm[i] = 1, sum += mat[i][1];
        add[i] = abs(mat[i][1] - mat[i][0]);
        D.merge(inE[i][0], 2 * i + (0 ^ curm[i]));
        D.merge(inE[i][1], 2 * i + (1 ^ curm[i]));
        prs.emplace_back(add[i], D.get(inE[i][0]), D.get(inE[i][1]));
    }

    sort(prs.begin(), prs.end());
    for (auto pr : prs) {
        int c, a, b;
        tie(c, a, b) = pr;
        if (D.merge(a, b))
            sum += c;
    }

    printf("Case #%d: %d\n", cs, sum);

}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
