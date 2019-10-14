#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
	int to;
	int time;
}path;

typedef struct {
	int W;
	vector<path> p;
	vector<path> t;
}point;

point loc[2000];
bool vis[2000][2];

int station[100][1000];

class node {
public:
	int time;
	int loc;
	int aftertunnel;
};

bool operator<(const node& a, const node& b) {
	return a.time > b.time;
}

int dij(int st, int ed) {
	if (st == ed) return 0;
	priority_queue<node> q;
	memset(vis, 0, sizeof(vis));
	node temp;
	temp.loc = st;
	temp.time = 0;
	temp.aftertunnel = 1;
	q.push(temp);
	while (!q.empty()) {
		temp = q.top();
		q.pop();
		if (vis[temp.loc][temp.aftertunnel]) continue;
		vis[temp.loc][temp.aftertunnel] = true;
		if (temp.loc == ed) {
			return temp.time;
		}
		for (auto it = loc[temp.loc].p.begin(); it != loc[temp.loc].p.end();it++) {
			node temp2;
			temp2.time = it->time + temp.time + (temp.aftertunnel ? loc[temp.loc].W : 0);
			temp2.loc = it->to;
			temp2.aftertunnel = 0;
			if (vis[temp2.loc][temp2.aftertunnel]) continue;
			q.push(temp2);
		}
		for (auto it = loc[temp.loc].t.begin(); it != loc[temp.loc].t.end(); it++) {
			node temp2;
			temp2.time = it->time + temp.time;
			temp2.loc = it->to;
			temp2.aftertunnel = 1;
			if (vis[temp2.loc][temp2.aftertunnel]) continue;
			q.push(temp2);
		}
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int counts = 0;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int SN, W;
			cin >> SN >> W;
			for (int j = 0; j < SN; j++) {
				loc[counts].p.clear();
				loc[counts].t.clear();
				station[i][j] = counts++;
				loc[station[i][j]].W = W;
				if (j) {
					int time;
					cin >> time;
					path newp;
					newp.time = time;
					newp.to = station[i][j];
					loc[station[i][j - 1]].p.push_back(newp);
					newp.to = station[i][j - 1];
					loc[station[i][j]].p.push_back(newp);
				}
			}
		}
		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int m1, s1, m2, s2, t;
			cin >> m1 >> s1 >> m2 >> s2 >> t;
			path newp;
			newp.time = t;
			newp.to = station[m2 - 1][s2 - 1];
			loc[station[m1 - 1][s1 - 1]].t.push_back(newp);
			newp.to = station[m1 - 1][s1 - 1];
			loc[station[m2 - 1][s2 - 1]].t.push_back(newp);
		}
		int Q;
		cin >> Q;
		cout << "Case #" << cas << ":" << endl;
		while (Q--) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << dij(station[x1 - 1][y1 - 1], station[x2 - 1][y2 - 1]) << endl;
		}
	}
}