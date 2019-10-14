#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i=1; i<=N; ++i)
	{
		string num, src, trg;
		cin >> num >> src >> trg;

		int n = 0, b1 = src.length(), b2 = trg.length();
		for (int k=0; k<num.length(); ++k)
			(n *= b1) += src.find(num[k]);

		string res;
		do
			res = trg[n%b2] + res;
		while (n/=b2);

		cout << "Case #" << i << ": " << res << endl;
	}

	return 0;
}