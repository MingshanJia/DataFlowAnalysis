#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	long long cnt[10005];
	int t1 = t;
	while(t--) {
		long long q;
		cin>>q;
		for(int i = 0; i<1001; i++) {
			cnt[i] = 0;
		}
		for(int i = 0; i<q; i++) {
			long long t1, t2;
			cin>>t1>>t2;
			cnt[t2] += t1;
		}
		long long rem = 0;
		long long max1 = 0;
		for(int i = 0; i<=1000; i++) {
			if(cnt[i]>0) {
				max1 = i;
			}
			rem-= (cnt[i]) * i;
			rem = max(rem, (long long)0);
			rem+= cnt[i];
		}
		printf("Case #%d: ", t1-t);
		cout<<max(max1 + 1, rem)<<endl;
	}
	return 0;
}