#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n;
pair<char, int> ev[2000];
int T, teste;

int entrances[3500];
int exits[3500];

bool is_feasible(int unknown) {
	int clear = 0;
	
	for (int i = 0; i <= 3100; i++) {
		entrances[i] = 6000;
		exits[i] = 6001;
	}	

	set<int> no_enter;
	set<int> no_exit;
	set<int> premature_exit;
	set<int> premature_enter;

	for (int i = 0; i < n; i++) {
		if (ev[i].second != 0) {
			if (ev[i].first == 'E') {
				if (entrances[ev[i].second] == 6000)
					entrances[ ev[i].second ] = i;
			}
			else {
				if (exits[ ev[i].second ] == 6001)
					exits[ ev[i].second ] = i;
			}
		}
	}

	set<int> inside;
	
	int throwaway = 3100;

	for (int k = 0; k < n + unknown; k++) {
		if (k < unknown) {
			int mid = -1;

			for (int id = 0; id <= 2000; id++) if (!inside.count(id)) {
				if (exits[id] < entrances[id]) {
					if (mid == -1 || exits[id] < exits[mid]) mid = id;
				} 
			}

			if (mid == -1) {
				mid = throwaway--;
			}

			inside.insert(mid);
		} 

		else {
			int i = k-unknown;
			
			if (ev[i].first == 'E') {
				if (ev[i].second == 0) {
					int mid = -1;

					for (int id = 0; id <= 2000; id++) if (!inside.count(id)) {
						if (exits[id] < entrances[id]) {
							if (mid == -1 || exits[id] < exits[mid]) mid = id;
						} 
					}

					if (mid == -1) {
						mid = throwaway--;
					}

					inside.insert(mid);
				}

				else {
					if (inside.count(ev[i].second)) return false;
					inside.insert(ev[i].second);

					int id = ev[i].second;

					bool found = false;
					for (int j = i+1; j < n; j++) {
						if (ev[j].first == 'E' && ev[j].second == ev[i].second) {
							entrances[id] = j;
							found = true;
							break;
						}
					}
					if (!found) entrances[id] = 6000;
				}
			}

			else {
				if (inside.size() == 0) return false;

				if (ev[i].second == 0) {
					int mid = -1;

					for (set<int>::iterator it = inside.begin(); it != inside.end(); it++) {
						if (entrances[*it] < exits[*it] && entrances[*it] != 6000) {
							if (mid == -1 || entrances[*it] < entrances[mid]) mid = *it;
						}
					}

					if (mid == -1) {
						for (set<int>::iterator it = inside.begin(); it != inside.end(); it++) {
							if (mid == -1 || exits[*it] > exits[mid]) mid = *it;
						}
					}

					inside.erase(mid);
				}

				else {
					if (!inside.count(ev[i].second)) return false;
					inside.erase(ev[i].second);

					int id = ev[i].second;

					bool found = false;
					for (int j = i+1; j < n; j++) {
						if (ev[j].first == 'L' && ev[j].second == ev[i].second) {
							exits[id] = j;
							found = true;
							break;
						}
					}
					if (!found) exits[id] = 6001;
				}
			}
		}
	}

	return true;
}

int main() {	
	for (scanf("%d", &T) ;T ;T--) {
		printf("Case #%d: ", ++teste);
		fprintf(stderr, "At case %d\n", ++teste)

		scanf("%d", &n);
		int tot = 0;
		for (int i = 0; i < n; i++) {
			scanf(" %c %d", &ev[i].first, &ev[i].second);
			if (ev[i].first == 'E') tot++;
			else tot--;
		}

		int best = 1000000;
		int st = 0, end = 1100;
		while (st < end && st <= 1000) {
			int mid = (st+end)/2;
			if (is_feasible(mid)) {
				end = mid;
			}
			else st = mid+1;
		}

		if (st > 1000) printf("CRIME TIME\n");
		else printf("%d\n", st+tot);
	}
}