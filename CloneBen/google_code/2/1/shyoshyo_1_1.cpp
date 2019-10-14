#include<cstdio>
#include<algorithm>
#include<cstring>

int n, m;
int a[100005];
long long f[1005][1005];

void work(int case_id)
{
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}

	std::sort(a + 1, a + n + 1);

	memset(f, 0xc0, sizeof f);
	f[0][0] = m;

	int ans = 0;

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0, k = i; j <= k; j++, k--)
		{
			if(f[i][j] > 0)
			{
				// fprintf(stderr, ">> %d = (+) %d  (-) %d     ~ %lld\n", i, j, k, f[i][j]);
				ans = std::max(ans, k - j);

				f[i + 1][j + 1] = std::max(f[i + 1][j + 1], f[i][j] + a[n - j]);
				f[i + 1][j] = std::max(f[i + 1][j], f[i][j] - a[k + 1]);
			}
		}
	}

	printf("Case #%d: %d\n", case_id, ans);

}

int main()
{
	int total_case;
	scanf("%d", &total_case);
	
	for(int i = 1; i <= total_case; i++)
	{
		work(i);
	}
}