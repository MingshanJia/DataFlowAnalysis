#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>

#define REP(a,b) for (int a = 0; a < b; a++)
#define FOR(a,b,c) for (int a = b; a <= c; a++)
#define RESET(a,b) memset(a,b,sizeof a)

#define PB push_back
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

#define EPS 1e-8
#define INF 1023123123
#define LL long long
#define __ puts("")

#define MAXN 105

using namespace std;

int T, N;
int ar[MAXN];
int FULL = 127;
int disp[10];

void prep(){
	RESET(disp,0);

	// 0
	disp[0] = FULL;
	disp[0] ^= (1 << 6);

	// 1
	disp[1] |= (1 << 1);
	disp[1] |= (1 << 2);

	// 2
	disp[2] |= (1 << 0);
	disp[2] |= (1 << 1);
	disp[2] |= (1 << 6);
	disp[2] |= (1 << 4);
	disp[2] |= (1 << 3);

	// 3
	disp[3] |= (1 << 0);
	disp[3] |= (1 << 1);
	disp[3] |= (1 << 6);
	disp[3] |= (1 << 2);
	disp[3] |= (1 << 3);

	// 4
	disp[4] |= (1 << 5);
	disp[4] |= (1 << 6);
	disp[4] |= (1 << 1);
	disp[4] |= (1 << 2);

	// 5
	disp[5] |= (1 << 0);
	disp[5] |= (1 << 5);
	disp[5] |= (1 << 6);
	disp[5] |= (1 << 2);
	disp[5] |= (1 << 3);

	// 6
	disp[6] |= (1 << 0);
	disp[6] |= (1 << 5);
	disp[6] |= (1 << 6);
	disp[6] |= (1 << 2);
	disp[6] |= (1 << 3);
	disp[6] |= (1 << 4);

	// 7
	disp[7] |= (1 << 0);
	disp[7] |= (1 << 1);
	disp[7] |= (1 << 2);

	// 8
	disp[8] = FULL;

	// 9
	disp[9] |= (1 << 0);
	disp[9] |= (1 << 1);
	disp[9] |= (1 << 2);
	disp[9] |= (1 << 3);
	disp[9] |= (1 << 5);
	disp[9] |= (1 << 6);
}

int pred(int x){
	if (x == 0){
		return 9;
	}
	return x-1;
}

int inv(int x){
	return FULL ^ x;
}

bool match(int okMask, int now, int test){
	return (okMask & now) == test; 
}

bool isSubset(int a, int b){
	return (a & b) == a;
}

string tos(int val){
	string ret = "";
	REP(i,7){
		if (val & 1){
			ret += '1';
		}else{
			ret += '0';
		}

		val /= 2;
	}

	return ret;
}

int main(){
	prep();

	scanf("%d", &T);
	REP(jt,T){
		scanf("%d", &N);
		REP(i,N){
			char sc[10];
			scanf("%s", sc);

			int val = 0;
			REP(j,7){
				if (sc[j] == '1'){
					val |= (1<<j);
				}
			}

			ar[i] = val;
		}

		// try all
		set<int> hsol;
		hsol.clear();

		int sol;

		REP(mas,1<<7){
			FOR(i,0,9){
				int now = i;
				bool consistent = 1;

				REP(j,N){
					if (!isSubset(ar[j], mas)){
						consistent = 0;
						break;
					}
					if (!match(mas, disp[now], ar[j])){
						consistent = 0;
						break;
					}

					now = pred(now);
				}

				if (consistent){
					sol = mas & disp[now];
					hsol.insert(sol);

//					printf("%d mask=%d %d\n", i, mas, consistent);
				}
			}
		}
/*
		for (set<int>::iterator it = hsol.begin(); it != hsol.end(); it++){
			printf("nih %d\n", *it);
		}
*/
		printf("Case #%d: ", jt+1);
		if (hsol.size() == 1){
			printf("%s\n", tos(sol).c_str());
		}else{
			printf("ERROR!\n");
		}
	}	
}
