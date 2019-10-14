#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int s[100][100];
bool flag[100];

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++)
	{
		int N;
		cin >> N;
		int NN = N * N;
		for (int i = 0; i < NN; i++)
			for (int j = 0; j < NN; j++)
				cin >> s[i][j];
		cout << "Case #" << z << ": ";
		for (int i = 0; i < NN; i++)
		{
			memset(flag, 0, sizeof flag);
			for (int j = 0; j < NN; j++)
				if (s[i][j] < 1 || s[i][j] > NN)
					goto bad;
				else if (flag[s[i][j]])
					goto bad;
				else
					flag[s[i][j]] = true;
			memset(flag, 0, sizeof flag);
			for (int j = 0; j < NN; j++)
				if (s[j][i] < 1 || s[j][i] > NN)
					goto bad;
				else if (flag[s[j][i]])
					goto bad;
				else
					flag[s[j][i]] = true;
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				memset(flag, 0, sizeof flag);
				for (int ii = 0; ii < N; ii++)
					for (int jj = 0; jj < N; jj++)
					{
						int si = i * N + ii, sj = j * N + jj;
						if (s[si][sj] < 1 || s[si][sj] > NN)
							goto bad;
						else if (flag[s[si][sj]])
							goto bad;
						else
							flag[s[si][sj]] = true;
					}
			}
		cout << "Yes" << endl;
		continue;

bad:	cout << "No" << endl;
	}
	return 0;
}
