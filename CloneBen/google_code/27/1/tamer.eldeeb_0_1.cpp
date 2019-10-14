#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;


int main()
{
	ifstream cin("AR-large.in");
	ofstream cout("AR-large.out");
	int N;
	cin >> N;
	for(int cc = 1; cc <= N; cc++)
	{
		int G;
		cin >> G;
		int res = 0;
		for(int i = 0; i < G; i++)
		{
			int t;
			cin >> t;
			res ^= t;
		}

		cout << "Case #" << cc << ": " << res << endl;
	}
}