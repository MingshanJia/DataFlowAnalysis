// try.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
#define PI 3.1415926535897932
int main(int argc, _TCHAR* argv[])
{	
	//freopen("A-small-1-attempt0.txt", "r", stdin);
	freopen("B-small-out.txt", "w", stdout);
	
	ios::sync_with_stdio(false);
	int tk, tk1 = 0;;
	cin >> tk;
	while (tk--)
	{
		tk1++;
		if (tk1 == 795)
		{
			tk1 = tk1;
		}
		double v, d, res;
		cin >> v >> d;
		double res1 = 9.8*d/v/v;
		//cout << "res1 = " << res1 << endl;
		//cout << asin(1.0) << endl;
		if (res1 > 1.0)
		{
			res1 = 1.0;
		}
		if (res1 < 0)
		{
			res1 = 0;
		}
		res = 90 * asin(res1) / PI;
		cout << fixed << setprecision(7) << "Case #" << tk1 << ": " << res << endl;
	}
	
	
	return 0;
}

