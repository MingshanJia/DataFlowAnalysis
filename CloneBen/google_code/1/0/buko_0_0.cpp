#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int MAXX = 200000;

int cou[MAXX + 5], res, i, j, tab[7005], n, q, z;

int main() {
for (i=1;i<=MAXX;i++) cou[i] = 0;
scanf("%d", &z);
for (q=1;q<=z;q++) {
	scanf("%d", &n);
	for (i=0;i<n;i++) scanf("%d", &tab[i]);
	sort(tab, tab + n);
	res = 0;
	
	cou[tab[0]]++;
	for (i=2;i<n;i++) {
		for(j=1;j<i;j++) {
			if (tab[j] != 0 && tab[i] % tab[j] == 0) res += cou[tab[i] / tab[j]];
			cou[tab[j]]++;
		}
		for(j=1;j<i;j++) cou[tab[j]]--;
	}
	cou[tab[0]]--;
	for (i=0;i<n;i++) for (j=i+1;j<n;j++) if (tab[i] == 0 && tab[j] == 0) res += (n - 1 - j);
	printf("Case #%d: %d\n", q, res);
}
return 0;
}