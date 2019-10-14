#include <bits/stdc++.h>
using namespace std;

long long int x[400000],y[400000],z[400000],l[400000],r[400000],k[400000],a[6];
map <long long int, long long int >m;
map <long long int, long long int >::iterator it,it1;

vector <pair <long long int, long long int > >v;
vector < long long int > stans;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-largeoutput","w",stdout);
	long long int t,n,q,val,val1,val2,flag,ans,finans,index1,i,j;
	scanf("%lld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lld %lld",&n,&q);
		m.clear();
		v.clear();
		stans.clear();
		for(j=0;j<6;j++)
			scanf("%lld",&a[j]);
		x[0]=a[0];
		x[1]=a[1];
		for(j=2;j<400000;j++)
		{
			x[j]=(a[2]*x[j-1]+a[3]*x[j-2]+a[4])%a[5];
		}
		for(j=0;j<6;j++)
			scanf("%lld",&a[j]);
		y[0]=a[0];
		y[1]=a[1];
		for(j=2;j<400000;j++)
		{
			y[j]=(a[2]*y[j-1]+a[3]*y[j-2]+a[4])%a[5];
		}
		for(j=0;j<6;j++)
			scanf("%lld",&a[j]);
		z[0]=a[0];
		z[1]=a[1];
		for(j=2;j<400000;j++)
		{
			z[j]=(a[2]*z[j-1]+a[3]*z[j-2]+a[4])%a[5];
		}
		for(j=0;j<400000;j++)
		{
			l[j]=min(x[j],y[j])+1;
			r[j]=max(x[j],y[j])+1;
			k[j]=z[j]+1;
		}
		for(j=0;j<n;j++)
		{
			m[l[j]-1]--;
			m[r[j]]++;
		}
		/*for(j=0;j<n;j++)
			printf("%lld ",x[j]);
		printf("\n");
		for(j=0;j<n;j++)
			printf("%lld ",y[j]);
		printf("\n");
		for(j=0;j<q;j++)
			printf("%lld ",z[j]);
		printf("\n\n\n\n\n");
		for(j=0;j<n;j++)
			printf("%lld ",l[j]);
		printf("\n");
		for(j=0;j<n;j++)
			printf("%lld ",r[j]);
		printf("\n");
		for(j=0;j<q;j++)
			printf("%lld ",k[j]);
		printf("\n\n\n\n\n");*/
		finans=0;
		for(j=0;j<q;j++)
		{
			v.push_back(make_pair(k[j],j));
		}
		sort(v.begin(),v.end());
		for(j=0;j<q;j++)
			stans.push_back(0);
		index1=0;
		it=m.end();
		it--;
		val=0;
		val1=(*it).first+1;
		val2=0;
		ans=0;
		flag=1;
		while(1)
		{
			if(index1>=q)
				break;
			//printf("%lld %lld %lld %lld %lld %lld\n",val,val1,val2,ans,(*it).first,(*it).second);
			if(val+(val1-(*it).first-1)*val2>=v[index1].first)
			{
				while(index1<q && val+(val1-(*it).first-1)*val2>=v[index1].first)
				{
					ans=val1-(v[index1].first-val)/val2;
					if((v[index1].first-val)%val2!=0)
						ans--;
					stans[index1]=ans;
					index1++;
				}
			}
			if(index1>=q)
				break;
			val+=(val1-(*it).first-1)*val2;
			val2+=(*it).second;
			val+=val2;
			val1=(*it).first;
			if(val>=v[index1].first)
			{
				while(index1<q && val>=v[index1].first)
				{
					stans[index1]=(*it).first;
					index1++;
				}
			}
			//printf("%lld %lld %lld %lld\n",val,val1,val2,ans);
			if(it==m.begin())
			break;
			it--;
		}
		finans=0;
		//for(j=0;j<q;j++)
		//	printf("%lld %lld %lld\n",v[j].first,v[j].second,stans[j]);
		for(j=0;j<q;j++)
			finans+=stans[j]*(v[j].second+1);
		printf("Case #%lld: %lld\n",i,finans);
	}
	return 0;
}
