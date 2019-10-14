#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cmath>


using namespace std;
int a[110][110];

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		int P, Q;
		scanf("%d %d", &P, &Q);
		vector<int> q;
		q.resize(Q);
		for (int i = 0; i < Q; ++i)
			scanf("%d", &q[i]);
		
		memset(a, -1, sizeof(a));
		for (int h = 1; h <= Q + 2; ++h)
		{
			for (int i = 0; i < Q + 1; ++i)
			{
				int j = i + h;
				int start = 0;
				if (i > 0)
					start = q[i - 1];
				int end = P + 1;
				if (j <= Q)
					end = q[j - 1];
				if (j < Q + 2)
				{
					int add = end - start - 2;
					if (h == 1)
						a[i][j] = 0;
					else
					{
						for (int k = i + 1; k < j; ++k)
						{
							if (a[i][j] == -1 ||  a[i][j] > a[i][k] + a[k][j] + add)
								a[i][j] = a[i][k] + a[k][j] + add;
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n", t + 1, a[0][Q + 1]);
	}

	return 0;
}