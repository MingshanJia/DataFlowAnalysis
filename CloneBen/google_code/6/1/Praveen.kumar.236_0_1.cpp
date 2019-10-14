#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define M 1000000007 
#define mp make_pair
#define eps 1e-12
#define int long long
#define float long double
#pragma GCC optimize("Ofast")
#pragma unroll
#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#define _CRT_SECURE_NO_WARNINGS

int a[300010],b[300010],z=0,ans,c[311010],d[300010],mat[1001][1001],x,m,n;long double an[2000],S,D,S1,S2,X,Y,tim,te=0,tt=0,tt1=0;
string st1[1000001],st,st2,st3;char str[1000001],ch1[1000100],ch,ch2,ch3,*si;
 int modulo(int a,int b=M-2,int n=M){
    int x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%n;
        }
        y = (y*y)%n; // squaring the base
        b /= 2;
    }
    return x%n;
}
vector<int> g[300001];
vector<int> h[100001];
struct node{
mutable int v,i,n;
node(){}
node(int x,int y,int z=0)
{
v=x;i=y;n=z;
}
bool operator<(const node&y)const
{
if(v==y.v)
if(i!=y.i)return i<y.i; else return n<y.n;
else 
return v<y.v;
}
};
bool cmp(node x,node y)
{
if(x.i!=y.i)
return x.i<y.i;
else if(x.v!=y.v) return x.v>y.v;
else return x.n<y.n;
}
ostream& operator<<(ostream& o,node x)
{
o<<'('<<x.v<<','<<x.i;
if(x.n>0)
o<<','<<x.n;
o<<")\t";
return o;
}
template<class T >
ostream& operator<<(ostream& o,vector<T> v)
{
for(T x : v)o<<x<<' ';
o<<endl;
return o;
}
template<class T ,class T1>
ostream& operator<<(ostream& o,map<T,T1> v)
{
for(auto x : v)o<<x.first<<' '<<x.second<<endl;
o<<endl;
return o;
}
template<class T >
ostream& operator<<(ostream& o,set<T> v)
{
for(T x : v)o<<x<<' ';
o<<endl;
return o;
}
template<class T >
ostream& operator<<(ostream& o,multiset<T> v)
{
for(T x : v)o<<x<<' ';
o<<endl;
return o;
}
template<class T,class T2 >
ostream& operator<<(ostream& o,pair<T,T2> v)
{
o<<v.first<<' '<<v.second<<endl;
return o;
}
template<class T1,class T2>
T2 min(T1 a,T2 b)
{
return min((T2)a,b);
}
template<class T1,class T2>
T2 max(T1 a,T2 b)
{
return max((T2)a,b);
}

int vis[100001]={0};
 
class UF    {
public:
    int *id, cnt, *sz;
 
	// Create an empty union find data structure with N isolated sets.
    UF(int N)   {
        cnt = N;
	id = new int[N];
	sz = new int[N];
        for(int i=0; i<N; i++)	{
            id[i] = i;
	    sz[i] = 1;
	}
    }
    ~UF()	{
	delete [] id;
	delete [] sz;
    }
	// Return the id of component corresponding to object p.
    int find(int p)	{
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
	// Replace sets containing x and y with their union.
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;
		
		// make smaller root point to larger one
        if   (sz[i] < sz[j])	{ 
		id[i] = j; 
		sz[j] += sz[i]; 
	} else	{ 
		id[j] = i; 
		sz[i] += sz[j]; 
	}
        cnt--;
    }
	// Are objects x and y in the same set?
    bool connected(int x, int y)    {
        return find(x) == find(y);
    }
	// Return the number of disjoint sets.
    int count() {
        return cnt;
    }
 
};
/*
void tree(int i)
{
for(int x:g[i])
g[x].erase(find(g[x].begin(),g[x].end(),i)),tree(x);
}
*/
void factorial(int *b,int* c)
{
b[0]=1;int i;
for(i=1;i<=1000005;i++)
b[i]=b[i-1]*i%M;
c[1000002]=modulo(b[1000002],M-2,M);
for(i=1000001;i>-1;i--)
c[i]=c[i+1]*(i+1)%M;
}
int comb(int n,int r,int* b,int* c)
{
if(r>n)return 0;
return b[n]*c[n-r]%M*c[r]%M;
}
 
long double flor(long double x)
{
if(abs(x-round(x))<1e-12)
return round(x);
else return floor(x);
}
int ceil(int x,int y)
{
return x/y+(x%y!=0);
}
int rond(float x)
{
int y=round(x);
if(x-y>0&&x-y-0.5>-eps)
return y+1;
else return y;
}
bool prime(int n)
{
if(n==1)return 0;
for(int i=2;i*i<=n;i++)
if(n%i==0)return 0;
return 1;
}
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
bool comp(string s1,string s2)
{
if(s1.size()!=s2.size())return s1.size()<s2.size();
return s1<s2;
}
int32_t main()
{
    std::ios::sync_with_stdio(false);
cin.tie(NULL);
 int t,j,r,q,u,s1,s2,s3,bb,l,c1,v1,v2,z,c2,n1,nn,x1,hx,hy,tx,ty,n2, js,maxi,i,s,n3,L,R,mx,p,v,o,m1,t1,k1,k,k2,N,T,y,x3,y3,w,sq,x2,y1,y2,p1,
q1,l1,r1,t2,l2,r2;
T=1;
cin>>T;
//factorial(b,c);
srand(time(NULL));
tim=clock();float ti=0;
N=T;
while(T--)
{
cout<<"Case #"<<N-T<<": ";
cin>>m>>n;
for(i=0;i<n;i++)
cin>>st1[i];
s=pow(2.0L,m);
sort(st1,st1+n,comp);
//s-=pow(2,m-st1[0].size());
for(i=0;i<n;i++)
{
for(j=0;j<i;j++)
if(st1[j]==st1[i].substr(0,st1[j].size()))goto f;
s-=pow(2.0L,m-st1[i].size());
f:;
}
cout<<s<<endl;














 
}
cerr<<(clock()-tim)/CLOCKS_PER_SEC<<endl;
}
