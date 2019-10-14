#include <stdio.h>

#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))

FILE *in=fopen("A-small-attempt0.in","rt");
FILE *out=fopen("output.txt","wt");

int n,a[2][4],p[5][5],b[15],ans;
bool check[15];

void input()
{
	int i,j;
	fscanf(in,"%d",&n);
	for(i=0;i<2;i++){
		for(j=1;j<=3;j++) fscanf(in,"%d",&a[i][j]);
	}
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			fscanf(in,"%d",&p[i][j]);
		}
	}
}

void go_check()
{
	int i,x,y,c[2][4],j,tmp=0,cnt;
	for(i=0;i<2;i++){
		for(j=1;j<=3;j++) c[i][j]=a[i][j];
	}
	for(i=1;i<=9;i++)
	{
		x=b[i]/3+1;
		y=b[i]%3+1;
		cnt=Min(c[0][x],c[1][y]);
		tmp+=cnt*p[x][y];
		c[0][x]-=cnt;
		c[1][y]-=cnt;
	}
	if(ans<tmp) ans=tmp;
}

void process(int lev)
{
	int i;
	if(lev==9){
		go_check();
		return;
	}
	for(i=0;i<9;i++){
		if(!check[i]){
			check[i]=true;
			b[lev+1]=i;
			process(lev+1);
			check[i]=false;
		}
	}
}

int main()
{
	int t,i;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++){
		ans=-1000000000;
		input();
		process(0);
		fprintf(out,"Case #%d: %d\n",i,ans);
	}
	fclose(in);
	fclose(out);
	return 0;
}