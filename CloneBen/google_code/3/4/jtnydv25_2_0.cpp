#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll X[3], Y[3], Z[3];
int main(){
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt ++){
		cin >> X[0] >> Y[0] >> Z[0];
		cin >> X[1] >> Y[1] >> Z[1];
		cin >> X[2] >> Y[2] >> Z[2];

		sort(X, X + 3);

		cout << "Case #" << tt << ": " << setprecision(10) << fixed << (X[2] - X[0]) / 6.0 << endl;
	}
}