#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

LL T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an, ans;
char temp[10];
LL a[100][100];

void merge(LL x){
	if (x == 0){
		for (LL i=0; i<m; i++){
			w = m-1;
			for (LL j=m-1; j>=0; j--){
				if (a[i][j] != 0)
					a[i][w--] = a[i][j];
			}
			for (LL j=w; j>=0; j--)
				a[i][j] = 0;
		}
	}
	if (x == 1){
		for (LL i=0; i<m; i++){
			w = 0;
			for (LL j=0; j<m; j++){
				if (a[i][j] != 0)
					a[i][w++] = a[i][j];
			}
			for (LL j=w; j<m; j++)
				a[i][j] = 0;
		}
	}
	if (x == 2){
		for (LL i=0; i<m; i++){
			w = 0;
			for (LL j=0; j<m; j++){
				if (a[j][i] != 0)
					a[w++][i] = a[j][i];
			}
			for (LL j=w; j<m; j++)
				a[j][i] = 0;
		}
	}
	if (x == 3){
		for (LL i=0; i<m; i++){
			w = m-1;
			for (LL j=m-1; j>=0; j--){
				if (a[j][i] != 0)
					a[w--][i] = a[j][i];
			}
			for (LL j=w; j>=0; j--)
				a[j][i] = 0;
		}
	}
}

int main(){
	scanf("%lld", &T);
	for (LL rr = 1; rr <= T; rr++){
		printf("Case #%lld:\n", rr);
		scanf("%lld", &m);
		scanf("%s", temp);
		for (LL i=0; i<m; i++)
			for (LL j=0; j<m; j++)
				scanf("%lld", &a[i][j]);
		if (temp[0] == 'r'){
			for (LL i=0; i<m; i++){
				LL cur = -1, index;
				for (LL j=m-1; j>=0; j--){
					if (cur != a[i][j] && a[i][j] != 0){
						index = j;
						cur = a[i][j];
					} else if (cur == a[i][j]){
						a[i][j] = 0;
						a[i][index] *= 2;
						cur = -1;
					}
				}
			}
			merge(0);
		}
		else if (temp[0] == 'l'){
			for (LL i=0; i<m; i++){
				LL cur = -1, index;
				for (LL j=0; j<m; j++){
					if (cur != a[i][j] && a[i][j] != 0){
						index = j;
						cur = a[i][j];
					} else if (cur == a[i][j]){
						a[i][j] = 0;
						a[i][index] *= 2;
						cur = -1;
					}
				}
			}
			merge(1);
		}
		else if (temp[0] == 'u'){
			for (LL i=0; i<m; i++){
				LL cur = -1, index;
				for (LL j=0; j<m; j++){
					if (cur != a[j][i] && a[j][i] != 0){
						index = j;
						cur = a[j][i];
					} else if (cur == a[j][i]){
						a[j][i] = 0;
						a[index][i] *= 2;
						cur = -1;
					}
				}
			}
			merge(2);
		}
		else if (temp[0] == 'd'){
			for (LL i=0; i<m; i++){
				LL cur = -1, index;
				for (LL j=m-1; j>=0; j--){
					if (cur != a[j][i] && a[j][i] != 0){
						index = j;
						cur = a[j][i];
					} else if (cur == a[j][i]){
						a[j][i] = 0;
						a[index][i] *= 2;
						cur = -1;
					}
				}
			}
			merge(3);
		}
		for (LL i=0; i<m; i++)
			for (LL j=0; j<m; j++)
				printf("%lld%c", a[i][j], j==m-1?'\n':' ');
	}
	return 0;
}
