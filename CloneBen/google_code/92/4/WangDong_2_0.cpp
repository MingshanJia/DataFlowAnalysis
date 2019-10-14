#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int n, k;
int p[110][30];

int a[110][110];
int check[110];
int link[110];

bool calc(int k)
{
	if (check[k])
		return false;
	check[k] = true;

	for (int i=0; i<=n; i++)
		if (a[k][i]==1)
		{
			if (link[i]==-1)
			{
				link[i] = k;
				return true;
			}
			else if (calc(link[i]))
			{
				link[i] = k;
				return true;
			}
		}
	return false;
}

int work()
{
	int cur = 0;
	for (int i=0; i<n; i++)
		link[i] = -1;
	for (int i=0; i<n; i++)
	{
		memset(check, 0, sizeof(check));
		if (calc(i))
			cur++;
	}
	return cur;
}

void make_graph()
{
	memset(a,0,sizeof(a));
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (p[i][0]>p[j][0])
			{
				a[i][j]=1;
				for (int t=0; t<k; t++)
					if (p[i][t]==p[j][t])
						a[i][j]=0;
					else if (p[i][t]<p[j][t])
						a[i][j]=0;
			}
}

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);

	int T;
	cin >> T;
	for (int i=1; i<=T; i++)
	{
		cin >> n >> k;
		for (int j=0; j<n; j++)
			for (int t=0; t<k; t++)
				cin >> p[j][t];
		make_graph();
		cout << "Case #" << i << ": " << n - work() << endl;
	}

	return 0;
}