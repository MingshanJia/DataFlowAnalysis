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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double run(){
	int B,L,N;
	cin >> B >> L >> N;
	vector<vector<double> > a,b;
	a.resize(1);
    a[0].resize(1, B * 750);
	for(int i = 1; i < L; ++i){
		b.resize(i + 1);
		for(int j = 0; j <= i; ++j){
			b[j].clear();
			b[j].resize(j + 1, 0.0);
		}
		for(int j = 0; j<i; ++j)
			for(int k = 0; k <= j; ++k)
			if(a[j][k] >= 250.0){
				a[j][k] -= 250.0;
				b[j][k] += a[j][k] / 3;
				b[j+1][k] += a[j][k] / 3;
				b[j+1][k+1] += a[j][k] / 3;
			}
		a.swap(b);
	}
	for(int i=0, k=0; i < L; ++i)
		for(int j = 0; j <= i; ++j)
			if(++k == N)
				return min(a[i][j],250.0);
}
int main(){
	int T;
	cin >> T;
	cout.precision(12);
	for(int i = 1; i <= T; ++i)
		cout << "Case #"<<i <<": " << run() << endl;
}

