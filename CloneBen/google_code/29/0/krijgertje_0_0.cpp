#include <cstdio>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)

typedef long long ll;

int nfrom,nto,ns,nt;
char s[100],t[100],from[100],to[100];
int val[256];


void run(int casenr) {
	scanf("%s%s%s",s,from,to);
	nfrom=strlen(from);
	nto=strlen(to);
	ns=strlen(s);
	memset(val,-1,sizeof(val)); REP(i,nfrom) val[from[i]]=i;
	ll x=0; REP(i,ns) { x=x*nfrom+val[s[i]]; assert(x<=1000000000); }
	nt=0; do { t[nt++]=to[x%nto]; x/=nto; } while(x>0);
	reverse(t,t+nt); t[nt]='\0';
	printf("Case #%d: %s\n",casenr,t);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
}
