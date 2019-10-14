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

bool graph[1010][1010];
int flag[1010];
map<string , int> Hash;

bool dfs(int cur , int n , int color)
{
	flag[cur] = color;

	for (int i = 1;i <= n;i ++)
	{
		if (graph[cur][i])
		{
			if (flag[i] == color)
				return false;
			else if (flag[i] == 0)
			{
				if (!dfs(i , n , - color))
					return false;
			}
		}
	}
	return true;
}

int main()
{
	freopen("E:\\liuwei\\google test\\A-small-1-attempt2.in" , "r" , stdin);
	freopen("E:\\liuwei\\google test\\A-small-1-attempt2.out"  ,"w" , stdout);

	int i , j , k , test , case_num = 1;
	cin >> test;
	while (test > 0)
	{
		bool result = true;
		Hash.clear();

		memset(graph , 0 , sizeof(graph));
		memset(flag , 0 , sizeof(flag));

		int m , next = 1;
		cin >> m;
		for (i = 0;i < m;i ++)
		{
			int index1 , index2;
			string name1;
			string name2;

			cin >> name1 >> name2;

			if (Hash[name1] == 0)
			{
				Hash[name1] = next;
				index1 = next;
				next ++;
			}
			else
				index1 = Hash[name1];

			if (Hash[name2] == 0)
			{
				Hash[name2] = next;
				index2 = next;
				next ++;
			}
			else
				index2 = Hash[name2];

			graph[index1][index2] = graph[index2][index1] = true;
		}

		for (i = 1;i <= next - 1;i ++)
		{
			if (flag[i] == 0)
			{
				if (!dfs(i , next - 1 , 1))
				{
					result = false;
					break;
				}
			}
		}

		if (result)
			printf("Case #%d: Yes\n" , case_num);
		else
			printf("Case #%d: No\n" , case_num);

		case_num ++;
		test --;
	}
	return 0;
}





