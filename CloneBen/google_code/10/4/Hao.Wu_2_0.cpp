#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class point {
public:
	int index;
	int odd;
	int result;
};

class edge {
public:
	int to;
	int value;
};

bool vis[10000][2];

int main() {
	freopen("input.txt","r",stdin);
	int T;
	cin.sync_with_stdio(false);
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		vector<edge> v[10000];
		int counts = 0;
		map<string, int> m;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string formula;
			cin >> formula;
			int plus, equal;
			for (int j = 0; j < formula.size(); j++) {
				if (formula[j] == '+') plus = j;
				else if (formula[j] == '=') equal = j;
			}
			string a, b;
			int z;
			a = formula.substr(0, plus);
			b = formula.substr(plus + 1, equal - plus - 1);
			z = stoi(formula.substr(equal + 1));
			if (m.find(a) == m.end()) {
				m[a] = counts;
				counts++;
			}
			if (m.find(b) == m.end()) {
				m[b] = counts;
				counts++;
			}
			edge e;
			e.to = m[b];
			e.value = z;
			v[m[a]].push_back(e);
			e.to = m[a];
			v[m[b]].push_back(e);
		}
		cin >> n;
		cout << "Case #" << cas << ": " << endl;
		for (int i = 0; i < n; i++) {
			string formula;
			cin >> formula;
			int plus;
			for (int j = 0; j < formula.size(); j++) {
				if (formula[j] == '+') plus = j;
			}
			string a, b;
			a = formula.substr(0, plus);
			b = formula.substr(plus + 1);
			if (m.find(a) == m.end() || m.find(b) == m.end()) {
				//cout << "ERROR!" << endl;
				continue;
			}
			int ma = m[a];
			int mb = m[b];
			memset(vis, 0, sizeof(vis));
			queue<point> q;
			point begin;
			begin.index = ma;
			begin.odd = 0;
			begin.result = 0;
			vis[ma][0] = true;
			q.push(begin);
			bool found = false; 
			int result;
			while (!found && !q.empty()) {
				begin = q.front();
				q.pop();
				ma = begin.index;
				int newodd = 1 - begin.odd;
				for (int j = 0; j < v[ma].size(); j++) {
					if (vis[v[ma][j].to][newodd]) continue;
					point newpoint;
					vis[v[ma][j].to][newodd] = true;
					newpoint.index = v[ma][j].to;
					newpoint.odd = newodd;
					newpoint.result = begin.result;
					if (newodd) {
						newpoint.result += v[ma][j].value;
					}
					else {
						newpoint.result -= v[ma][j].value;
					}
					q.push(newpoint);
					if (v[ma][j].to == mb && newodd) {
						found = true;
						result = newpoint.result;
						break;
					}
				}
			}
			if (found) {
				cout << a << "+" << b << "=" << result << endl;
			}
		}
	}
}
