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

int n;
LL num[5010];

int main(){
	freopen("B-small-attempt0.in", "r",stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%lld", &num[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				for (int k = j + 1; k < n; k++){
					for (int r = k + 1; r < n; r++){
						if (num[i] == num[j]){
							if (num[r] > num[k] && num[r] < num[k] + 2 * num[i]){
								ans++;
							}
							else if (num[k] > num[r] && num[k] < num[r] + 2 * num[i]){
								ans++;
							}
						}
						else if (num[i] == num[k]){
							if (num[r] > num[j] && num[r] < num[j] + 2 * num[i]){
								ans++;
							}
							else if (num[j] > num[r] && num[j] < num[r] + 2 * num[i]){
								ans++;
							}
						}
						else if (num[i] == num[r]){
							if (num[k] > num[j] && num[k] < num[j] + 2 * num[i]){
								ans++;
							}
							else if (num[j] > num[k] && num[j] < num[k] + 2 * num[i]){
								ans++;
							}
						}
						else if (num[j] == num[k]){
							if (num[r] > num[i] && num[r] < num[i] + 2 * num[j]){
								ans++;
							}
							else if (num[i] > num[r] && num[i] < num[r] + 2 * num[j]){
								ans++;
							}
						}
						else if (num[j] == num[r]){
							if (num[k] > num[i] && num[k] < num[i] + 2 * num[j]){
								ans++;
							}
							else if (num[i] > num[k] && num[i] < num[k] + 2 * num[j]){
								ans++;
							}
						}
						else if (num[k] == num[r]){
							if (num[j] > num[i] && num[j] < num[i] + 2 * num[k]){
								ans++;
							}
							else if (num[i] > num[j] && num[i] < num[j] + 2 * num[k]){
								ans++;
							}
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n",ii,ans);
	}
	return 0;
}