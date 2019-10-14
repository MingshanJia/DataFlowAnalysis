#include <cstdio>

const int MAXN = 110;
int next[MAXN], list[MAXN];
void doit()
{	
	int n, k;
	scanf("%d%d", &n, &k);
	int cnt = n, flag = 1;
	for (int i = 1; i <= n; i++)
		scanf("%d", &list[i]);
	list[0] = 1000000000;
	list[n+1] = -1000000000;
	for (int i = 0; i <= n; i++)
		next[i] = i + 1;
	next[n + 1] = n + 1;
	while(flag)
	{
		flag = 0;
		for (int i = next[0], pre = 0; next[next[i]] != n + 1; pre = i, i = next[i])
		{
			int ne = next[i];
			int nne = next[next[i]];
			if (list[ne] - list[i] == k && list[nne] - list[ne] == k)
			{
				next[pre] = next[nne];
				flag = 1;
				cnt -= 3;
				break;
			}
		}
	}
	printf("%d\n", cnt);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		doit();
	}
	return 0;
}