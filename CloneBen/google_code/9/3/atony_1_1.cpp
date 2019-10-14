#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 11001;
const int MAXM = 1000011;
const int INF = 1000000005;
const double pi = acos(-1.0);

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j;
	vector<int> sum(401,0);
	vector<int> number(401,0);
	int L=400;
	for(i=1,sum[0]=0;i<=L;i++)
	{
		number[i]=(i+1)*i/2;
		sum[i]=sum[i-1]+number[i];
	}
	int T,cas,B,N;
	vector<double> a(sum[L]+1),b(sum[L]+1);
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d%d%d",&B,&L,&N);
		int n=sum[L];
		for(i=1;i<=n;i++)
		{
			a[i]=0;
			b[i]=0;
		}
		b[1]=B*750;
		int id,val;
		for(i=1;i<=L;i++)
			for(j=1,val=1,id=1;j<=number[i];j++)
			{
				int pos=sum[i-1]+j;
				if(b[pos]+a[pos]>250)
				{
					b[pos]=b[pos]+a[pos]-250;
					a[pos]=250;
					if(i<L)
					{
						b[sum[i]+j]+=1.0/3*b[pos];
						b[sum[i]+val+j]+=1.0/3*b[pos];
						b[sum[i]+val+j+1]+=1.0/3*b[pos];
						b[pos]=0;
					}
				}
				else
				{
					a[pos]=a[pos]+b[pos];
					b[pos]=0;
				}
				if(id>=val)
				{
					val++;
					id=1;
				}
				else
					id++;
			}
		int pos=sum[L-1]+N;
		printf("Case #%d: %.7lf\n",cas,a[pos]);
	}
	return 0;
}
