#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <map>

using namespace std;


int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		string s;
		cin >> s;
		map <char, int> z;
		int j = 1;
		bool was0 = false;
		for (int i = 0; i < s.size(); ++i)
		{
			if (z.find(s[i]) == z.end())
			{
				if (i != 0 && !was0 )
				{
					z[s[i]] = 0;
					was0 = true;
				}
				else
				{
					z[s[i]] = j;
					++j;
				}
			}
		}
		unsigned long long res = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			res = res * j + z[s[i]];
		}
		cout << "Case #" << t + 1 << ": " << res << "\n";
	}

	return 0;
}