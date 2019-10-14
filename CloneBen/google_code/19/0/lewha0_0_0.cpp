#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a, b, index, c;
int n;
int T;
int ret;

int main(void)
{
	int l0, l1, l2;

	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);

	scanf("%d",&T);

	ret = 0;

	for(l0=1;l0<=T;l0++)
	{
		scanf("%d",&n);
		a.resize(n);
		b.resize(n);
		index.resize(n);
		for(l1=0;l1<n;l1++) scanf("%d %d",&a[l1],&b[l1]);

		for(l1=0;l1<n;l1++) index[l1] = l1;

		ret = 0;

		c.resize(n);
		for(l1=0;l1<n;l1++) c[l1] = 0;
		do
		{
			int curr = 0;
			for(l1=0;l1<n;l1++)
			{
				if(a[index[l1]] < curr) continue;
				curr += b[index[l1]];
			}
			if(ret < curr) ret = curr;
		} while(next_permutation(index.begin(), index.end()));
		printf("Case #%d: %d\n",l0,ret);
	}
}