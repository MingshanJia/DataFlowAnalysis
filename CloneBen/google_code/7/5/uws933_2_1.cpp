#include <iostream>
#include <map>
#include <string>
using namespace std;

int parent[10010];
int child[10010];
string name[10010];

int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		map<string, int> m;
		memset(parent, -1, sizeof(parent));
		memset(child, -1, sizeof(child));
		int counts = 0;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string start, end;
			cin >> start >> end;
			int sint, eint;
			if (m.find(start) == m.end()) {
				m[start] = counts;
				name[counts] = start;
				counts++;
			}
			if (m.find(end) == m.end()) {
				m[end] = counts;
				name[counts] = end;
				counts++;
			}
			sint = m[start];
			eint = m[end];
			parent[eint] = sint;
			child[sint] = eint;
		}
		int start = 0;
		while (parent[start] != -1) start = parent[start];
		cout << "Case #" << cas << ":";
		while (child[start] != -1) {
			cout << " " << name[start] << "-" << name[child[start]];
			start = child[start];
		}
		cout << endl;
	}
}