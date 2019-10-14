//AV
//quasar

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> graph;

int grp[101];
graph g;

bool add(int i, int gp){
	if (grp[i] == gp)return true;
	if (grp[i] == -1 )
		grp[i] = gp;
	else return false;
	bool f = true;
	for (int j : g[i]){
		f &= add(j, !gp);
		if (!f)return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n, cs=1;
	cin >> t;
	while (t--){
		cin >> n;
		string a, b;
		int x, y;
		map<string, int> mp;
		map<string, int>::iterator it;
		g.clear();
		g.resize(n + 1);

		for (int i = 0; i < n; i++){
			cin >> a >> b;
			it = mp.find(a);
			if (it == mp.end())
				x=mp[a] = mp.size();
			else x = it->second;
			it = mp.find(b);
			if (it == mp.end())
				y = mp[b] = mp.size();
			else y = it->second;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		fill(grp, grp + 101, -1);
		bool f = true;
		for (int i = 0; i < mp.size(); i++){
			if (grp[i] == -1)
				f&=add(i, 0);
			if (!f)break;
		}
		cout << "Case #" << cs++ << ": ";
		if (f)cout << "Yes\n";
		else cout << "No\n";
	}
}
