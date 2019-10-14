#include<bits/stdc++.h>
using namespace std;
long double p[2001][2001];
int m,n,t;
int main()
{
	cin>>t;
	int cas =1;
	while(t--)
	{
		cin>>n>>m;
		p[0][0]=1;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(i==0&&j==0)
				{
					p[i][j]=1;
				}
				else if(i<=j)
				{
					p[i][j]=0;
				}
				else
				{
					p[i][j] = (p[i-1][j])*(n-i+1)/((long double)(n-i+1+m-j)) + (p[i][j-1])*(m-j+1)/((long double)(n-i+m-j+1));
				}
			}
		}
		cout<<"Case #"<<cas<<": "<<fixed<<setprecision(9)<<p[n][m]<<endl;
		cas++;
	}
	return 0;
}