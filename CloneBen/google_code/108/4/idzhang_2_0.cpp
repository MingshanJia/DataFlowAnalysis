#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string prod(int n, int offset, int zeroidx) {
	int idx = offset % 4;
	string s;
	for (int i = 0; i < n; i++) {
		if (idx == 0) {
			s.append("I");
		} else if (idx == 1 || idx == 3) {
			s.append("/");
		}
		else {
			s.append("O");
		}
		idx = (idx+1)%4;
	}
	for (int i = zeroidx; i < n; i++) {
		s[i] = 'I';
	}
	return s;
}

string prodalt(int n, int offset) {
	int idx = offset % 2;
	string s;
	for (int i = 0; i < n; i++) {
		if (idx == 2) {
			s.append("I");
		} else {
			s.append("O");
		}
		idx = (idx+1)%4;
	}
	return s;
}

int main() {
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int d,n;
		cin >> d >> n;      
		cout << "Case #" << tc+1 << ":" << endl;
		int hi = (d-1)/2;
		int lo = (d-2)/2;
		// count number of hi/odd rows
		int numhi = n/hi;
		// print first 2 * numhi rows
		for (int i = 0; i < numhi; i++) {
			cout << prod(d,0,d-1) << endl;
			cout << prod(d,0,0) << endl;
		}
		// print last row
		int numleft = n % hi;
		cout << prod(d,0,2*numleft+1) << endl;
	}
}
















