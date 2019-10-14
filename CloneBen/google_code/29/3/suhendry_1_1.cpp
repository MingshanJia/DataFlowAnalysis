#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int (i)=0,_n=(n);(i)<_n;(i)++)
#define FOR(i,a,b) for(int (i)=(a),_n=(b);(i)<=_n;(i)++)
#define FORD(i,a,b) for(int (i)=(a),_n=(b);(i)>=_n;(i)--)

const int inf = 0x7fffffff;

char a[10005];
char b[10005];

enum { NORTH, EAST, SOUTH, WEST };
int left(int d) { return (d + 3) % 4; }
int right(int d) { return (d + 1) % 4; }
int pr[] = { -1, 0, 1, 0 };
int pc[] = { 0, 1, 0, -1 };
int out[] = { 0, 3, 1, 2 };

int main()
{
	int ncase;
	scanf( "%d", &ncase );

	FOR(tcase,1,ncase) {
		scanf( "%s %s", a, b );
		
		int rlo = 0, rhi = 0;
		int clo = 0, chi = 0;

		int r = 0, c = 0, d = SOUTH;
		REP(x,2) {
			char *p = (x == 0) ? a : b;
			int np = strlen(p);
			FOR(i,1,strlen(p)-1) {
				if ( p[i] == 'W' ) r += pr[d], c += pc[d];
				else if ( p[i] == 'R' ) d = right(d);
				else if ( p[i] == 'L' ) d = left(d);
				if ( i != np - 1 ) {
					rhi = max(r, rhi), rlo = min(r, rlo);
					chi = max(c, chi), clo = min(c, clo);
				}
			}
			r -= pr[d], c -= pc[d];
			d = left(left(d));
		}
		
		vector < vector<char> > m(rhi-rlo+1,chi-clo+1);

		r = -rlo, c = -clo, d = SOUTH;
		REP(x,2) {
			char *p = (x == 0) ? a : b;
			FOR(i,1,strlen(p)-1) {
				if ( p[i] == 'W' ) {
					m[r][c] |= (1 << out[d]);
					r += pr[d], c += pc[d];
				}
				else if ( p[i] == 'R' ) d = right(d);
				else if ( p[i] == 'L' ) d = left(d);
			}
			r -= pr[d], c -= pc[d];
			d = left(left(d));
		}

		printf( "Case #%d:\n", tcase );
		REP(i,m.size()) {
			REP(j,m[i].size()) printf( "%x", m[i][j] );
			putchar( '\n' );
		}
	}
	
	return 0;
}
