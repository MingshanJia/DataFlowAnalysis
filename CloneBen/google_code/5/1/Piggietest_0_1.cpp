#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <cstdio>
#include <list>

using namespace std;

typedef pair <int, int> PII;
typedef pair <int, double> PID;
typedef pair <double, double> PDD;
typedef vector <int> VI;
typedef vector <double> VD;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout

int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";

		int m, n = 0;
		map <string, vector <string>> graph;
		map <string, int> color;

		graph.clear();
		color.clear();

		cin >> m;

		for (int i = 0; i < m; i++) {
			string str1, str2;

			cin >> str1 >> str2;

			if (color.find(str1) == color.end()) {
				color[str1] = -1;
				graph[str1] = vector <string> ();

				n++;
			}

			if (color.find(str2) == color.end()) {
				color[str2] = -1;
				graph[str2] = vector <string> ();

				n++;
			}

			graph[str1].PB(str2);
			graph[str2].PB(str1);
		}

		bool ans = true;

		while (ans and n > 0) {
			queue <string> q;

			while (!q.empty()) q.pop();

			string node;
			int o = 0;

			for (auto item : color) {
				if (item.second < 0) {
					node = item.first;

					break;
				}
			}

			color[node] = o;
			q.push(node);

			n--;

			while (ans and !q.empty()) {
				node = q.front();

				q.pop();

				o = 1 - color[node];

				for (auto item : graph[node]) {
					if (color[item] < 0) {
						color[item] = o;
						q.push(item);

						n--;
					}
					else if (color[item] != o) {
						ans = false;

						break;
					}
				}
			}
		}

		if (ans)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}
