#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, vector<pair<string, bool> > > g;
map<string, int> in, out;
int N;

vector<string> ans;

void go(string s)
{
	for (auto &p : g[s]){
		if (!p.second){
			p.second = 1;
			go(p.first);
			ans.push_back(s+"-"+p.first);
		}
	}
}

int main()
{
	freopen ("1.in","r",stdin);
	freopen ("1.out","w",stdout);

	int Test; cin >> Test; for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);
		cin >> N;

		g.clear(); in.clear(); out.clear();
		while (N--){
			string a,b; cin >> a >> b;
			g[a].push_back(make_pair(b,false));
			in[a]; out[a]; in[b]; out[b];
			in[b]++; out[a]++;
		}

		string s = "";
		for (auto p : in){
			if (p.second - out[p.first] == -1){
				s = p.first; break;
			}
		}
		if (s == "") s = in.begin()->first;

		ans.clear();
		go(s);

		for (int i=ans.size()-1;i>=0;i--) cout << ans[i] << " ";
		cout << endl;
	}

	return 0;
}