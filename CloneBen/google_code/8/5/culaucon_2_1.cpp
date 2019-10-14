#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

int MOD=1000000007;

bool a[110];
int n;
vector<int> v;
int dp[1010];
map<int, int> f;

int check(int k)
{
	int ret=0;
	while (k>0)
	{
		int t=k%10;
		if (!a[t]) return -1;
		k/=10;
		ret++;
	}
	return ret;
}
int go(int cur)
{
	//cout<<cur<<" "<<v[cur]<<endl;
	if (dp[cur]>=0) return dp[cur];
	int num=v[cur], ret=check(num);
	for (int i=1;i<cur;i++)
		if (num%v[i]==0)
		{
			int t1=go(f[v[i]]), t2=go(f[num/v[i]]);
			if (t1==-1 || t2==-1) continue;
			if (ret==-1 || ret>t1+t2+1) ret=t1+t2+1;
		}
	//cout<<num<<" "<<ret<<endl;
	return dp[cur]=ret;
}
int main()
{
	freopen("broken_calculator.in","r",stdin);
	freopen("broken_calculator.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--)
	{
		for (int i=0;i<10;i++) cin>>a[i];
		cin>>n;
		v.clear();
		f.clear();
		for (int i=1;i<=n;i++)
			if (n%i==0)
			{
				v.push_back(i);
				f[i]=v.size()-1;
			}
		memset(dp,-1,sizeof(dp));
		int ret=go(v.size()-1);
		cout<<"Case #"<<nt++<<": ";
		if (ret==-1) cout<<"Impossible"<<endl;
		else cout<<ret+1<<endl;
	}
}
