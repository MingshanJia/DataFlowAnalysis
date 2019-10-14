#include <cstdio>
#include <algorithm>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

const int DOWN=0,LEFT=1,UP=2,RIGHT=3;
const int DX[]={+1,0,-1,0},DY[]={0,-1,0,+1};

int ns,nt;
char s[10001],t[10001];

void run(int casenr) {
	scanf("%s%s",s,t);
	ns=strlen(s),nt=strlen(t);
	int lx=0,ly=0,hx=0,hy=0;
	{
		int x=0,y=0,d=DOWN;
		FOR(i,1,ns-1) if(s[i]=='W') x+=DX[d],y+=DY[d],lx<?=x,ly<?=y,hx>?=x,hy>?=y; else if(s[i]=='L') d=(d+3)%4; else if(s[i]=='R') d=(d+1)%4; else assert(false);
		d=(d+2)%4;
		FOR(i,1,nt-1) if(t[i]=='W') x+=DX[d],y+=DY[d],lx<?=x,ly<?=y,hx>?=x,hy>?=y; else if(t[i]=='L') d=(d+3)%4; else if(t[i]=='R') d=(d+1)%4; else assert(false);
	}
	VVVI can(4,VVI(hx-lx+1,VI(hy-ly+1,-1)));
	{
		int x=-lx,y=-ly,d=DOWN;
		for(int i=1;i<ns;) {
			assert(x>=0); assert(x<=hx-lx);
			assert(y>=0); assert(y<=hy-ly);
			assert(can[(d+2)%4][x][y]!=0);
			can[(d+2)%4][x][y]=1;
			if(s[i]=='L') {
				assert(can[(d+3)%4][x][y]!=0);
				can[(d+3)%4][x][y]=1;
				d=(d+3)%4; i++;
				assert(s[i]=='W');
				x+=DX[d],y+=DY[d]; i++;
			} else {
				assert(can[(d+3)%4][x][y]!=1);
				can[(d+3)%4][x][y]=0;
				if(s[i]=='W') {
					assert(can[d][x][y]!=0);
					can[d][x][y]=1;
					x+=DX[d],y+=DY[d]; i++;
				} else {
					assert(can[d][x][y]!=1);
					can[d][x][y]=0;
					assert(s[i++]=='R');
					d=(d+1)%4;
					if(s[i]=='W') {
						assert(can[d][x][y]!=0);
						can[d][x][y]=1;
						x+=DX[d],y+=DY[d]; i++;
					} else {
						assert(can[d][x][y]!=1);
						can[d][x][y]=0;
						assert(s[i++]=='R');
						d=(d+1)%4;
						assert(s[i]=='W');
						assert(can[d][x][y]!=0);
						can[d][x][y]=1;
						x+=DX[d],y+=DY[d]; i++;
					}
				}
			}
		}
		x-=DX[d],y-=DY[d]; d=(d+2)%4;
		for(int i=1;i<nt;) {
			assert(x>=0); assert(x<=hx-lx);
			assert(y>=0); assert(y<=hy-ly);
			assert(can[(d+2)%4][x][y]!=0);
			can[(d+2)%4][x][y]=1;
			if(t[i]=='L') {
				assert(can[(d+3)%4][x][y]!=0);
				can[(d+3)%4][x][y]=1;
				d=(d+3)%4; i++;
				assert(t[i]=='W');
				x+=DX[d],y+=DY[d]; i++;
			} else {
				assert(can[(d+3)%4][x][y]!=1);
				can[(d+3)%4][x][y]=0;
				if(t[i]=='W') {
					assert(can[d][x][y]!=0);
					can[d][x][y]=1;
					x+=DX[d],y+=DY[d]; i++;
				} else {
					assert(can[d][x][y]!=1);
					can[d][x][y]=0;
					assert(t[i++]=='R');
					d=(d+1)%4;
					if(t[i]=='W') {
						assert(can[d][x][y]!=0);
						can[d][x][y]=1;
						x+=DX[d],y+=DY[d]; i++;
					} else {
						assert(can[d][x][y]!=1);
						can[d][x][y]=0;
						assert(t[i++]=='R');
						d=(d+1)%4;
						assert(t[i]=='W');
						assert(can[d][x][y]!=0);
						can[d][x][y]=1;
						x+=DX[d],y+=DY[d]; i++;
					}
				}
			}
		}
		x-=DX[d],y-=DY[d]; d=(d+2)%4;
		assert(x==-lx&&y==-ly&&d==DOWN);
//		REP(k,4) { REPE(i,hx-lx) { REPE(j,hy-ly) printf("%c",can[k][i][j]==-1?'?':can[k][i][j]?'V':'.'); puts(""); } puts(""); }
	}
	REP(k,4) REPE(x,hx-lx) REPE(y,hy-ly) assert(can[k][x][y]!=-1);
	printf("Case #%d:\n",casenr);
	char dig[17]="0123456789abcdef";
	
	REPE(x,hx-lx) {
		REPE(y,hy-ly) printf("%c",dig[1*can[UP][x][y]+2*can[DOWN][x][y]+4*can[LEFT][x][y]+8*can[RIGHT][x][y]]);
		puts("");
	}
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
}
