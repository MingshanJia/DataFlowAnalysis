#define LOCAL

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double D;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;

#define rd(x) scanf("%d",&x)
#define rd2(x,y) scanf("%d %d",&x,&y)
#define rl(x) scanf("%lld",&x)
#define rl2(x,y) scanf("%lld %lld",&x,&y)
#define wd(x) printf("%d" ,x)
#define wd2(x,y) printf("%d %d",x,y)
#define wl(x) printf("%lld",x)
#define wl2(x,y) printf("%lld %lld",x,y)
#define PC(x) putchar(x)
#define GC() getchar()
#define NL printf("\n")
#define SP printf(" ")

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define fr(i,s,e) for(int i=s;i<e;i++)
#define frr(i,s,e) for(int i=s-1;i>=e;i--)
#define frv(i,a) for(int i = 0;i<(int)a.size();i++)
#define frvr(i,a) for(int i = a.size()-1;i>=0;i--)
#define tr(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end();i++)

#ifdef LOCAL
#define E1(a) cout<<#a<<":" <<a<<endl;
#define E2(a,b) cout<<#a<<":" <<a<<" " <<#b<<":" <<b<<endl;
#define E3(a,b,c) cout<<#a<<":" <<a<<" " <<#b<<":" <<b<<" "<<#c<<":"<<c<<endl;
#define E4(a,b,c,d) cout<<#a<<":" <<a<<" " <<#b<<":" <<b<<" "<<#c<<":"<<c<< " "<<#d<< ":"<<d<<endl;
#define INP freopen("input","r",stdin);
#define OUT freopen("output","w",stdout);
#else
#define E1(a)
#define E2(a,b)
#define E3(a,b,c)
#define E4(a,b,c,d)
#define INP
#define OUT
#endif

#define mod 1000000007
#define maxn 100009
#define maxr 100009






//check 1,23,
int main(){
//	freopen("input","r",stdin);
	freopen("input.in","r",stdin);
	freopen("output","w",stdout);
	int t;
	rd(t);
	int cc = 0;
	while(t--){
		cc++;
		int e,n;
		rd2(e,n);
		multiset<int> st;
		int ans = 0;
		fr(i,0,n){
			int a;
			rd(a);
			st.insert(a);
		}

		int h = 0;
		while(!st.empty()){
			int x = *st.begin();
			if(e>x){
				e -= x;
				st.erase(st.begin());
				h++;
			}
			else if(h>0){
				h--;
				multiset<int>::iterator it = st.end();
				it--;
				e += *it;
				st.erase(it);
			}
			else break;
			ans = max(ans,h);
		}



		cout<<"Case #"<<cc<<": "<<ans<<endl;

	}
}
