#include<cstdio>
#include<algorithm>

using namespace std;

int f(long long kk, long long vv) {
	long long i, j, k, minn, maxx, ans=0;
	for (i = 0; i <= kk; i++) {
		for ( j = 0; j <= kk; j++) 
			for (k = 0; k <= kk; k++) {
				minn = min(i, min(j, k));
				maxx = max(i, max(j,k));
				if (maxx-minn <= vv)
					ans++;
			}
//		printf("fi: %lld, fans: %lld\n", i, ans);
	}
	return ans;
}

int main() {
	int tcc;
	scanf("%d", &tcc);
	for (int tc = 1; tc<=tcc; tc++) {
		long long k,v;
		int ccnt;
		scanf("%lld %lld", &k, &v);
		if (v == 0) {
			//printf("Case #%d: %lld\n", tc, k+1);
			//continue;
		}
		long long ans= 0, c = 0, cnt=0, i, j, ans2;
		for (i = 0; i < v; i++) {
			for (j = 0; j <= min(k, i+v); j++){
				int l = max(max(i, j) -v, (long long)0);
				int h = min(min(i, j) +v, k);
				ans += h-l+1;
			}
			cnt++;
		}
		//printf("cnt: %lld\n", cnt);
		ccnt=cnt;
		//printf("ans: %lld\n", ans);
		for (i = max(v, k-v); i<= k; i++) {
			for (j = max((long long)0, i-v); j<= k; j++) {
				int l = max(max(i, j) -v, (long long)0);
				int h = min(min(i, j) +v, k);
				ans += h-l+1;
			}
			cnt++;
		}
		//printf("ans: %lld\n", ans);
		ans2=0;
		for (i = 0; i <= 2*v; i++) {
			int l = max(max(i, v) -v, (long long)0);
			int h = min(min(i, v) +v, 2*v);
			ans2 += h-l+1;
//			printf("%lld %lld %d %d %lld\n", i, v, l, h, ans2);
		}

		if (cnt <= k+1) {
			ans += (k+1-cnt) * ans2;
		}
//		printf("ans: %lld %lld\n", ans, ans2);
//		printf("k: %lld cnt: %lld\n", k, cnt);
		printf("Case #%d: %lld\n", tc, ans);
		if (true){
			long long anss = f(k, v);
			if (ans != anss)
				printf("ERR %lld %lld \n", ans, anss);
		}
	}
	return 0;
}
