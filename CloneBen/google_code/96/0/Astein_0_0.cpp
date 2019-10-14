#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int check(string a, string b)
{
	int pos = 0;
	for (int i = 0; i < b.size(); ++i)
	{
		string word = "";
		if (a[pos] == '(')
		{
			for (int j = pos + 1; ; ++j)
				if (a[j] == ')') 
				{
					pos = j + 1;
					break; 
				}
				else word += a[j];

		}
		else 
		{
			word = a[pos];
			pos++;
		}

		bool isOK = false;
		for (int j = 0; j < word.size(); ++j)
			if (word[j] == b[i]) isOK = true;
		if (!isOK) return 0;
	}

	if (pos != a.size()) return 0;
	return 1;
}

int main()
{
	int L, D, N;
	cin >> L >> D >> N;

	vector<string> word(D);

	for (int i = 0; i < D; ++i)
		cin >> word[i];

	for (int q = 0; q < N; ++q)
	{
		int ret = 0;
		string str;

		cin >> str;
		for (int i = 0; i < D; ++i)
		{
			if (check(str, word[i])) ret++;
		}
		printf("Case #%d: %d\n", q + 1, ret);
	}
}