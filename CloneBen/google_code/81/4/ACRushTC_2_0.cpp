#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE(X) ((int)(X.size()))
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}

int m,n;
int c[100],s[100],t[100];
int a[100];

int _main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d%d",&c[i],&s[i],&t[i]);
	scanf("%d",&m);
	m+=n;
	for (int i=n;i<m;i++) scanf("%d%d%d",&c[i],&s[i],&t[i]);
	int p=n;
	for (int i=0;i<m;i++) a[i]=1;
	int left=1,total=0;
	int result=0;
	while (left>0)
	{
		if (p>m) p=m;
		int key=-1;
		for (int i=0;i<p;i++) if (a[i] && t[i]>0)  key=i;
		if (key>=0)
		{
			left--;
			a[key]=0;
			total+=s[key];
			left+=t[key];
			p+=c[key];
			continue;
		}
		vector<int> g;
		for (int i=0;i<p;i++) if (a[i]) g.push_back(s[i]);
		sort(g.begin(),g.end());
		reverse(g.begin(),g.end());
		int current=total;
		for (int i=0;i<SIZE(g) && i<left;i++)
			current+=g[i];
		checkmax(result,current);
		for (int i=0;i<p;i++) if (a[i] && c[i]==1 && (key<0 || s[i]>s[key])) key=i;
		if (key<0)
			break;
		left--;
		a[key]=0;
		total+=s[key];
		left+=t[key];
		p+=c[key];
	}
	checkmax(result,total);
	return result;
}

int main()
{
//	freopen("C.in","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);//freopen("C-small-attempt1.out","w",stdout);
	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
		cout<<"Case #"<<case_id<<": "<<_main()<<endl;
	return 0;
}
