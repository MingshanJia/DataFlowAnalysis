#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, d, n;
	cin >> t;
	
	int count;

	
	for (int test=1; test<=t; test++) {
		cin >> d >> n;
		char final[50][48];
		for (int i=0; i<50; i++) 
			for (int j=0; j<48; j++)
				final[i][j] = 'O';
		count = 0;
		for (int i=0; i<50; i=i+2) {
			for (int j=0; j<48; j=j+3) {
				if (count == n)
					break;
				final[i][j] = 'I';
				final[i][j+1] = '/';
				count++;
			}
			if (count == n)
				break;
		}
		printf("Case #%d:\n", test);
		for (int i=0; i<50; i++)  {
			for (int j=0; j<48; j++) {
				cout << final[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}