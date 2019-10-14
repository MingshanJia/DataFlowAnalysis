#include <cstdio>
#include <memory.h>
#include <iostream>
#include <string>
using namespace std;
string A,B,C,S;

int    visit[255][3];
int	   result[255][3];
int    choice[255][3];
string abc[255][3][3];
bool noZeroAt(const string &x,int i)
{
	if (x[i]==' ') return false;
	if (i==0 || x[i-1]==' ')
	{
		//zero itself.
		if (x.size() == i+1) return false;
		return true;
	}
	return false;
}
bool goodMatch(int a,int b)
{
	if (a<0) a+=10;
	return (a%10)==b;
}
int toInt(char i,int d)
{
	if (i=='?') return d;
	if (i==' ') return 0;
	return i-'0';
}
int solveIt(int i,int stat)
{
	//terminate.
	if (stat<0 || stat>2) return 0;
	if (i>=A.size())
		return stat == 1;
	if (visit[i][stat]) return result[i][stat];
	visit[i][stat] = 1;
	result[i][stat] = 0;
	
	int al = toInt(A[i],0);
	int ah = toInt(A[i],9);

	int bl = toInt(B[i],0);
	int bh = toInt(B[i],9);
	
	int cl = toInt(C[i],0);
	int ch = toInt(C[i],9);

	//printf("%d-%d %d-%d %d-%d\n",al,ah,bl,bh,cl,ch);
	for (int a=al;a<=ah;++a) 
		for (int b=bl;b<=bh;++b)
			for (int c=cl;c<=ch;++c)
			{
				//leading zero prob.
				if (a==0 && noZeroAt(A,i)) continue;
				if (b==0 && noZeroAt(B,i)) continue;
				if (c==0 && noZeroAt(C,i)) continue;				
			
				int k = (S=="+") ? (a+b) : (a-b);
				int ns = -1;
				switch (stat)
				{
					case 1://normal
						if (k>=0 && k<=9)
						{
							if (c==k) ns = 1;//rp = solveIt(i+1,1);
							else if (c==k+1) ns=0;//rp = solveIt(i+1,0);//now Im hungry
							else if (c==k-1) ns=2;//rp = solveIt(i+1,2);//Im fullfilled 
						}
						break;
					case 0://hungry
						if (k>=10)
						{
							if (c==k%10) ns=1;//rp = solveIt(i+1,1);
							else if (c==(k+1)%10) ns=0;//rp = solveIt(i+1,0);
						}
						else if (k==9)	//should carry
						{				
							if (c==0) ns=0;//rp = solveIt(i+1,0);
						}
						break;
					case 2://fullfilled
						if (k<0)
						{
							if (c==k+10) ns=1;//rp = solveIt(i+1,1);
							else if (c==k+9) ns=2;//rp = solveIt(i+1,2);
						}
						else if (k==0) 
						{
							if (c==9) ns=2;//rp = solveIt(i+1,2);
						}
						break;
				}
				//printf("try@%d,%d : %d[%d,%d] vs %d => %d\n",i,stat,k,a,b,c,ns);
				if (solveIt(i+1,ns))
				{
					string D = "";
					string sa = (string() + char(a+'0')) + D + abc[i+1][ns][0];
					string sb = (string() + char(b+'0')) + D + abc[i+1][ns][1];
					string sc = (string() + char(c+'0')) + D + abc[i+1][ns][2];
					if (result[i][stat] == 0 
							|| (abc[i][stat][0]>sa)
							|| (abc[i][stat][0]==sa && abc[i][stat][1]>sb)
							|| (abc[i][stat][0]==sa && abc[i][stat][1]==sb && abc[i][stat][2]>sc))
					{
						result[i][stat]=1;
						abc[i][stat][0] = sa;
						abc[i][stat][1] = sb;
						abc[i][stat][2] = sc;
						choice[i][stat] = ns;
					}
				}
			}
	return result[i][stat] ;
}

string solve(string a,string b,string c,string sgn)
{
	memset(visit,0,sizeof(visit));
	A=a;B=b;C=c;S=sgn;
	int m = max(max(A.size(),B.size()),C.size());
	for (int q=0;q<=m;++q) for (int w=0;w<3;++w) for (int e=0;e<3;++e)
		abc[q][w][e].clear();
	while (A.size()<m) A=" " + A;
	while (B.size()<m) B=" " + B;
	while (C.size()<m) C=" " + C;
	int  z = solveIt(0,1);
	if (z==0) fprintf(stderr,"ffff\n");
	string R[3];
	for (int q=0;q<3;++q)
	{
		R[q] = abc[0][1][q];
		while (R[q].length() > 1 && R[q][0]=='0') R[q] = R[q].substr(1);
	}
	return R[0] + " " + sgn + " " + R[1] + " " + "=" + " " + R[2];
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		string a,b,c,sgn,eql;
		cin >> a >> sgn >> b >> eql >> c;
		printf("Case #%d: %s\n",kase,solve(a,b,c,sgn).c_str());
	}
	return 0;
}

