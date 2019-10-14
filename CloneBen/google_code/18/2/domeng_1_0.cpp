#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int U,N,A,B,AX,BX,AY,BY;
string Data[55];
int Next[35][6];

int parse(const string& str)
{
	if (str == "Do") return 1;
	if (str == "Gae") return 2;
	if (str == "Gul") return 3;
	if (str == "Yut") return 4;
	if (str == "Mo") return 5;
	fprintf(stderr,"FYEAH!\n");
}

int canMeet(int a,int b)
{
	if (a>=30 || b>=30) return 0;
	if (a==b) return 1;
	return 0;
}

int isSame(int a,int b)
{
	if (a==29) a=0;
	if (b==29) b=0;//reduce
	if (a==b) return 1;
	if (a>=30 && b>=30) //µÑ´Ù not exist case
		return 1;
	return 0;
}

namespace B1
{
	//	  n*who's turn? * ax * bx
	int dp[50][2][30][30];
	int vs[50][2][30][30];
	int solve(int n,int t,int ax,int bx)
	{
		if (n>=N) 
		{
			return (AX==ax || isSame(AX,ax))
				&& (BX==bx || isSame(BX,bx));
		}
		
		int len = parse(Data[n]);
		int ax2 = ax, bx2 = bx, nextTurn = !t;
		if (t==0) ax2 = Next[ax][len];
		else if (t==1) bx2 = Next[bx][len];

		//eat?
		if (canMeet(ax2,bx2))
		{
			if (t==0) bx2 = 31;
			else      ax2 = 31;
			nextTurn = t;
		}
		if (len>=4) nextTurn = t;

		return solve(n+1,nextTurn,ax2,bx2);
	}
};
int main()
{
	int G=29;
	for (int q=0;q<G;++q)
		for (int w=1;w<=5;++w)
		{
			if(q+w<20) Next[q][w]=q+w;
			else if (q+w==20) Next[q][w]=29;
			else Next[q][w]=30;
		}

	Next[5][1]=20;
	Next[5][2]=21;
	Next[5][3]=22;
	Next[5][4]=23;
	Next[5][5]=24;

	Next[20][1]=21;
	Next[20][2]=22;
	Next[20][3]=23;
	Next[20][4]=24;
	Next[20][5]=15;

	Next[21][1]=22;
	Next[21][2]=23;
	Next[21][3]=24;
	Next[21][4]=15;
	Next[21][5]=16;

	Next[22][1]=27;
	Next[22][2]=28;
	Next[22][3]=29;
	Next[22][4]=30;//OUT OF PLANE
	Next[22][5]=30;

	Next[23][1]=24;
	Next[23][2]=15;
	Next[23][3]=16;
	Next[23][4]=17;
	Next[23][5]=18;

	Next[24][1]=15;
	Next[24][2]=16;
	Next[24][3]=17;
	Next[24][4]=18;
	Next[24][5]=19;

	Next[10][1]=25;
	Next[10][2]=26;
	Next[10][3]=22;
	Next[10][4]=27;
	Next[10][5]=28;

	Next[25][1]=26;
	Next[25][2]=22;
	Next[25][3]=27;
	Next[25][4]=28;
	Next[25][5]=29;

	Next[26][1]=22;
	Next[26][2]=27;
	Next[26][3]=28;
	Next[26][4]=29;
	Next[26][5]=30;

	Next[27][1]=28;
	Next[27][2]=29;
	Next[27][3]=30;
	Next[27][4]=30;
	Next[27][5]=30;

	Next[28][1]=29;
	Next[28][2]=30;
	Next[28][3]=30;
	Next[28][4]=30;
	Next[28][5]=30;

	Next[29][1]=30;
	Next[29][2]=30;
	Next[29][3]=30;
	Next[29][4]=30;
	Next[29][5]=30;

	Next[30][1]=-1;
	Next[30][2]=-1;
	Next[30][3]=-1;
	Next[30][4]=-1;
	Next[30][5]=-1;

	Next[31][1]=1;
	Next[31][2]=2;
	Next[31][3]=3;
	Next[31][4]=4;
	Next[31][5]=5;

	int T;
	cin  >> T;
	//scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		cin>> U >> N >> A >> B;
		for (int q=0;q<N;++q) cin >> Data[q];
		AX=AY=BX=BY=31;
		if (A==1) cin >> AX;
		if (A==2) cin >> AY;
		if (B==1) cin >> BX;
		if (B==2) cin >> BY;
		if (U==1)
		{
			int res = B1::solve(0,0,31,31);
			printf("Case #%d: %s\n",kase,res?"YES":"NO");
		}
		else
		{
			fprintf(stderr,"FYEAH!\n");
			printf("Case #%d: %s\n",kase,"¸ô¶ó");
		}

	}
	
	return 0;
}