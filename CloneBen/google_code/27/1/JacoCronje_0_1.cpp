// A.cpp : Defines the entry point for the console application.
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
	int n;
	cin >> n;
	for (int t=0;t<n;t++)
	{
		map<unsigned int, int> tel;
		int g;
		cin >> g;
		for (int i=0;i<g;i++)
		{
			int v;
			cin >> v;
			tel[v]++;
		}
		cout << "Case #" << (t+1) << ": ";
		for (map<unsigned int, int>::iterator itr=tel.begin();itr!=tel.end();++itr)
		{
			if (itr->second==1)
			{
				cout << itr->first << endl;
				break;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	solve();
	return 0;
}

