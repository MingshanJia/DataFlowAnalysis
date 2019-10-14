#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	for (int kase=1;kase<=T;++kase)
	{
		long long MY,DM,DW;
		long long CNT[105] = {0,};
		cin >> MY >> DM >> DW;
		long long CURDAY = 0, CYCLE = 0;
		for (int q=0;q<DW && q<MY;++q)
		{
			CNT[CURDAY]++;
			CURDAY = (CURDAY + DM) % DW;
			CYCLE++;
		}
		//곱하기!
		for (int q=0;q<DW;++q)
			CNT[q] *= MY / CYCLE;
		//나머지
		if (MY>CYCLE)
		{
			CURDAY = 0;
			for (int q=0;q<MY%CYCLE;++q)
			{
				CNT[CURDAY]++;
				CURDAY = (CURDAY + DM) % DW;
			}
		}
		long long LINES = 0;
		for (int q=0;q<DW;++q)
			LINES += CNT[q] * ((q+DM+DW-1)/DW);
		cout << "Case #" << kase << ": " << LINES << endl;
	}

	return 0;
}
