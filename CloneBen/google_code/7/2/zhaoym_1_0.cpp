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
const int MAXN = 5055;

int cnt[MAXN];
int N, P; 


int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	
	int T;	cin >> T;
	for (int cas = 1; cas <= T; ++ cas)
	{
		cin >> N;
		int minC = MAXN, maxC = -1;
		memset (cnt, 0, sizeof (cnt));
		while (N --)
		{
			int a, b;
			cin >> a >> b;
			if (a > b)
			{
				swap (a, b);
			}
			minC = min (minC, a);
			maxC = max (maxC, b);
			++ cnt[a];
			-- cnt[b + 1];
		}
		
		for (int i = 1; i < MAXN; ++ i)
		{
			cnt[i] += cnt[i - 1];
		}
		
		cout << "Case #" << cas << ":";
		
		cin >> P;
		while (P --)
		{
			int x;	cin >> x;
			if (x < minC || x > maxC)	cout << " 0";
			else	cout << " " << cnt[x];
		}
		cout << endl;
	}
	
	
	
	return 0;	
}
