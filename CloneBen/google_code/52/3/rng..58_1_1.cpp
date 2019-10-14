#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int a[10][10];

int brute(int X, int Y, int K){
	int mask,i,j,ans=10000;
	int N = X * Y;
	
	REP(mask,(1<<N)) if(__builtin_popcount(mask) == K){
		REP(i,X) REP(j,Y){
			int k = i * Y + j;
			if(mask&(1<<k)) a[i][j] = 1; else a[i][j] = 0;
		}
		int cnt = 0;
		REP(i,X) REP(j,Y-1) if(a[i][j] && a[i][j+1]) cnt++;
		REP(i,X-1) REP(j,Y) if(a[i][j] && a[i+1][j]) cnt++;
		ans = min(ans, cnt);
	}
	
	return ans;
}

int func2(int X, int Y, int K){
	if(X >= 2 && Y >= 2 && K <= ((X - 2) * (Y - 2) + 1) / 2) return 4 * K;
	
	if(X >= 2 && Y >= 2 && X % 2 == 1 && Y % 2 == 1 && K <= (X * Y + 1) / 2 - 4){
		int tmp = 4 * K;
		int center = ((X - 2) * (Y - 2) + 1) / 2;
		if(K >= center) tmp -= K - center;
		return tmp;
	}
	
	int four = 0;
	if(X >= 2 && Y >= 2) four = (X - 2) * (Y - 2) / 2;
	int two = 0;
	if(X % 2 == 0 || Y % 2 == 0) two = 2;
	int three = X * Y / 2 - four - two;
	int one = 0, zero = 0;
	
	if(X == 1 || Y == 1){
		int Z = max(X, Y);
		three = four = 0;
		two = (Z - 1) / 2;
		one = ((Z % 2 == 0) ? 1 : 0);
		zero = Z - two - one;
	}
	
	int a[] = {zero, one, two, three, four};
	int ans = 0;
	int i;
	for(i=4;i>=0;i--){
		ans += min(K, a[i]) * i;
		K -= min(K, a[i]);
	}
	
//	if(X == 2 && Y == 10 && K == 11) cout << X << ' ' << Y << ' ' << K << ' ' << zero << ' ' << one << ' ' << two << ' ' << three << ' ' << four << endl;
	
	return ans;
}

int func(int X, int Y, int K){
	if(K <= (X * Y + 1) / 2) return 0;
	return (X - 1) * Y + X * (Y - 1) - func2(X, Y, X*Y-K);
}

void main2(void){
	int X,Y,K,i;
	cin >> X >> Y >> K;
	cout << func(X, Y, K) << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
