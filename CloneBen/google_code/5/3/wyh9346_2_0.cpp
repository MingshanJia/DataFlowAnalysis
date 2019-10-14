// try.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

int main(int argc, _TCHAR* argv[])
{	
	//freopen("A-small-1-attempt0.txt", "r", stdin);
	freopen("C-small-out.txt", "w", stdout);
	
	ios::sync_with_stdio(false);
	int tk, tk1 = 0;;
	cin >> tk;
	while (tk--)
	{
		tk1++;
		int n;
		cin >> n;
		vector<string> a(n);
		getline(cin, a[0]);
		for (int i = 0; i < n; i++)
		{
			getline(cin, a[i]);
		}
		int res = 0;
		string biggest = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i].compare(biggest) > 0)
			{
				biggest = a[i];
			}
			else {
				res++;
			}
		}
		cout << "Case #" << tk1 << ": " << res << endl;
	}
	
	
	return 0;
}

