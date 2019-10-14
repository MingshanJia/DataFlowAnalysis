#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <time.h>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

string names[100010];
char temp[100010];

int main()
{
	freopen("E:\\liuwei\\google test\\C-small-2-attempt0.in" , "r" , stdin);
	freopen("E:\\liuwei\\google test\\C-small-2-attempt0.out"  ,"w" , stdout);

	int i , j , k , test , case_num = 1;
	scanf("%d" , &test);
	while (test --)
	{
		int n , ans = 0;
		scanf("%d" , &n);

		getchar();
		for (i = 0;i < n;i ++)
		{
			gets(temp);
			names[i] = temp;
		}

		for (i = 1;i < n;i ++)
		{
			if (names[i] < names[i - 1])
			{
				sort(names , names + i + 1);
				ans ++;
			}
		}
		printf("Case #%d: %d\n" , case_num , ans);
		case_num ++;
	}
	return 0;
}





