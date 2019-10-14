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

const double pi = acos((double) -1);

int main()
{
	freopen("E:\\liuwei\\google test\\B-small-attempt0.in" , "r" , stdin);
	freopen("E:\\liuwei\\google test\\B-small-attempt0.out"  ,"w" , stdout);

	int i , j , k , test , case_num = 1;
	cin >> test;
	while (test --)
	{
		int v , d;
		scanf("%d%d" , &v , &d);
		double temp = (double) d * (double) 9.8 / (double) (v * v);
		if (temp - 1 < 1e-9 && temp > 1)
			temp = 1;
		double result = asin(temp);
		printf("Case #%d: %.10lf\n" , case_num , result / pi * 90);
		case_num ++;
	}
	return 0;
}





