#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

void debug1(){}

template<class T, class ... Tails>
void debug1(const T &v, const Tails& ... tails){
	cout<<" "<<v;
	debug1(tails...);
}

template<class T, class ... Tails>
void debug(const T &v, const Tails& ... tails){
#ifdef LOCAL
	cout<<"Debug: "<<v;
	debug1(tails...);
	cout<<endl;
#endif
}

const R PI = acos(-1);
const int MAXN = 1<<20;
const int P = 1e9+7;


int s[20];
int s2[20];
int q[100000][20];
int C[20][20];
char in[20];
int h, t;
ll ans;

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		int i, j, k;
		scanf("%s", in);
		int n = strlen(in);
		for(i = 0; i < n; i++)
			q[0][i] = in[i]-'0';
		if(q[0][0] == 1){
			for(i = 1; i < n; i++)
				if(q[0][i] != 0)
					break;
			if(i == n){
				ans = 1;
				for(i = 0; i < n; i++)
					ans *= n+1;
				ans--;
				printf("Case #%d: %lld\n", i0, ans);
				continue;
			}
		}
		C[0][0] = 1;
		for(i = 1; i <= n; i++){
			C[i][0] = 1;
			for(j = 1; j <= i; j++)
				C[i][j] = C[i-1][j] + C[i-1][j-1];
		}

		ans = 1;
		h = 0;
		t = 1;
		while(h < t){
			for(i = 0; i < n; i++)
				s[i] = q[h][i];
			h++;
			int cnt = 0;
			for(i = 0; i < n; i++)
				cnt += s[i];
			if(cnt > n)
				continue;
			ll prod = 1;
			cnt = 0;
			for(i = 0; i < n; i++){
				cnt += s[i];
				prod *= C[cnt][s[i]];
			}
			prod *= C[n][cnt];
			ans += prod;
			int sum = 0;
			for(i = 0; i < n; i++)
				sum += (i+1) * s[i];
			if(sum > n)
				continue;
			cnt = n-cnt;
			for(i = 0; i < cnt; i++)
				s2[i] = 0;
			for(i = 0; i < n; i++)
				for(j = 0; j < s[i]; j++)
					s2[cnt++] = i+1;
			while(true){
				for(i = 0; i < n; i++)
					q[t][i] = s2[i];
				t++;
				if(!next_permutation(s2, s2+n))
					break;
			}
		}
		//cout<<t<<endl;
		printf("Case #%d: %lld\n", i0, ans);
	}
	return 0;
}
