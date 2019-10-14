/*

 E-Mail : ahmed.aly.tc@gmail.com

 Just For You :)

 */

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>

using namespace std;

#include <ext/hash_set>
#include <ext/hash_map>

using namespace __gnu_cxx;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;

inline int comp(const double &a, const double &b) {
	if (fabs(a - b) < eps)
		return 0;
	return a > b ? 1 : -1;
}

int di[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dj[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int diK[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int djK[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int I, J;

inline bool val(const int &i, const int &j) {
	if (i < 0 || j < 0 || i >= I || j >= J)
		return false;
	return true;
}

int N;
int n;

//#define SMALL
//#define LARGE

string maze[55];

int g[55][55];

int main() {
	freopen("a.txt", "rt", stdin);
	freopen("b.txt", "wt", stdout);
#ifdef SMALL
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small.out", "wt", stdout);
#endif
#ifdef LARGE
	freopen("C-large.in", "rt", stdin);
	freopen("C-large.out", "wt", stdout);
#endif

	cin >> N;
	rep2(nn,1,N+1) {
		cout << "Case #" << nn << ": ";
		cin >> J >> I;
		mem(g,0);
		rep(i,I) {
			cin >> maze[i];
			rep(j,J)
				if (maze[i][j] != 'G' && maze[i][j] != 'S')
					g[i][j] = 1;
		}
		/*rep2(j,1,J)
			g[0][j] += g[0][j - 1];
		rep2(i,1,I)
			g[i][0] += g[i - 1][0];
		rep2(i,1,I) rep2(j,1,J)
				g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
		rep(i,I){
			break;
			rep(j,J)
				cout<<g[i][j]<<" ";
			cout<<endl;
		}*/
		int mx = 0,ii,jj;
		rep(i1,I) rep(j1,J) rep2(i2,i1,I) rep2(j2,j1,J) {
                        bool ok=1;
                        rep2(a,i1,i2+1)
                            rep2(b,j1,j2+1)
                                if(g[a][b])
                                    goto EE;
                        
						ii = i2 - i1 + 1;
						jj = j2 - j1 + 1;
						mx = max(mx, ii * jj);
						EE:;
						/*int x = g[i2][j2];
						if (i1)
							x -= g[i1 - 1][j2];
						if (j1)
							x -= g[i2][j1 - 1];
						if (i1 && j1)
							x += g[i1 - 1][j1 - 1];
						if (!x)
							mx = max(mx, ii * jj);
						if(ii*jj==28 && !x)
							cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<" "<<x<<endl;*/
					}
		cout << mx << endl;

#ifdef SMALL
		cerr << nn << " of " << N << " is done." << endl;
#endif
#ifdef LARGE
		cerr << nn << " of " << N << " is done." << endl;
#endif
	}
	return 0;
}
