#include <cstdio>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int (i)=0,_n=(n);(i)<_n;(i)++)
#define FOR(i,a,b) for(int (i)=(a),_n=(b);(i)<=_n;(i)++)
#define FORD(i,a,b) for(int (i)=(a),_n=(b);(i)>=_n;(i)--)

typedef long long LL;
LL limit = (LL)1 << 32;


LL findf(LL d, LL b) {
	LL ret = 0, p = 1;
	FOR(i,1,min(b,d)) {
		p = p * (d - i + 1) / i;
		ret += p;
		if ( ret >= limit || p >= limit ) { ret = limit; break; }
	}
	return ret;
}

int main()
{
	int ncase;
	scanf( "%d", &ncase );

	FOR(tcase,1,ncase) {
		LL f, d, b;
		scanf( "%lld %lld %lld", &f, &d, &b );

		LL L, R;
		LL fmax = findf(d,b);
		LL dmin = f, bmin = f;

		L = 1, R = f;
		while ( L <= R ) {
			LL mid = (L + R) / 2;
			if ( findf(mid,b) >= f ) dmin = min(dmin, mid), R = mid - 1;
			else L = mid + 1;
		}

		L = 1, R = f;
		while ( L <= R ) {
			LL mid = (L + R) / 2;
			if ( findf(d,mid) >= f ) bmin = min(bmin, mid), R = mid - 1;
			else L = mid + 1;
		}

		printf( "Case #%d:", tcase );
		printf( " %lld %lld %lld\n", fmax == limit ? -1 : fmax, dmin, bmin );
	}
	
	return 0;
}
