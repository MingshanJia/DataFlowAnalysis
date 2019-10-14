#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T,N;
	double d;
	vector<double> p;
	cin >> T;
	for (int ii = 0; ii < T; ii++) {
		p.clear();
		cin >> N;
		for (int i = 0; i < 2*N; i++) {cin >> d; p.push_back(d);}
		sort(p.begin(),p.end());
		double ans = 1;
		for (int i = 0; i < N; i++) {ans*=(1-p[i]*p[2*N-i-1]);}
		cout << "Case #" << ii+1 << ": " << ans << endl;
	}
	
	return 0;
}
