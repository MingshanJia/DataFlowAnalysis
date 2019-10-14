#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

LL dp[4444];
int vochash[444][26], len[444], tmphash[26];
char str[4444];

int main()
{
	int T, V, S;

	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d%d", &V, &S);
		memset(vochash, 0, sizeof(vochash));
		for (int i = 0; i < V; i++)
		{
			scanf("%s", str);
			len[i] = strlen(str);
			for (int j = 0; str[j]; j++)
				vochash[i][str[j] - 'a']++;
		}
		printf("Case #%d: ", t);
		while (S--)
		{
			scanf("%s", str);
			int N = strlen(str);
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			memset(tmphash, 0, sizeof(tmphash));
			for (int i = 0; i < N; i++)
			{
				memset(tmphash, 0, sizeof(tmphash));
				for (int j = 1; j < 21 && i + j <= N; j++)
				{
					tmphash[str[i + j - 1] - 'a']++;
					for (int k = 0; k < V; k++)
					{
						if (len[k] == j && memcmp(tmphash, vochash[k], sizeof(tmphash)) == 0)
							dp[i + j] = (dp[i + j] + dp[i]) % MOD;
					}
				}
			}
			printf("%lld ", dp[N]);
		}
		printf("\n");
	}

	return 0;
}