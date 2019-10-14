#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 55;
const int INF = 1e9;
typedef pair<int,int> pii;
int dist[MAXN][MAXN];
int ori[MAXN][MAXN];
 
void setmin(int &a, int b) {
    if (b < a) a = b;
}

int main() {
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int b;
		cin >> b;
		for (int i = 1; i < b; i++) {
			for (int j = 0; j < i; j++) {
				int w;
				cin >> w;
				if (w == -1) w = INF;
				dist[i][j] = w;
				ori[i][j] = w;
				dist[j][i] = w;
				ori[j][i] = w;
			}
		}
		for (int i = 0; i < b; i++) {
        	dist[i][i] = 0;
		}
		for (int k = 0; k < b; k++) {
		    for (int i = 0; i < b; i++) {
		        for (int j = 0; j < b; j++) {
		            // relax distance
		            setmin(dist[i][j], dist[i][k] + dist[k][j]);
		        }
		    }
		}
		double best = INF;
		for (int i = 1; i < b; i++) {
			for (int j = 0; j < i; j++) {
				if (ori[i][j] == -1) continue;
				double curmax = -INF;
				// put in middle
				for (int k = 0; k < b; k++) {
					curmax = max(curmax, (double)min(dist[i][k], dist[j][k]));
				}
				curmax += ori[i][j]/2.0;
				// put in right
				double curmax2 = -INF;
				for (int k = 0; k < b; k++) {
					curmax2 = max(curmax2, (double)min(dist[i][k]+ori[i][j], dist[j][k]));
				}
				// put in left
				double curmax3 = -INF;
				for (int k = 0; k < b; k++) {
					curmax3 = max(curmax3, (double)min(dist[i][k], dist[j][k]+ori[i][j]));
				}
				// put in right
				double curmax4 = -INF;
				for (int k = 0; k < b; k++) {
					curmax4 = max(curmax4, (double)min(dist[i][k]+ori[i][j]*0.75, dist[j][k]+ori[i][j]*0.25));
				}
				// put in left
				double curmax5 = -INF;
				for (int k = 0; k < b; k++) {
					curmax5 = max(curmax5, (double)min(dist[i][k]+ori[i][j]*0.25, dist[j][k]+ori[i][j]*0.75));
				}
				best = min(best,min(curmax, min(curmax2, min(curmax3, min(curmax4, curmax5)))));
			}
		}
		cout << "Case #" << tc+1 << ": " << best << endl;
	}
}

















