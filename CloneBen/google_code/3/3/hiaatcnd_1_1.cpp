#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int INF = ((int)1e9) + 7;
int T, n, ca;
int a[5010];
int cnt[5010], sum[5010];
map<int, int> mp;

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		mp.clear();
		for(int i = 1; i <= n; ++i){
			scanf("%d", a + i);
			mp[a[i]]++;
		}
		sort(a + 1, a + n + 1);
		n = unique(a + 1, a + n + 1) - a - 1;
		for(int i = 1; i <= n; ++i){
			sum[i] = sum[i - 1] + mp[a[i]];
			cnt[i] = mp[a[i]];
		}

		ll ans = 0;

		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j)
				if(i != j && cnt[j] >= 2){
					int k = upper_bound(a + 1, a + n + 1, a[i] - 2 * a[j]) - a;
					int tmp = sum[i - 1] - sum[k - 1];
					if(j < i && k <= j) tmp -= cnt[j];
					int tmp2 = cnt[j] * (cnt[j] - 1) / 2;
					ans += (ll)tmp * tmp2 * cnt[i];
				}
		}
		
		for(int i = 1; i <= n; ++i)
			if(cnt[i] >= 3){
				ll tmp = (ll)cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
				int tt = min((ll)INF, 3LL * a[i]);
				int k = lower_bound(a + 1, a + n + 1, tt) - a - 1;
				int tmp2 = sum[k];
				if(k >= i) tmp2 -= cnt[i];
				ans += tmp * tmp2;
			}

		printf("Case #%d: %lld\n", ++ca, ans);
	}
	
	return 0;
}
