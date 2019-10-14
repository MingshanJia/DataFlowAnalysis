#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int S[40001];
int supply(int i,int j,int si,int sj)
{
	if (i!=j)
		return min(si,sj);
	return si/2;
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int n,m,b;
		scanf("%d %d %d",&n,&m,&b);
		memset(S,0,sizeof(S));
		int T[1000];
		for (int q=0;q<m;++q)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			S[u]+=v;
			T[q]=u;
		}
		long long ret = 0;
		for (int tar=b;tar<=40000;tar++)
		{
			for (int q=0;q<m;++q)
			{
				if (T[q]>tar) continue;
				if (T[q]==tar) 
				{
					//s=S[T[q]]
					int s = min(S[T[q]],n);
					n-=s;
					S[T[q]]-=s;
					ret += static_cast<long long>(tar)*s;
				}
				else
				{
					//tar-T[q]
					int s = supply(T[q],tar-T[q],S[T[q]],S[tar-T[q]]);
					s = min(s,n);
					n-=s;
					S[T[q]]-=s;
					S[tar-T[q]]-=s;
					ret += static_cast<long long>(tar)*s;
				}
			}
		}
		if (n==0)
			cout << "Case #" << kase <<": " << ret << endl;		
		else
			cout << "Case #" << kase <<": " << -1 << endl;
	}

	return 0;
}