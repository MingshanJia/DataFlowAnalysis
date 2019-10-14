#include<cstdio>
#include<algorithm>
#include<cstring>

int f[100005];

void work(int case_id)
{
	int n;

	scanf("%d", &n);
	printf("Case #%d: %d\n", case_id, f[n]);
}

int main()
{
	memset(f, 0x2f, sizeof f);
	f[0] = 0;

	for(int j = 1; j * j <= 100000; j++)
	{
		int k = j * j;

		// fprintf(stderr, "%d %d\n", j, k);

		for(int i = 0; i + k <= 100000; i++)
		{
			f[i + k] = std::min(f[i + k], f[i] + 1);
		}
	}


	int total_case;
	scanf("%d", &total_case);
	
	for(int i = 1; i <= total_case; i++)
	{
		work(i);
	}

	return 0;


}