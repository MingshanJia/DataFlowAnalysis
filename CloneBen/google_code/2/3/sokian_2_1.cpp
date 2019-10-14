#include <bits/stdc++.h>

#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define clr(x) memset((x), 0, sizeof((x)));
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;
typedef unsigned long long ull;

template<class T>
bool remin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool remax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

ll gcd(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef ld ptdata;

struct pt {
    ptdata x, y;

    pt() { }

    pt(ptdata x, ptdata y) : x(x), y(y) { }

    inline pt operator-(const pt &r) const {
        return pt(x - r.x, y - r.y);
    }

    inline pt operator+(const pt &r) const {
        return pt(x + r.x, y + r.y);
    }

    inline pt operator*(const ptdata &r) const {
        return pt(x * r, y * r);
    }

    inline ptdata sqlen() const {
        return abs(x * x + y * y);
    }

    inline ld len() const {
        return sqrt(sqlen());
    }

    inline bool operator<(const pt &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }

    inline bool operator==(const pt &r) const {
        return x == r.x && y == r.y;
    }
};

ostream &operator<<(ostream &os, const pt &p) {
    return os << "(" << p.x << "," << p.y << ")";
}

inline ptdata cross(const pt &l, const pt &r) {
    return l.x * r.y - l.y * r.x;
}

inline ptdata dot(const pt &l, const pt &r) {
    return l.x * r.x + l.y * r.y;
}


ll pwmod(ll a, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

template<typename T>
inline T sqr(T x) {
    return x * x;
}

const int N = 100;
int n;

struct Mat {
    double a[N][N];
    double p[N][N];

    Mat operator * (const Mat &r) const {
        Mat ret{};
        memset(ret.a, 0, sizeof(ret.a));
        memset(ret.p, 0, sizeof(ret.p));
        forn(i, n) {
            forn(j, n) {
                forn(k, n) {
//                    ret.a[i][j] += a[i][k] * r.p[k][j] + r.a[k][j] * p[i][k];
//                    ret.a[i][j] += a[i][k] * p[i][k] + r.a[k][j] * r.p[k][j];
                    ret.a[i][j] += (a[i][k] + r.a[k][j]) * p[i][k] * r.p[k][j];
                    ret.p[i][j] += p[i][k] * r.p[k][j];
                }
                if (ret.p[i][j] > 1e-10) {
                    ret.a[i][j] /= ret.p[i][j];
                }
            }
        }
        return ret;
    }
};

Mat pw(Mat a, int k) {
    Mat ret{};
    memset(ret.a, 0, sizeof(ret.a));
    memset(ret.p, 0, sizeof(ret.p));
    forn(i, n) {
        ret.p[i][i] = 1.0;
    }
    while (k) {
        if (k & 1) ret = ret * a;
        a = a * a;
        k >>= 1;
    }
    return ret;
}

void solve(int test) {
    cout << "Case #" << test << ": ";
    int m, p;
    cin >> n >> m >> p;
    vector<vector<int> > a(n, vector<int>(n, INT_MAX >> 1));
    forn(i, n) {
        a[i][i] = 0;
    }
    forn(i, m) {
        int v, u, d;
        cin >> v >> u >> d;
        --v, --u;
        a[v][u] = a[u][v] = d;
    }
    forn(k, n) {
        forn(i, n) {
            forn(j, n) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    Mat w{};
    memset(w.a, 0, sizeof(w.a));
    memset(w.p, 0, sizeof(w.p));
    forn(i, n) {
        forn(j, n) {
            w.a[i][j] = a[i][j];
            w.p[i][j] = 1.0 / (n - 1);
        }
        w.p[i][i] = 0.0;
    }
    w = pw(w, p);
    double ans = 0;
    forn(i, n) {
        ans += w.a[0][i] * w.p[0][i];
    }
    cout << setprecision(10) << fixed << ans << "\n";
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double cl0 = clock();

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    cerr << "Time: " << (clock() - cl0) / CLOCKS_PER_SEC << std::endl;
    return 0;
}
