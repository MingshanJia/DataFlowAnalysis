#include<bits/stdc++.h>
using namespace std;
#define LL long long

int n;
int a[7005];
int cnt[200005];

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
			scanf("%d",&a[i]);
        }
        memset(cnt,0,sizeof(cnt));
        LL ret = 0;
        for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				cnt[a[j]]++;
			}
			for (int j=i+1; j<n; j++) {
				cnt[a[j]]--;
				if (a[i] == 0 && a[j] == 0) {
					ret += n-j-1;
					continue;
				}
				LL ans1 = -1,ans2 = -1,ans3 = -1;
				ans1 = a[i]*1LL*a[j];
				if (ans1 <= 200000) ret += cnt[ans1];
				if (a[j] > 0 && a[i]%a[j] == 0) {
					ans2 = a[i]/a[j];
					if (ans2 != ans1) ret += cnt[ans2];
				}
				if (a[i] > 0 && a[j]%a[i] == 0) {
					ans3 = a[j]/a[i];
					if (ans3 != ans2 && ans3 != ans1) ret += cnt[ans3];
				}
			}
			//printf("%d: %d\n",i,ret);
        }
        printf("Case #%d: %lld\n",t,ret);
	}
	return 0;
}
