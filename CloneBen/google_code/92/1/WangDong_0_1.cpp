#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int n;
vector<string> a;
vector<int> b;

int work()
{
	int cur = 0;
	for (int i=0; i<n; i++)
	{
		for (int j=i; j<n; j++)
			if (b[j]<=i)
			{
				for (int t=j; t>i; t--)
				{
					int temp = b[t];
					b[t] = b[t-1];
					b[t-1] = temp;
					cur++;
				}
				break;
			}
	}
	return cur;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);

	int T;
	cin >> T;
	for (int i=1; i<=T; i++)
	{
		cin >> n;
		a.clear();
		b.clear();
		for (int j=0; j<n; j++)
		{
			string temp;
			cin >> temp;
			a.push_back(temp);
			int max = 0;
			for (int t=0; t<n; t++)
				if (a[j][t]=='1')
					max = t;
			b.push_back(max);
		}
		cout << "Case #" << i << ": " << work() << endl;
	}

	return 0;
}