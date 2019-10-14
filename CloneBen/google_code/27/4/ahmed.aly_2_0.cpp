/*

 E-Mail : ahmed.aly.tc@gmail.com

 Just For You :)

 */

#include <cstring>
#include <string.h>
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

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
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
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
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

ll I, J;

inline bool val(const int &i, const int &j) {
	if (i < 0 || j < 0 || i >= I || j >= J)
		return false;
	return true;
}

int N;
int n;

vector<ll> v;
int p,c;


bool val(ll num){
	vector<ll> v2=v;
	ll sum=0;
	while(v2.sz>=c){
		sort(rall(v2));
		rep(i,c)
			v2[i]--;
		rep(i,v2.sz)
			if(!v2[i])
				v2.erase(v2.begin()+i--);
		sum++;
	}
	return sum>=num;
	/*vector<ll> v2=v;
	ll sum=0;
	while(v2.sz>=c){
		sort(rall(v2));
		ll mn=v2[c-1];
		sum+=mn;
		rep(i,c)
			v2[i]-=mn;
		rep(i,v2.sz)
			if(!v2[i])
				v2.erase(v2.begin()+i--);
	}
	return sum>=num;*/
}

#define SMALL
//#define LARGE
int main() {
	freopen("a.txt", "rt", stdin);
#ifdef SMALL
	freopen("c-small-attempt0.in","rt",stdin);
	freopen("c-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("c-large.in","rt",stdin);
	freopen("c-large.out","wt",stdout);
#endif

	cin >> N;
	rep2(nn,1,N+1) {
		cin>>p>>c;
		v.clear();
		rep(i,p){
			cin>>I;
			if(I)
				v.pb(I);
		}
		sort(rall(v));
		ll st=0,en=(ll)1e18;
		while(st+1<en){
			ll md=(st+en)/2;
			if(val(md))
				st=md;
			else
				en=md;
		}
		if(val(en))
			st=en;
		cout<<"Case #"<<nn<<": "<<st<<endl;
	}
	return 0;
}
