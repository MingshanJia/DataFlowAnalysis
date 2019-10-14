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

ifstream cin("C-small.in");
ofstream cout("C-small.out");
//ifstream cin("C-large.in");
//ofstream cout("C-large.out");

int main() {
	int N;
	cin >> N;
	for (int n=1; n<=N; n++) {
		cout << "Case #" << n << ": ";
		int L, W;
		cin >> L >> W;
		char ch;
		vector < pair <int, int> > V;
		for (int i=0; i<W; i++) {
			for (int j=0; j<L; j++) {
				cin >> ch;
				if (ch == 'W' || ch == 'R' || ch == 'T')
					V.push_back(make_pair(i,j));
			}
		}
		int M = 0;
		for (int i=0; i<W; i++)
			for (int j=0; j<L; j++)
				for (int k=i; k<W; k++)
					for (int l=j; l<L; l++) {
						bool good = 1;
						for (int x=0; x<V.size(); x++)
							if (!((V[x].first < i || V[x].first > k) || (V[x].second < j || V[x].second > l)))
								good = 0;
						if (good && (k-i+1)*(l-j+1) > M)
							M = (k-i+1)*(l-j+1);
					}
		cout << M << endl;
	}
	return 0;
}
