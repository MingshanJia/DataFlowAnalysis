#include <cstdio>
#include <iostream>

using namespace std;

int cmmdc(int a,int b)
{
	if (b == 0) return a;
	return cmmdc(b, a%b);
}

int main()
{
	freopen ("A.in", "r", stdin);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		long long n;
		int pd, pg;
		cin >> n >> pd >> pg;

		int p = cmmdc(pd, 100);
	
		cout << "Case #" << i + 1 << ": ";

		if (n < 100/p) cout << "Broken";
		else
		{
			if ((pg == 100 && pd != 100) || (pg == 0 && pd != 0))
				cout << "Broken";
			else cout << "Possible";
		}
		cout << "\n";
	}

	return 0;
}

