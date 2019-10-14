#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100010
#define LL long long
using namespace std;

struct NODE{
	LL x, cnt;
}nodes[5010];

int n;
LL num[5010];
LL sum[5010];

int main(){
	freopen("B-large.in", "r",stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%lld", &num[i]);
		}
		sort(num, num + n);
		int cou = 1;
		nodes[1].x = num[0];
		nodes[1].cnt = 1;
		for (int i = 1; i < n; i++){
			if (num[i] == nodes[cou].x){
				nodes[cou].cnt++;
			}
			else{
				cou++;
				nodes[cou].x = num[i];
				nodes[cou].cnt = 1;
			}
		}
		n = cou;
		sum[0] = 0;
		for (int i = 1; i <= n; i++){
			sum[i] = sum[i - 1] + nodes[i].cnt;
		}
		LL ans = 0;
		for (int i = 1; i <= n; i++){
			LL x = nodes[i].cnt * (nodes[i].cnt - 1) / 2;
			LL y = x * (nodes[i].cnt - 2) / 3;
			if (x == 0){
				continue;
			}
			int left = n, right = n;
			while (right > 0){

				if (right == i){
					while (left > 0 && nodes[right].x < nodes[left].x + 2 * nodes[i].x){
						left--;
					}
					if (left <= right - 1){
						ans += y * (sum[right - 1] - sum[left]);
					}
					right--;
					if (right == 0) break;
				}

				while (left > 0 && nodes[right].x < nodes[left].x + 2 * nodes[i].x){
					left--;
				}
				int min1 = left + 1, max1 = right - 1;
				if (min1 <= max1){
					if (i >= min1 && i <= max1){
						ans += x * nodes[right].cnt * (sum[max1] - sum[left] - nodes[i].cnt);
						ans += y * nodes[right].cnt;
					}
					else{
						ans += x * nodes[right].cnt * (sum[max1] - sum[left]);
					}
				}
				right--;
			}
		}
		printf("Case #%d: %lld\n",ii,ans);
	}
	return 0;
}