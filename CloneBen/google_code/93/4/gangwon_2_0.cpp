#include <cstdio>
#include <algorithm>
using namespace std;
int prisoner[102];
int dy[102][102];
int main()
{
	int test_case_num;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &test_case_num);
	for (int test_case = 1 ; test_case <= test_case_num ; test_case++)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		prisoner[0] = 0;
		prisoner[q + 1] = p + 1;
		for (int i = 1 ; i <= q ; i++)
			scanf("%d", &prisoner[i]);
		for (int i = 1 ; i <= q ; i++)
			dy[i][i] = prisoner[i + 1] - prisoner[i - 1] - 2;
		for (int dummy = 1 ; dummy <= q ; dummy++)
			for (int i = 1 ; i <= q - dummy ; i++)
			{
				int j = i + dummy;

				dy[i][j] = -1;

				for (int k = i ; k <= j ; k++)
				{
					int now = dy[i][k - 1] + dy[k + 1][j];
					if (dy[i][j] == -1 || now < dy[i][j])
						dy[i][j] = now;
				}

				dy[i][j] += prisoner[j + 1] - prisoner[i - 1] - 2;
			}

		printf("Case #%d: %d\n", test_case, dy[1][q]);
	}
	return 0;
}