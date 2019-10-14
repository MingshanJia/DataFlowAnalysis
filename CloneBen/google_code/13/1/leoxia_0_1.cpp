#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int T, M;
unordered_map<string, int> names;
int p[200], r[200], e[200];

int getId(const string& name) {
	unordered_map<string, int>::iterator it = names.find(name);
	if (it == names.end()) {
		int id = names.size();
		names[name] = id;
		return id;
	} else {
		return it->second;
	}
}


int find_set(int x) {
  if (p[x] != x) {
    p[x] = find_set(p[x]);
  }
  return p[x];
}


void union_set(int x, int y) {
  int u = find_set(x);
  int v = find_set(y);
  if (r[u] < r[v]) {
    p[u] = v;
  } else {
    p[v] = u;
    if (r[u] == r[v]) {
      r[v]++;
    }
  }
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> M;
		
		names.clear();
		for (int i = 0; i < 200; i++) {
			p[i] = i; r[i] = 0; e[i] = -1;
		}

		string A, B;
		int a, b, ra, rb;
		bool res = true;
		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			if (!res) continue;
			a = getId(A); b = getId(B);
			ra = find_set(a); rb = find_set(b);
			if (ra == rb) {
				res = false;
			} else {
				if (e[ra] != -1 && e[rb] != -1) {
					union_set(ra, e[rb]);
					union_set(rb, e[ra]);
				} else if (e[ra] != -1) {
					union_set(rb, e[ra]);
				} else if (e[rb] != -1) {
					union_set(ra, e[rb]);
				}
				ra = find_set(ra);
				rb = find_set(rb);
				e[ra] = rb;
				e[rb] = ra;
			}
		}

		cout << "Case #" << t << ": " << (res ? "Yes" : "No") << endl;
	}
	return 0;
}