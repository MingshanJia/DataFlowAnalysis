#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

int N, R;

const int SIZE = 1000;
int edges[15][2];

struct state{
	int i, j, mask, added;
	bool operator<(const state& st)const{
		return added < st.added;
	}
};
int table[15][2][1<<15];
multiset<state> ms;

void add(state& st){
	if(table[st.i][st.j][st.mask] == -1 || st.added < table[st.i][st.j][st.mask]){
		table[st.i][st.j][st.mask] = st.added;
		ms.insert(st);
	}
}

int get(int i, int j){

	int start = edges[i][j];
	memset(table, -1, sizeof table);
	ms.clear();

	state first = {i, j, 0};
	add(first);

	int best = 1e9;
	while(!ms.empty()){
		 state st = *ms.begin(); ms.erase(ms.begin());
		 //cout << st.i << " " << st.j << " " << st.mask << " " << st.added << endl;
		 if((st.mask == (1<<R)-1)){
		 	if(st.i == i && st.j == j){
		 		best = st.added;
		 		break;
		 	}

		 	state ns = st;
		 	ns.added++;
		 	add(ns);
			continue;
		 }

		for(int k = 0 ; k < R ; k++){
			if((st.mask>>k)&1)continue;

			for(int a = 0 ; a < 2 ; a++){	//go from edge[st.i][st.j] to edges[k][a]
				int d = edges[st.i][st.j] == edges[k][a] ? 0 : 1;
				state ns = {k, 1-a, st.mask|(1<<k), st.added+d};
				add(ns);
			}
		}

	}
	return best;
}

int main(){

	//freopen("1.in", "rt", stdin);
	//freopen("1.out", "wt", stdout);
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);
	//freopen("B-large.in", "rt", stdin);
	//freopen("B-large.out", "wt", stdout);

	int tt; cin >> tt;
	for(int t = 0 ; t < tt ; t++){
		cerr << t << endl;
		cin >> N >> R;
		for(int i = 0 ; i < R ; i++){
			int x, y; cin >> x >> y;
			edges[i][0] = x;
			edges[i][1] = y;
		}

		int best = 1e9;
		for(int i = 0 ; i < R ; i++)
			for(int j = 0 ; j < 2 ; j++)
				best <?= get(i, j);

		cout << "Case #" << t+1 << ": " << best << endl;
	}

	return 0;
}

