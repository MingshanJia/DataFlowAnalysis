/* DIKRA */
/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

int ntc;
int w, h, n;
int a[205][205];

class Tetromino{
private:
	int x;
	int b[5][5];

	int topIsVoid(){
		REP(i, 4){
			if (b[0][i]) return 0;
		}
		return 1;
	}

	int leftIsVoid(){
		REP(i, 4){
			if (b[i][0]) return 0;
		}
		return 1;
	}

	void rotate(){
		int tmp[5][5];
		RESET(tmp, 0);
		REP(i, 4)
			REP(j, 4){
				tmp[3-j][i] = b[i][j];
			}

		REP(i, 4)
			REP(j, 4){
				b[i][j] = tmp[i][j];
			}


		// push to top
		while (topIsVoid()){
			REP(i, 4){
				REP(j, 4){
					if (i == 3) b[i][j] = 0;
					else b[i][j] = b[i+1][j];
				}
			}
		}

		// push to left
		while (leftIsVoid()){
			REP(j, 3){
				REP(i, 4){
					if (j == 3) b[i][j] = 0;
					else b[i][j] = b[i][j+1];
				}
			}
		}
	}

public:


	Tetromino(int t, int r, int _x){
		x = _x;
		RESET(b, 0);
		switch (t){
			case 1:
				b[0][0] = 1;
				b[1][0] = 1;
				b[1][1] = 1;
				b[2][1] = 1;
				break;
			case 2:
				b[0][1] = 1;
				b[1][0] = 1;
				b[1][1] = 1;
				b[2][0] = 1;
				break;
			case 3:
				b[0][0] = 1;
				b[1][0] = 1;
				b[2][0] = 1;
				b[2][1] = 1;
				break;
			case 4:
				b[0][1] = 1;
				b[1][1] = 1;
				b[2][0] = 1;
				b[2][1] = 1;
				break;
			case 5:
				b[0][0] = 1;
				b[0][1] = 1;
				b[1][0] = 1;
				b[1][1] = 1;
				break;
			case 6:
				b[0][0] = 1;
				b[1][0] = 1;
				b[2][0] = 1;
				b[3][0] = 1;
				break;
			case 7:
				b[0][1] = 1;
				b[1][0] = 1;
				b[1][1] = 1;
				b[1][2] = 1;
				break;
			default:
				break;
		}

		while (r--){
			rotate();
		}
	}

	int canPut(int pos){
		REP(i, 4){
			REP(j, 4){
				if (b[i][j]){
					if (i+pos >= h+4) return 0;
					if (a[i+pos][j+x]) return 0;
				}
			}
		}
		return 1;
	}

	void putAt(int pos){
		REP(i, 4){
			REP(j, 4){
				if (b[i][j]){
					a[i+pos][j+x] = 1;
				}
			}
		}
	}
};



int drop(Tetromino *tetro){
	int pos = 0;
	while (pos < h+4 && tetro->canPut(pos)) pos++;
	pos--;

	if (pos < 4){
		delete tetro;
		return 0;
	}

	tetro->putAt(pos);
	delete tetro;
	return 1;
}

int isFilled(int pos){
	REP(j, w){
		if (a[pos][j] == 0) return 0;
	}
	return 1;
}

void clear(){
	FOR(i, 4, h+3){
		if (isFilled(i)){
			FORD(j, i, 4){
				REP(k, w){
					a[j][k] = a[j-1][k];
					a[j-1][k] = 0;
				}
			}
		}
	}
}


int main(){
	OPEN("b");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc){
		scanf("%d %d %d", &w, &h, &n);
		//printf("w = %d, h = %d, n = %d\n", w, h, n);
		int flag = 1;
		RESET(a, 0);
		REP(i, n){
			int t, r, x;
			scanf("%d %d %d", &t, &r, &x);

			if (flag) flag = drop(new Tetromino(t,r,x));
			if (flag == 0) continue;
			clear();
		}

		printf("Case #%d:\n", itc);
		if (flag){
			FOR(i, 4, h+3){
				REP(j, w){
					if (a[i][j]) printf("x");
					else printf(".");
				}
				printf("\n");
			}
		} else {
			printf("Game Over!\n");
		}
		
	}
	return 0;
}









