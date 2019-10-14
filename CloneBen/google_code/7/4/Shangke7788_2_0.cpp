#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 101010;
int n, now;
map<string, int> mp;
map<int, string> st;

char s2[MAX_N];

int din[MAX_N], dout[MAX_N];

int head[MAX_N], nxt[MAX_N << 1], to[MAX_N << 1], e;
vector<int> ans;

void gao(int src) {
	if (dout[src] == 0) {
		ans.push_back(src);
		return;
	}
	for (int i = head[src]; ~i; i = nxt[i]) {
		int v = to[i];
		if (din[v]) {
			--dout[src], --din[v];
			gao(v);
		}
	}
	ans.push_back(src);
}

void addEdge(int u, int v) {
	to[e] = v, nxt[e] = head[u], head[u] = e++;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		scanf("%d", &n);
		now = 0, mp.clear(), st.clear();
		memset(head, -1, sizeof head), e = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", s2);
			string s = s2;
			if (mp.find(s) == mp.end()) {
				mp[s] = now;
				st[now++] = s;
			}
			int u = mp[s];
			scanf("%s", s2);
			s = s2;
			if (mp.find(s) == mp.end()) {
				mp[s] = now;
				st[now++] = s;
			}
			int v = mp[s];
			++dout[u], ++din[v];
			addEdge(u, v);
		}
		int src = -1;
		for (int i = 0; i < now; i++) {
			if (dout[i] > din[i]) {
				src = i;
				break;
			}
		}
		ans.clear();
		gao(src);
		reverse(ans.begin(), ans.end());
		printf("Case #%d: ", ca);
		for (int i = 0; i < (int)ans.size() - 1; i++) {
			printf("%s-%s%c", st[ans[i]].c_str(), st[ans[i + 1]].c_str(), " \n"[i == (int)ans.size() - 2]);
		}
	}
	return 0;
}
