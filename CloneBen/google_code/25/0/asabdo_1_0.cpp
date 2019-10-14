#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;
struct dis_joint_set{

	vector<int> p,r;
	int cmp;
	dis_joint_set(int N)
	{
		p.resize(N+1);
		r.resize(N+1);
		clear();
		cmp = N;
		cerr<<"djs of size "<<N<<" created\n";
	}
	void clear()
	{
		for(int i=0;i<(int)p.size();i++)
		{
			p[i] = i;
			r[i] = 0;
		}
	}
	int find(int x)
	{
		if( x == p[x] ) return x;
		return p[x] = find( p[x] );
	}

	void merg(int px,int py)
	{
		px = find(px);
		py = find(py);
		if( px == py ) return ;
		cmp--;
		if( r[px] == r[py] )
		{
			r[px]++;
			p[py] = px;
		}
		else if( r[px] > r[py] )
			p[py] = px;
		else 
			p[px] = py;             
	}

};

int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int a[10000];
	int TC,n,m,x,y;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;tc++)
	{
		memset(a,0,sizeof(a));
		scanf("%d %d",&n,&m);
		dis_joint_set djs(n);
		int ans = 0,i,j;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			djs.merg(x,y);
			a[x]++;
			a[y]++;
		}

		//int ans = 0;
		for( i=0;i<n;i++)
			if(a[i]==0)
				djs.cmp--;
		/*else if(a[i]%2)
		v.push_back(i);*/

		while(djs.cmp != 1)
		{
			for(i=0;i<n;i++)
				if(a[i]%2)
				{
					
					for( j=i+1;j<n;j++)
						if(a[j]%2 && djs.find(i) != djs.find(j)) 
						{
							a[i]++;
							a[j]++;
							ans++;
							djs.merg(i,j);
							break;
						}
					if(j==n)
					for(j=0;j<n;j++)
						if(a[j] && djs.find(j) != djs.find(i))
						{
							a[i]++;
							a[j]++;
							ans++;
							djs.merg(i,j);
							break;
						}
						break;
				}
				if(i==n)
				{
					for(i=0;i<i<n;i++)
						if(a[i]) break;
					for(j=i+1;j<n;j++)
						if(a[j] && djs.find(j) != djs.find(i))
						{
							a[i]++;
							a[j]++;
							ans++;
							djs.merg(i,j);
							break;
						}
				}
		}
		int c=0;
		for(i=0;i<n;i++)
			if(a[i]%2) c++;
		ans += (c+1)/2;

		printf("Case #%d: %d\n",tc,ans);
		
	}
	return 0;
}