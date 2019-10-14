#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

int A[110][110],r,c;

inline bool check(VVI &V, int j, int k)
{
	if(j<0 || j>=r || k<0 || k>=c || V[j][k] == 0) return 1;
	if(j>0 && j<r-1 && V[j-1][k] && V[j+1][k]) return 0;
	if(k>0 && k<c-1 && V[j][k-1] && V[j][k+1]) return 0;
	return 1;
}

inline int f(VVI &v, int i, int j, int cnt)
{
	if(i==r) return cnt;
	int ni=i,nj=j;
	if(nj < c-1) nj++;
	else ni++, nj = 0;
	int mx = f(v,ni,nj,cnt);
	v[i][j] = 1;
	if(check(v,i,j) && check(v,i-1,j) && check(v,i,j-1)) mx = max(f(v,ni,nj,cnt+1),mx);
	v[i][j] = 0;
	return mx;
}

int main()
{
	SET(A,-1);
	int T,test=0; si(T); while(T--)
	{
		test++;
		int n,ans=0; si(r); si(c); n = r*c;
		if(A[r][c] == -1)
		{
			if(r<3 && c<3)
			{
				VVI V(r,VI(c,0));
				A[r][c] = f(V,0,0,0);
			}
			else
			{
				if(c >= 3)
				{
					int ans=0;
					for(int i=0; i<r; i++)
					{
						ans += 2*(c/3);
						int x = c%3;
						if((i%3)==0) ans += x;
						if((i%3)==1) ans += (x==2);
						if((i%3)==2) ans += (x>0);
					}
					A[r][c] = max(A[r][c],ans);
					if(r == 2) ans = 2*(2*(c/3) + (c%3));
					A[r][c] = max(A[r][c],ans);
				}
				if(r >= 3)
				{
					swap(r,c);
					int ans=0;
					for(int i=0; i<r; i++)
					{
						ans += 2*(c/3);
						int x = c%3;
						if((i%3)==0) ans += x;
						if((i%3)==1) ans += (x==2);
						if((i%3)==2) ans += (x>0);
					}
					swap(r,c);
					A[r][c] = max(A[r][c],ans);
					swap(r,c);
					if(r == 2) ans = 2*(2*(c/3) + (c%3));
					swap(r,c);
					A[r][c] = max(A[r][c],ans);
				}
			}
		}
		printf("Case #%d: %d\n",test,A[r][c]);
	}
	return 0;
}
