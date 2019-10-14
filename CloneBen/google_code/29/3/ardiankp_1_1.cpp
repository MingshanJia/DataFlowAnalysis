#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

map <int, int> wall[10001];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int tc, ntc;
char a[100000], b[100000];
int la, lb;

inline int xx(int x)
{
	int res = 15;
	if (x&1) res &= ~1;
	if (x&2) res &= ~8;
	if (x&4) res &= ~2;
	if (x&8) res &= ~4;
	return res;
}

void proc(int y, int x, int dir, int xdir, int w)
{
	int ny, nx;
	dir += xdir;
	dir %= 4;
	ny = y + dy[dir];
	nx = x + dx[dir];
	//printf("y=%d x=%d dir=%d w=%d\n",y,x,dir,w);
	//if (y == 0 && x == -1) printf("%d\n",wall[0][-1]);
	if (w) 
	{
		wall[y][x] |= 1<<dir;
		if (ny >= 0) wall[ny][nx] |= 1<<((dir+2)%4);
	}
	else
	{
		wall[y][x] &= ~(1<<dir);
		if (ny >= 0) wall[ny][nx] &= ~(1<<((dir+2)%4));
	}
	//if (y == 0 && x == -1) printf("%d\n",wall[0][-1]);
	
}

int minx, maxx, maxy;
int lasty, lastx, lastdir;

void trace(char* s, int len, int y, int x, int dir)
{
	int i;
	for (i=1; i<len; i++)
	{
		minx <?= x;
		maxx >?= x;
		maxy >?= y;
		//printf("%d %c %d %d %d\n",i,s[i],y,x,dir);
		if (s[i] == 'W')
		{
			// kiri buntu, depan bolong
			proc(y,x, dir, 3, 1);
			//proc(y,x, dir, 0, 0);
			y += dy[dir];
			x += dx[dir];
		}
		else if (s[i] == 'L')
		{
			//proc(y,x,dir,3,0);
			dir += 3;
			if (dir >= 4) dir -= 4;
			y += dy[dir];
			x += dx[dir];
			i++;
		}
		else if (s[i] == 'R' && s[i+1] == 'R')
		{
			proc(y,x,dir,3,1);
			proc(y,x,dir,0,1);
			proc(y,x,dir,1,1);
			//proc(y,x,dir,2,0);
			dir+=2;
			if (dir >= 4) dir -= 4;
			y += dy[dir];
			x += dx[dir];			
			i+=2;
		}
		else if (s[i] == 'R')
		{
			proc(y,x,dir,3,1);
			proc(y,x,dir,0,1);
			//proc(y,x,dir,1,0);
			dir ++;
			if (dir >= 4) dir -= 4;
			y += dy[dir];
			x += dx[dir];			
			i++;
		}
	}
	
	lasty = y;
	lastx = x;
	lastdir = dir;
}

int main()
{
	scanf("%d",&ntc);
	int i, j;
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%s %s",a,b);
		la = strlen(a); lb = strlen(b);	
		
		for (i=0; i<=10000; i++) wall[i].clear();
		// assume start from north
		minx = 0, maxx = 0, maxy = 0;
		trace(a,la, 0, 0, 2); 
		lastdir += 2;
		lastdir %= 4;
		//printf("%d %d\n",lasty,lastx);
		
		lasty += dy[lastdir];
		lastx += dx[lastdir];
		//printf("%d %d %d\n",lasty,lastx,lastdir);
		trace(b,lb,lasty,lastx,lastdir);
		
		printf("Case #%d:\n",tc);
		for (i=0; i<=maxy; i++)
		{
			for (j=minx; j<=maxx; j++) printf("%x",xx(wall[i][j]));
			//for (j=minx; j<=maxx; j++) printf("%x",wall[i][j]);
			printf("\n");
		}
	}
}