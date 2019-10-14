#include<stdio.h>
int T, M, dayPerM, dayPerWeek;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, i, j, row = 1, col = 1;
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		row = col = 1;
		printf("Case #%d: ", t);
		scanf("%d %d %d", &M, &dayPerM, &dayPerWeek);
		for(i = 1; i <= M; i++)
		{
			for(j = 1; j <= dayPerM; j++)
			{
				if(j == dayPerM && i != M){
					if(col == dayPerWeek){ col = 1; row ++; }
					else { col ++; row ++; }
				}
				else if(j == dayPerM && i == M){
					continue;
				}
				else if(j != dayPerM) {
					if(col == dayPerWeek){
						row++;
						col = 1;
					}
					else col ++;
				}
			}
		}
		printf("%d\n", row);
	}
	return 0;
}