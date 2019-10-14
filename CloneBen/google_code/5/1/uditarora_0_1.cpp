#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
#include <cstdlib>
#include <string>
#include <queue>
using namespace std;

unordered_map<string, vector<string> > bad;
unordered_map<string, int> color;

bool check(string start) {
	queue<string> q;
	q.push(start);
	color[start] = 1;
	while (!q.empty()) {
		start = q.front();
		q.pop();
		vector<string> temp = bad[start];
		for (int i = 0; i < temp.size(); ++i) {
			if (color[temp[i]] == color[start]) {
				return false;
			}
			else if (color[temp[i]] == 0) {
				if (color[start] == 1)
					color[temp[i]] = 2;
				else
					color[temp[i]] = 1;
				q.push(temp[i]);
			}
		}
	}
	return true;
}

int main(void) {
	int t, m;
	string name1, name2;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		bad.clear(); color.clear();
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			cin >> name1 >> name2;
			bad[name1].push_back(name2);
			bad[name2].push_back(name1);
		}
		bool ans = true;
		for (auto it = bad.begin(); it != bad.end(); ++it) {
			if (color[it->first] == 0) {
				if (!check(it->first)) {
					ans = false;
					break;
				}
			}
		}
		printf("Case #%d: ", i);
		if (ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}