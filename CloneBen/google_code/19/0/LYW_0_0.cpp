#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int P[1000], S[1000];
int D[101001];
vector < pair < int, int > > food;

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	for (int testcase = 1; testcase <= testnum; testcase++) {
		int n;
		scanf("%d", &n);
		food.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &P[i], &S[i]);
			food.push_back(make_pair(S[i] + P[i], S[i]));
		}
		sort(food.begin(), food.end());
		for (int i = 0; i <= 101000; i++) 
			D[i] = 0;
		D[0] = 1;
			
		int bef_max = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int now_max = bef_max;
			bef_max = min(food[i].first - food[i].second, bef_max);
			for (int j = bef_max; j >= 0; j--) {
				if (D[j]) {
					D[j + food[i].second] = 1;
					now_max = max(now_max, j + food[i].second);
				}
			}
			bef_max = now_max;
			ans = max(ans, now_max);
		}		
		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}