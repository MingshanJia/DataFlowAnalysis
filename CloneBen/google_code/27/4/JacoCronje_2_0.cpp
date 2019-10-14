// C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

#define ull unsigned long long

void solve()
{
	int T;
	cin >> T;
	for (int t=0;t<T;t++)
	{
		int P, C;
		cin >> P >> C;
		vector<ull> dt;
		for (int i=0;i<P;i++)
		{
			ull v;
			cin >> v;
			dt.push_back(v);
		}
		ull res = 0;

		for (;;)
		{
			sort(dt.begin(), dt.end());
			//for (int z=0;z<dt.size();z++)
			//	cout << dt[z] << " ";
			//cout << " : " << res << endl;
			ull bg = 0;
			for (int z=0;z<C;z++)
			{
				ull step = 0;
				int zz = P-1-z;
				if (zz>0)
				{
					step = dt[zz] - dt[zz-1];
					if (dt[zz-1]>0)
						step = step + (ull)(1);
				}
				else
				{
					step = dt[zz];
				}
				if (z==0 || step<bg)
				{
					bg = step;
				}
			}
			for (int z=0;z<C;z++)
			{
				int zz = P-1-z;
				dt[zz] = dt[zz] - bg;
			}
				res += bg;
			if (bg==0) break;
		}
		cout << "Case #" << (t+1) << ": " << res << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	solve();
	return 0;
}

