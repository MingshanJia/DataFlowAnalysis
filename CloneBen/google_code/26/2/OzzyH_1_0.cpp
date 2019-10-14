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

ifstream cin("B-small.in");
ofstream cout("B-small.out");
//ifstream cin("B-large.in");
//ofstream cout("B-large.out");

int main() {
	int N;
	cin >> N;
	for (int n=1; n<=N; n++) {
		cout << "Case #" << n << ": ";
		int M;
		cin >> M;
		vector <int> P;
		int temp;
		for (int i=0; i<12; i++) {
			cin >> temp;
			P.push_back(temp);
		}
		int MP=0, ppu=100000;
		int m1=0, m2=0;
		for (int i=0; i<11; i++) {
			for (int j=i+1; j<12; j++) {
				int prof = (M/P[i])*P[j] - (M/P[i])*P[i];
				if ((prof > MP) || (prof==MP && P[i]<ppu)) {
					MP = prof;
					m1 = i;
					m2 = j;
				}
			}
		}
		if (MP==0) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << m1+1 << " " << m2+1 << " " << MP << endl;
		}
	}
	return 0;
}
