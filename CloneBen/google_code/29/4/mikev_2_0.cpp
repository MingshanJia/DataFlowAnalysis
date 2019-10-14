#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i=1; i<=N; ++i)
	{
		int F, D, B;
		cin >> F >> D >> B;

		cout << "Case #" << i << ": ";

		vector<vector<long long> > maxF(D+1, vector<long long>(B+1));
		for (int d=1; d<=D; ++d)
		for (int b=1; b<=B; ++b)
		{
			maxF[d][b] = 1 + maxF[d-1][b] + maxF[d-1][b-1];
			if (maxF[d-1][b]<0 || maxF[d][b]>4294967295LL)
				maxF[d][b] = -1;
		}

		int minD, minB;
		for (int d=1; d<=D; ++d)
			if (maxF[d][B]<0 || maxF[d][B]>=F)
			{
				minD = d;
				break;
			}
		for (int b=1; b<=B; ++b)
			if (maxF[D][b]<0 || maxF[D][b]>=F)
			{
				minB = b;
				break;
			}

		cout << maxF[D][B] << " " << minD << " " << minB << endl;
	}

	return 0;
}