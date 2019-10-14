#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int dx[]={0,1,1,1,0,-1,-1,-1};
const int dy[]={-1,-1,0,1,1,1,0,-1};
int N,T,K;
char a[55][55];

bool check_red()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int k=0;k<8;k++)
			{
				bool flag=false;
				for(int l=0;l<K;l++)
					if(i+dx[k]*l<N&&i+dx[k]*l>=0&&j+dy[k]*l>=0&&j+dy[k]*l<N)
						if(a[i+dx[k]*l][j+dy[k]*l]!='R')
						{
							flag=true;
							break;
						}
						else;
					else
						flag=true;
				if(!flag)
					return true;
			}
	return false;
}

bool check_blue()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int k=0;k<8;k++)
			{
				bool flag=false;
				for(int l=0;l<K;l++)
					if(i+dx[k]*l<N&&i+dx[k]*l>=0&&j+dy[k]*l>=0&&j+dy[k]*l<N)
						if(a[i+dx[k]*l][j+dy[k]*l]!='B')
						{
							flag=true;
							break;
						}
						else
							;
					else
						flag=true;
				if(!flag)
					return true;
			}
	return false;
}

pair<bool,bool> check()
{
	return make_pair(check_red(),check_blue());
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A_large.out","w",stdout);
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		scanf("%d%d",&N,&K);
		printf("Case #%d: ",test);
		for(int i=N-1;i>=0;i--)
			scanf("%s",&a[i]);
		for(int i=0;i<N;i++)
		{
			vector<char> P;
			P.clear();
			for(int j=0;j<N;j++)
				if(a[i][j]!='.')
					P.push_back(a[i][j]);
			for(int j=N-1;j>=0;j--)
			{
				if(P.size())
				{
					a[i][j]=P.back();
					P.pop_back();
				}
				else
					a[i][j]='.';
			}
		}
		pair<bool,bool> ret=check();
		if(ret.first)
			if(ret.second)
				puts("Both");
			else
				puts("Red");
		else
			if(ret.second)
				puts("Blue");
			else
				puts("Neither");
	}
	return 0;
}

