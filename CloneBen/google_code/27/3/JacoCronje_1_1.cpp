// B.cpp : Defines the entry point for the console application.
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

void solve()
{
	int c;
	cin >> c;
	for (int t=0;t<c;t++)
	{
		int N, T;
		cin >> N >> T;
		T--;
		vector< vector<int> > town(N);
		int E;
		cin >> E;
		for (int i=0;i<E;i++)
		{
			int H, P;
			cin >> H >> P;
			H--;
			town[H].push_back(P);
		}
		stringstream ss;
		bool bok = true;
		for (int i=0;i<N;i++)
		{
			if (i==T)
			{
				ss << "0";
			}
			else
			{
				int sz = town[i].size();
				sort(town[i].begin(), town[i].end());
				reverse(town[i].begin(), town[i].end());
				int car = 0;
				for (int z=0;z<town[i].size();z++)
				{
					if (town[i][z]>0)
					{
						if (town[i][z]==1)
						{
							car++;
							sz--;
						}
						else
						{
							car++;
							sz--;
							int ll = town[i].size()-1;
							for (int k=0;k<town[i][z]-1;k++)
							{
								if (sz==0) break;
								if (ll<=z) break;
								ll--;
								town[i].pop_back();
								sz--;
							}
						}
					}
				}
				if (sz>0) 
				{
					bok = false;
					break;
				}
				ss << car;
			}
			if (i<N-1) ss << " ";
		}
		if (bok)
		{
			cout << "Case #" << (t+1) << ": " << ss.str() << endl;
		}
		else
		{
			cout << "Case #" << (t+1) << ": " << "IMPOSSIBLE" << endl;
		}
	}


}

int _tmain(int argc, _TCHAR* argv[])
{
	solve();
	return 0;
}

