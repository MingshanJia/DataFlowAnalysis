#include <iostream>
#include <stdio.h>
using namespace std;

void proc(int iTest);

int main() {
	int test;
	cin >> test;
	for (int iTest = 1; iTest <= test; ++iTest){
		proc(iTest);
	}
	return 0;
}

int abs(int val) {
	return val >= 0 ? val : -val;
}

void proc(int iTest) {
	int N, M;
	cin >> N;

	int **time = new int *[N];
	int *SN = new int[N];
	int *W = new int[N];
	for (int i=0; i<N; i++) {
		cin >> SN[i];
		cin >> W[i];
		time[i] = new int[SN[i]];
		time[i][0] = 0;
		for (int j=1; j<SN[i]; j++) {
			int delay;
			cin >> delay;
			time[i][j] = time[i][j-1] + delay;
		}
	}
	cin >> M;
	int (*tunnel)[5] = new int[M][5];
	for (int i=0; i<M; i++) {
		cin >> tunnel[i][0] >> tunnel[i][1] >> tunnel[i][2] >> tunnel[i][3] >> tunnel[i][4];
		tunnel[i][0]--;
		tunnel[i][1]--;
		tunnel[i][2]--;
		tunnel[i][3]--;
	}

	int exchangeNodeDist[M*2][M*2];
	for (int i=0; i<2*M; i++) {
		for (int j=0; j<i; j++) {
			int line_i = (i >= M) ? tunnel[i%M][0] : tunnel[i%M][2];
			int line_j = (j >= M) ? tunnel[j%M][0] : tunnel[j%M][2];
			if (line_i == line_j) {	//两个节点属于同一条地铁，可直接坐地铁往来
				int st_i = (i >= M) ? tunnel[i%M][1] : tunnel[i%M][3];
				int st_j = (j >= M) ? tunnel[j%M][1] : tunnel[j%M][3];
				if (st_i == st_j) {	//同一个站
					exchangeNodeDist[i][j] = exchangeNodeDist[j][i] = 0;
				} else {	//不同站，需要乘车
					exchangeNodeDist[i][j] = exchangeNodeDist[j][i] = abs(time[line_i][st_i] - time[line_i][st_j]) + W[line_i];
				}
			} else {
				exchangeNodeDist[i][j] = exchangeNodeDist[j][i] = 0x3fffffff;
			}
		}
		exchangeNodeDist[i][i] = 0;
	}
	for (int i=0; i<M; i++) {	//换乘时间
		exchangeNodeDist[i][i+M] = exchangeNodeDist[i+M][i] = tunnel[i][4];
	}

	for (int k=0; k<2*M; k++) {
		for (int i=0; i<2*M; i++) {
			for (int j=0; j<2*M; j++) {
				if (exchangeNodeDist[i][k] + exchangeNodeDist[k][j] < exchangeNodeDist[i][j]) {
					exchangeNodeDist[i][j] = exchangeNodeDist[i][k] + exchangeNodeDist[k][j];
				}
			}
		}
	}
	int Q;
	cin >> Q;
	cout << "Case #" << iTest << ": " << endl;


	// cout << M << endl;


	for (int i=0; i<Q; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		x2--;
		y2--;
		int minval = 0x3fffffff;
		if (x1 == x2) {	//try direct
			minval = abs(time[x1][y1] - time[x1][y2]) + W[x1];
		}
		//try exchange
		for (int k=0; k<2*M; k++) {//枚举x1线的换乘站
			int line_k = (k >= M) ? tunnel[k%M][0] : tunnel[k%M][2];
			if (line_k != x1) {
				continue;
			}
			int st_k = (k >= M) ? tunnel[k%M][1] : tunnel[k%M][3];

		// cout << 'x' << '\t' << x1 << '\t' << y1 << '\t' << st_k << endl;
			int valToEx1 = st_k == y1 ? 0 : (abs(time[x1][y1] - time[x1][st_k]) + W[x1]);

			for (int j=0; j<2*M; j++) {//枚举x2线的换乘站
				int line_j = (j >= M) ? tunnel[j%M][0] : tunnel[j%M][2];
				if (line_j != x2) {
					continue;
				}
				int st_j = (j >= M) ? tunnel[j%M][1] : tunnel[j%M][3];

				int valToEx2 = st_j == y2 ? 0 : (abs(time[x2][y2] - time[x2][st_j]) + W[x2]);
				// cout << k << ' ' << j << ' ' << endl;
				minval = min(minval, valToEx1 + valToEx2 + exchangeNodeDist[k][j]);
			}
		}
		if (minval == 1073741823) {
			cout << -1 << endl;
		} else {
			cout << minval << endl;
		}
	}


	// cout << M << endl;

	// for (int i=0; i<2*M; i++) {
	// 	for (int j=0; j<2*M; j++) {
	// 		cout << exchangeNodeDist[i][j] << '\t';
	// 	}
	// 	cout << endl;
	// }

	// cout << "Case #" << iTest << ": " << minval << endl;	
}