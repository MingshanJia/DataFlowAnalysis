#include<bits/stdc++.h>
#define M 1000000007
#define maxl 10000
using namespace std;
int segtree[40000];
int arr[10000];
int  infty = 1000000000;
int tmp;
int build(int i,int s, int e)
{
	if(s==e)
	{
		segtree[i] = arr[s];
		return segtree[i];
	}
	int mid = (s+e)/2;
	segtree[i] = min(build(2*i+1,s,mid),build(2*i+2,mid+1,e));
	return segtree[i];
}
int findmin(int i,int s, int e,int sq,int eq)
{
	//cout<<i<<" "<<s<<" "<<e<<" "<<sq<<" "<<eq<<endl;
	if(sq<0)
		sq=0;
	if(eq<0)
		return infty;

	if(s>eq || e<sq)
		return infty;
	if(s==e)
		return segtree[i];
	if(s>=sq&&e<=eq)
		return segtree[i];
	int mid = (s+e)/2;
	return min(findmin(2*i+1,s,mid,sq,eq),findmin(2*i+2,mid+1,e,sq,eq));
}
int n,m,l,t;
int main()
{
	cin>>t;
	int a[1000],b[1000],p[1000];
	int cas =1;
	while(t--)
	{
		cin>>n>>m>>l;

		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i]>>p[i];
		}
		arr[0]=0;
		for(int i=1;i<=l;i++)
		{
			arr[i]=infty;
		}
		for(int i=0;i<n;i++)
		{
			build(0,0,l);
			for(int j=0;j<=l;j++)
			{
				//cout<<i<<" "<<j<<" "<<j-b[i]<<" "<<j-a[i]<<" "<<findmin(0,0,l,j-b[i],j-a[i])+p[i]<<endl;
				arr[j] = min(arr[j],findmin(0,0,l,j-b[i],j-a[i])+p[i]);
			}
		}
		if(arr[l]>m)
			cout<<"Case #"<<cas<<": "<<"IMPOSSIBLE"<<endl;
		else
			cout<<"Case #"<<cas<<": "<<arr[l]<<endl;
		cas++;
	}
	return 0;
}