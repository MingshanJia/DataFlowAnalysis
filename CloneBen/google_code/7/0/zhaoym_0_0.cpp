#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <sstream>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef vector <bool> VB;
typedef vector <VB> VVB;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef vector <double> VD;
typedef vector <VD> VVD;
typedef pair <int, int> PII;
typedef vector <PII> VPII;
typedef vector <string> VS;

const double eps = 1e-9;
const int INF = (1 << 29) - 1;
const int MOD = 1000000007;
const int MAXN = 1055;

int posX[MAXN * MAXN];
int posY[MAXN * MAXN];
int steps[MAXN * MAXN];


int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	
	int T;	cin >> T;
	
	for (int cas = 1; cas <= T; ++ cas)
	{
		int N, num;
		cin >> N;
		for (int i = 0; i < N; ++ i)
			for (int j = 0; j < N; ++ j)
			{
				scanf ("%d", &num);
				posX[num] = i;
				posY[num] = j;
			}
		
		fill (steps, steps + N * N + 10, 1);
		int start = N * N;
		for (num = N * N - 1; num > 0; -- num)
		{
			if (abs (posX[num + 1] - posX[num]) + abs (posY[num + 1] - posY[num]) == 1)
			{
				steps[num] = steps[num + 1] + 1;
			}
			if (steps[num] >= steps[start])
			{
				start = num;
			}
		}
		
		cout << "Case #" << cas << ": " << start << " " << steps[start] << endl;
	}
	
	
	
	return 0;	
}
