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
	freopen("A-small-out.txt", "w", stdout);
	
	ios::sync_with_stdio(false);
	map<string, int> mp;
	int tk, tk1 = 0;;
	cin >> tk;
	while (tk--)
	{
		mp.clear();
		tk1++;
		int n;
		cin >> n;
		vector<vector<int>> a(2 * n);
		for (int i = 0; i < n; i++)
		{
			string str1, str2;
			cin >> str1 >> str2;
			if (mp.count(str1) == 0)
			{
				mp.insert(make_pair(str1, mp.size()));
			}
			if (mp.count(str2) == 0)
			{
				mp.insert(make_pair(str2, mp.size()));
			}
			a[mp.at(str1)].push_back(mp.at(str2));
			a[mp.at(str2)].push_back(mp.at(str1));
		}

		int siz = mp.size();
		vector<int> vis(siz);
		string resStr = "Yes";
		for (int i = 0; i < siz; i++)
		{
			if (vis[i])
			{
				continue;
			}
			queue<int> que;
			que.push(i);
			vis[i] = 1;
			while (!que.empty())
			{
				int now = que.front();
				que.pop();
				int val = vis[now];
				int res = -val;
				for (int j = 0; j < a[now].size(); j++)
				{
					if (vis[a[now][j]] == val)
					{
						resStr = "No";
					}
					else {
						if (vis[a[now][j]] == 0)
						{
							que.push(a[now][j]);
						}
						vis[a[now][j]] = res;
					}
				}
			}
		}
		cout << "Case #" << tk1 << ": " << resStr << endl;
	}
	
	
	return 0;
}

