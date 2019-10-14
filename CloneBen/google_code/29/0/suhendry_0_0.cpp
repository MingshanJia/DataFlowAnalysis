#include <cstdio>
#include <string>
#include <stack>
using namespace std;

#define REP(i,n) for(int (i)=0,_n=(n);(i)<_n;(i)++)
#define FOR(i,a,b) for(int (i)=(a),_n=(b);(i)<=_n;(i)++)
#define FORD(i,a,b) for(int (i)=(a),_n=(b);(i)>=_n;(i)--)

typedef long long LL;

char a[1000];
char s[1000];
char t[1000];

int main()
{
	int ncase;
	scanf( "%d", &ncase );

	FOR(tcase,1,ncase) {
		scanf( "%s %s %s", a, s, t );
		int ns = strlen(s);
		int nt = strlen(t);
		char ms[256] = { 0 };
		REP(i,ns) ms[s[i]] = i;

		LL dec = 0, p = 1;
		FORD(i,strlen(a)-1,0) {
			dec += ms[a[i]] * p;
			p *= ns;
		}
		
		stack <char> ans;
		do {
			ans.push(t[dec % nt]);
			dec /= nt;
		} while ( dec != 0 );

		printf( "Case #%d: ", tcase );
		while ( !ans.empty() ) putchar( ans.top() ), ans.pop();
		putchar( '\n' );

	}
	
	return 0;
}
