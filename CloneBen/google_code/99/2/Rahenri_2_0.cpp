/* Code written by Raphael Henrique Ribas
 * Language: C++
 * Reads input from stdin
 * Writes output to stdout
 * Best compiled with g++
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <vector>
#include <bitset>
#include <cctype>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#define foreach(it, cont) for(typeof((cont).begin()) it = (cont).begin() ;\
        it != (cont).end(); ++it)

#define debug(x) clog << #x "=" << x << endl

#define two(x) (1ll<<(x))

using namespace std;

double odds[32][4];

double attempt[4096];


template <class T> string to_str(const T& t) {
    stringstream stream; stream << t; return stream.str();
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;++t) {

		int M, Q;

		scanf("%d%d", &M, &Q);
	
		for(int i=0;i<Q;++i) {
			for(int j=0;j<4;++j) {
				scanf("%lf", &odds[i][j]);
			}
		}

		int p = (1<<(Q*2));
		for(int i=0;i<p;++i) {
			double tmp=1.0;
			for(int j=0;j<Q;++j) {
				int k = (i>>(j*2))&3;
				tmp *= odds[j][k];
			}
			attempt[i]=tmp;
		}

		sort(attempt, attempt+p);
		reverse(attempt, attempt+p);

		double resp = 0.0;
		for(int i=0;i<min(M, p);++i) {
			resp += attempt[i];
		}

        printf("Case #%d: %.7f\n", t, resp);
        fflush(stdout);
    }
    return 0;
}
