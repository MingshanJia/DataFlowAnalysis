#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, d, n;
	cin >> t;
	int count;
	for (int test=1; test<=t; test++) {
		cin >> d >> n;
		char final[15][15];
		vector<pair<int, int> > three, one;
		vector<pair<int, int> >::iterator it;
		count = 0;
		for(int i=0; i<15; i++)
			for(int j=0; j<15; j++)
				final[i][j] = 'O';

		for (int i=0; i<15; i++)
			for (int j=0; j<15; j+=4)
				final[i][j] = 'I';

		for (int i=1; i<14; i++)
			for (int j=1; j<15; j+=2)
				three.push_back(make_pair(i, j));

		for (int i=0; i<15; i+=14)
			for (int j=1; j<15; j+=2)
				one.push_back(make_pair(i, j));

		for (it = three.begin(); it!=three.end(); it++) {
			if (count+3>n) break;
			final[it->first][it->second] = '/';
			count = count+3;
		}

		for (it = one.begin(); it!=one.end(); it++) {
			if (count+1>n) break;
			final[it->first][it->second] = '/';
			count++;
		}
		printf("Case #%d:\n", test);
		for(int i=0; i<15; i++) {
			for(int j=0; j<15; j++) {
				cout << final[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
