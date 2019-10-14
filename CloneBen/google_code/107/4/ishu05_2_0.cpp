#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ff first
#define se second
#define pb push_back
#define nn 200100
#define mt make_tuple
#define mp make_pair
#define ll long long int
#define db double
#define ld long double
#define inf 1000000000000000000ll
#define logn 20
#define mod 1000000007ll
#define mod1 mod
#define mod2 100000009ll
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define setm1(a) memset(a,-1,sizeof a)
#define cmp 1e-16
#define endl '\n'
 
using namespace std;
using namespace __gnu_pbds;

typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef pair<long double,long double> pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> OST;

template<class T> T gcd(T a,T b){return (b==0)?a:gcd(b,a%b);}
ll power(ll a,ll p,ll m=mod)
{ll res=1;while(p>0){if(p&1)res=(res*a)%m;a=(a*a)%m;p>>=1;}
return res;}

const ld pi=3.141592653589793238462643383;

vector<int> adj[27];
int visited[27];
vector<int> adj_inv[27];
int visited_inv[27];
stack<int> temp;

string arr[3];

void init()
{
	for (int i = 0; i < 27; ++i)
	{
		adj[i].clear();
		adj_inv[i].clear();
		visited[i] = visited_inv[i] = 0;
	}

	while(!temp.empty())
		temp.pop();
}

bool addEdge(string s1, string s2)
{
	int i = 0, j = 0;
	int l1 = s1.length();
	int l2 = s2.length();

	while(i<l1 && j<l2 && s1[i]==s2[j])
	{
		i++;
		j++;
	}

	if(i<l1 && j<l2)
	{
		adj[s1[i]-'A'+1].pb(s2[j]-'A'+1);
		adj_inv[s2[j]-'A'+1].pb(s1[i]-'A'+1);
	}

	else if(i<l1 && j==l2)
	{
		return false;
	}

	return true;
}

void dfs(int u)
{
	visited[u] = 1;
	for(int i=0;i<adj[u].size();i++)
	{
		int v = adj[u][i];
		if(visited[v]==0)
		{
			dfs(v);
		}
	}
	temp.push(u);
}

int dfsSCC(int u)
{
	visited_inv[u] = 1;
	int count = 1;
	for(int i=0;i<adj_inv[u].size();i++)
	{
		int v = adj_inv[u][i];
		if(visited_inv[v]==0)
		{
			count++;
			dfs(v);
		}
	}
	return count;
}

bool check(string s[])
{
	init();
	string s1, s2;
	bool flag;
	for (int i = 1; i < 3; ++i)
	{
		s1 = s[i-1];
		s2 = s[i];
		flag = addEdge(s1, s2);
		if(!flag)
			return false;
	}
	for(int i=1;i<27;i++)
	{
		if(visited[i]==0)
		{
			dfs(i);
		}
	}
	while(!temp.empty())
	{
		int x = temp.top();
		temp.pop();
	 	if(!visited_inv[x])
	 	{
			int val = dfsSCC(x);
			if(val>1)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    
    int t;
    cin>>t;
    for (int tes = 0; tes < t; ++tes)
    {
        cout<<"Case #"<<(tes+1)<<": ";

        int l;
        cin>>l;

        for (int i = 0; i < 3; ++i)
        {
        	cin>>arr[i];
        }

        string temp[3];
        string temp1[3];
        for (int i = 0; i < 3; ++i)
        {
        	temp[0] = arr[(i+1)%3]; temp[1] = arr[i]; temp[2] = arr[(i+2)%3];
        	temp1[0] = arr[(i+2)%3]; temp1[1] = arr[i]; temp1[2] = arr[(i+1)%3];
        	if(check(temp))
        		cout<<"YES ";
        	else if(check(temp1))
        		cout<<"YES ";
        	else
        		cout<<"NO ";
        	
        }
        cout<<endl;
    }

    return 0;
}