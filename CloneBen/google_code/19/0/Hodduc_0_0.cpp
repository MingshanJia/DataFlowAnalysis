/*#include<stdio.h>
#include<algorithm>
int T, N;
struct LIST{
	int p, s;
}list[1005];
struct SORTF{
	bool inline operator () (LIST a, LIST b)
	{
		return (a.p+a.s) < (b.p+b.s);
	}
};
int d[2][105000], bef, aft;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	int i, t, j, max = 0;
	for(t = 1; t <= T; t++){
		scanf("%d", &N);
		for(i = 1; i <= N; i++)
			scanf("%d %d",&list[i].p, &list[i].s);
		std::sort(list+1, list+1+N, SORTF());

		bef = 0; aft = 1;
		memset(d, 0, sizeof(d));
		d[bef][0] = 1;
		max = 0;
		for(i = 1; i <= N; i++)
		{
			for(j = 0; j <= max; j++) if(d[bef][j] == i) d[aft][j] = i+1;
			for(j = 0; j <= list[i].p; j++)
			{
				if(d[bef][j] == i){
					d[aft][j+list[i].s] = i+1;
					if(max < j+list[i].s) max = j+list[i].s;
				}
			}
			
			bef ^= 1;
			aft ^= 1;
		}

		for(j = list[N].p + 1000; j >= 0; j--)
		{
			if(d[bef][j] == N+1) break;
		}
		printf("Case #%d: %d\n", t, j);
		fprintf(stderr, "%d\n", t);
	}
	return 0;
}

*/
#include<stdio.h>
#include<algorithm>
int T, N;
struct LIST{
	int p, s;
}list[1005];
struct SORTF{
	bool inline operator () (LIST a, LIST b)
	{
		if(a.p == b.p) return a.s < b.s;
		return a.p < b.p;
	}
};
int d[2][105000], bef, aft;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output_real.txt", "w", stdout);
	scanf("%d", &T);
	int i, t, j, max = 0, cnt = 0;
	for(t = 1; t <= T; t++){
		max = 0;
		scanf("%d", &N);
		for(i = 1; i <= N; i++)
			scanf("%d %d",&list[i].p, &list[i].s);
		std::sort(list+1, list+1+N, SORTF());
		do {
			if(list[1].p == 4 && list[2].p == 78 && list[3].p == 92){
				t = t;
			}
			int now = 0;
			for(i = 1; i <= N; i++){
				if(now <= list[i].p) now += list[i].s;
			}
			if(now > max) max = now;
			cnt ++;
		} while( std::next_permutation(list+1, list+1+N, SORTF() ));
		printf("Case #%d: %d\n", t, max);
		fprintf(stderr, "%d\n", t);
		fprintf(stderr, "%d\n", cnt);

	}
}