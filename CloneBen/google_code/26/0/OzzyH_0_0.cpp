//#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

ifstream cin("A-small.in");
ofstream cout("A-small.out");
//ifstream cin("A-large.in");
//ofstream cout("A-large.out");

int main() {
	int N;
	cin >> N;
	for (int n=1; n<=N; n++) {
		cout << "Case #" << n << ": ";
		int S;
		cin >> S;
		vector <int> B;
		vector <int> R;
		int temp; char ctemp; string ts;
		for (int i=0; i<S; i++) {
			cin >> ts;
			temp = 0;
			for (int j=0; j<ts.length(); j++) {
				if (ts[j]>='0' && ts[j]<='9')
					temp = temp*10 + ts[j] - '0';
				else {
					ctemp = ts[j];
					break;
				}
			}
			if (ctemp=='B')
				B.push_back(temp);
			else
				R.push_back(temp);
		}
		if (S<=1) {
			cout << "0" << endl;
			continue;
		}
		sort (B.begin(), B.end());
		reverse (B.begin(), B.end());
		sort (R.begin(), R.end());
		reverse (R.begin(), R.end());
		int si = B.size();
		bool bi = 0;
		if (R.size() < si) {
			si = R.size();
			bi = 1;
		}
		int M = 0;
		for (int i=0; i<si; i++) {
			M += B[i]+R[i];
			/*if (i==0)
				M -= 1;
			else*/ M -= 2;
		}
		/*if (B.size() > si && bi==1)
			M += B[si]-1;
		if (R.size() > si && bi==0)
			M += R[si]-1;*/
		cout << M << endl;
	}
	return 0;
}
