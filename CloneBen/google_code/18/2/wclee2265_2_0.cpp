#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

#define K 55
#define N 25
#define M 25

FILE *in=fopen("C-small-attempt0.in","rt");
FILE *out=fopen("output.txt","wt");

int n,ans,rcnt[K],m,num[K][N][M],room[K][205],rnum,l,d_y[4]={0,1,0,-1},d_x[4]={1,0,-1,0},check[20005];
char map[K][N][M];
vector<int> r[20005];

void bfs(int y, int x,char map[][M] ,int num[][M])
{
	int i,q[500][2],rear=1,front=0;
	q[rear][0]=y;
	q[rear][1]=x;
	num[y][x]=rnum;
	do{
		front++;
		for(i=0;i<4;i++){
			y=q[front][0]+d_y[i];
			x=q[front][1]+d_x[i];
			if(y>0 && y<=n && x>0 && x<=m && map[y][x]=='.' && num[y][x]==0){
				rear++;
				q[rear][0]=y;
				q[rear][1]=x;
				num[y][x]=rnum;
			}
		}
	}while(rear!=front);
}

void get_num(char map[][M], int num[][M], int room[], int &rcnt)
{
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(map[i][j]=='.' && num[i][j]==0){
				rnum++;
				bfs(i,j,map,num);
				room[++rcnt]=rnum;
			}
		}
	}
}

void input()
{
	int i,j,k;
	memset(num,0,sizeof(num));
	rnum=0;
	fscanf(in,"%d %d %d",&n,&m,&l);
	for(k=1;k<=l;k++){
		for(i=1;i<=n;i++) fscanf(in," %s",&map[k][i][1]);
		get_num(map[k],num[k],room[k],rcnt[k]);		
	}

	for(i=0;i<=rnum*2+1;i++) r[i].clear();

	for(i=1;i<=rnum;i++){
		r[0].push_back(i);
		r[rnum+i].push_back(rnum*2+1);
	}

	for(k=1;k<=l;k++){
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++){
				if(map[k][i][j]=='.' && map[k-1][i][j]=='.'){
					r[num[k][i][j]].push_back(rnum+num[k-1][i][j]);
					r[num[k-1][i][j]].push_back(rnum+num[k][i][j]);
				}
			}
		}
	}
}

bool dfs(int x)
{
	int i,k,y;
	if(x==rnum*2+1) return true;
	check[x]=ans+1;
	k=r[x].size();
	for(i=0;i<k;i++){
		y=r[x][i];
		if(check[y]!=ans+1 && dfs(y))
		{
			r[x][i]=r[x][r[x].size()-1];
			r[x].pop_back();
			r[y].push_back(x);
			return true;
		}
	}
	return false;
}

void process()
{
	ans=0;
	memset(check,0,sizeof(check));
	while(dfs(0)) ans++;
}

int main()
{
	int t,i;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++){
		input();
		process();
		fprintf(out,"Case #%d: %d\n",i,rnum-ans/2);
	}
	fclose(in);
	fclose(out);
	return 0;
}