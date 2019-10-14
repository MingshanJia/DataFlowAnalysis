#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

class CC
{
	const static long long limit = 4294967295LL;
	int F, D, B;
	int minb;
	long long C(int n, int k)
	{
		if (k<0 || n<0 || k>n)  return 0;
		k = min(k, n-k);
		long long res = 1;
		for (int i=1; i<=k; ++i)
			if ((res=res*(n-k+i)/i)>limit)  return -1;
		return res;
	}
	long long FF(int d, int b)
	{
		b = min(d, b);
		long long res = 0;
		for (int i=1; i<=b; ++i)
		{
			long long Cdi = C(d, i);
			if (Cdi<0 || (res+=Cdi)>limit)  return -1;
			if (res<F)  minb = i;
		}
		return res;
	}
public:
	void Solve(int nCase)
	{
		cin >> F >> D >> B;

		minb = 0;
		long long maxF = FF(D, B);
		int minB = minb+1;
		int D0 = 0, D1 = D;
		while (D1-D0>1)
		{
			long long f = FF((D1+D0)/2, B);
			( f<0 || f>=F ? D1 : D0 ) = (D1+D0)/2;
		}
		int minD = D1;

		cout << "Case #" << nCase << ": " << maxF << " " << minD << " " << minB << endl;
	}
};

int main()
{
	int N;  cin >> N;

	CC solver;
	for (int i=1; i<=N; ++i)  solver.Solve(i);

	return 0;
}
