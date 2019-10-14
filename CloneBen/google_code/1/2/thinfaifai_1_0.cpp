#include<bits/stdc++.h>
using namespace std;
#define LL long long

struct seg {
	int l,r;
} s[500005];

struct query {
	int k, id;
} qy[100005];

bool cmp(query a,query b) {
	return a.k>b.k;
}

int n,q;
int x[500005];
map<int, int> mp;

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
        scanf("%d%d",&n,&q);
        int a,b,c,m;
        LL tot = 0;
        mp.clear();

        scanf("%d%d%d%d%d%d",&x[0],&x[1],&a,&b,&c,&m);
        s[0].l = x[0]; s[1].l = x[1];
        for (int i=2; i<n; i++) {
			x[i] = (a*1LL*x[i-1] + b*1LL*x[i-2] + c)%m;
			s[i].l = x[i];
        }
        scanf("%d%d%d%d%d%d",&x[0],&x[1],&a,&b,&c,&m);
        s[0].r = x[0]; s[1].r = x[1];
        for (int i=2; i<n; i++) {
			x[i] = (a*1LL*x[i-1] + b*1LL*x[i-2] + c)%m;
			s[i].r = x[i];
        }
        for (int i=0; i<n; i++) {
			if (s[i].l > s[i].r) swap(s[i].l,s[i].r);
			s[i].l++; s[i].r++;
			//printf("%d %d\n",s[i].l,s[i].r);
			if (mp.find(s[i].l) == mp.end()) mp[s[i].l] = 1;
			else mp[s[i].l]++;
			if (mp.find(s[i].r+1) == mp.end()) mp[s[i].r+1] = -1;
			else mp[s[i].r+1]--;
			tot += s[i].r-s[i].l+1;
        }

		//printf("Tot %lld\n",tot);
        /*
		for (auto it=mp.begin(); it!=mp.end(); it++) {
			printf("%d: %d\n",(*it).first,(*it).second);
		}
		*/



		scanf("%d%d%d%d%d%d",&x[0],&x[1],&a,&b,&c,&m);
		for (int i=2; i<q; i++) {
			x[i] = (a*1LL*x[i-1] + b*1LL*x[i-2] + c)%m;
        }
        for (int i=0; i<q; i++) {
			x[i]++;
			qy[i].k = x[i]; qy[i].id = i+1;
        }

        sort(qy,qy+q,cmp);
        auto it = mp.begin();
        int cnt = (*it).second,lastsco = (*it).first;
        it++;
        LL curr = 1;
        LL ret = 0;
        for (int i=0; i<q; i++) {
			//printf("q %d (%d)\n",qy[i].k,qy[i].id);
			if (qy[i].k > tot) continue;
			LL kk = tot-qy[i].k+1;

			LL next = ((*it).first - lastsco)*1LL*cnt;
			//printf("kk %d next %lld\n",kk,next);
			while (curr + next <= kk) {
				lastsco = (*it).first;
				cnt += (*it).second;
				curr += next;
				it++;
				next = ((*it).first - lastsco)*1LL*cnt;
			}
			int realsco = lastsco+(kk-curr)/cnt;
			ret += realsco*1LL*qy[i].id;
			//printf("sco %d (r%lld)\n",realsco,curr);
        }
        printf("Case #%d: %lld\n",t,ret); fflush(stdout);
	}
	return 0;
}
