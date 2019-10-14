#include <cstdio>
#include <map>
#include <vector>
using namespace std;
long long go(long long st, long long mon, long long week) {
    long long ans = 1;
    long long ori = mon/week;
    long long rem = mon%week;
    long long t1,t2;
    t1 = 0;
    if (rem == 0)
        t2 = week-1;
    else
        t2 = rem-1;
    ans = ori;
    if (rem != 0)
        ans++;
    while(st != t1) {
        t1++;
        t2++;
        if (t2==week){
            ans++;
            t2=0;
        }
    }
    return ans;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t;
    scanf("%d\n",&t);
    for (int tc=1; tc<=t; tc++) {
        long long n,m,k;
        scanf("%lld %lld %lld\n",&n,&m,&k);
        vector<long long> st;
		vector<long long> tmpans;
        map<long long,int> check;
        int last=0;
        long long cur =0;
        long long ans=0;
        bool f = false;
        for (int i=0; i<n; i++) {
            if (check.count(cur)) {
                f = true;
				for (int j=0; j<st.size(); j++) {
					tmpans.push_back(go(st[j],m,k));
				}
				int nn = st.size();
				int mm = n/nn;
				int mk = n%nn;
				for (int j=0; j<st.size(); j++) {
					if (j < mk) {
						ans += tmpans[j];
					}
					ans += tmpans[j]*mm;
				}
                break;
            }
            st.push_back(cur);
            last = i;
            check[cur] = i;
            cur += m;
            cur %= k;
        }
        if (!f) {
            for (int i=0; i<n; i++) {
                ans += go(st[i],m,k);
            }
        }
        printf("Case #%d: %lld\n",tc,ans);
    }
}
