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

typedef long long int64;
#define two(X) (1<<(X))
#define contain(S,X) (((S)&two(X))!=0)

const int maxn=10000+5;

int n,m,size;
map<int64,int> a[26];
char s[maxn][15];

string _main()
{
	int64 pw[15];
	for (int i=0;i<15;i++)
		pw[i]=(i==0)?1:(pw[i-1]*27);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%s",s[i]);
	string R="";
	for (int step=0;step<m;step++)
	{
		char order[30];
		scanf("%s",order);
		for (int k=0;k<26;k++)
		{
			a[k].clear();
			for (int i=0;i<n;i++)
			{
				char *p=s[i];
				int L=strlen(p);
				int64 state=pw[10]*L;
				for (int j=0;j<L;j++) for (int l=0;l<k;l++) if (p[j]==order[l]) state+=pw[j]*(p[j]-'a'+1);
				int mask=0;
				for (int j=0;j<L;j++) mask|=two(p[j]-'a');
				a[k][state]|=mask;
			}
		}
		int max_score=-1;
		int best_pos=-1;
		for (int i=0;i<n;i++)
		{
			char *p=s[i];
			int score=0;
			int L=strlen(p);
			int64 state=pw[10]*L;
			int set=0;
			for (int k=0;k<26 && set!=two(L)-1;k++)
			{
				char ckey=order[k];
				if (a[k].find(state)==a[k].end()) continue;
				int mask=a[k][state];
				if (!contain(mask,ckey-'a')) continue;
				bool exists=false;
				for (int i=0;i<L;i++) if (p[i]==ckey) exists=true,set|=two(i),state+=pw[i]*(ckey-'a'+1);
				if (!exists) score++;
			}
			if (score>max_score) max_score=score,best_pos=i;
		}
		R+=" "+(string)s[best_pos];
	}
	return R;
}

int main()
{
	freopen("B.in","r",stdin);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-small-attempt3.in","r",stdin);freopen("B-small-attempt3.out","w",stdout);
//	freopen("B-small-attempt4.in","r",stdin);//freopen("B-small-attempt4.out","w",stdout);
//	freopen("B-small-attempt5.in","r",stdin);freopen("B-small-attempt5.out","w",stdout);
//	freopen("B-small-attempt6.in","r",stdin);freopen("B-small-attempt6.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		cout<<"Case #"<<case_id<<":"<<_main()<<endl;
		cout.flush();
	}
	return 0;
}
