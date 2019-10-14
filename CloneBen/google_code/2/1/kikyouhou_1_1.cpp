#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
#include<map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 300010
#define LL long long
#define RUN
using namespace std;

int n, e;
int num[MAX];
int sum[MAX];

int main(){
#ifdef RUN
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ii++){
		scanf("%d%d", &e, &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", &num[i]);
		}
		sort(num + 1, num + 1 + n);
		for (int i = 1; i <= n; i++){
			sum[i] = sum[i - 1] + num[i];
		}
		int left = 1, right = n;
		int rem = 0, ans = 0;
		while (left <= right){
			int ids = lower_bound(sum + left, sum + 1 + right, e + sum[left - 1]) - sum;
			if (ids == left){
				if (rem){
					rem--;
					e += num[right];
					right--;
				}
				else{
					break;
				}
			}
			else if (ids == right + 1){
				rem += (right - left + 1);
				ans = max(rem, ans);
				break;
			}
			else{
				rem += (ids - left);
				e -= (sum[ids - 1] - sum[left - 1]);
				left = ids;
			}
			ans = max(rem, ans);
		}
		printf("Case #%d: %d\n", ii, ans);
	}
	return 0;
}