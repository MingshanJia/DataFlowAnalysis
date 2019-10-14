#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,p=1;
cin>>t;
	while(t--)
	{
		long long int k,n,A[200],B[200],j=0,ans = 0;
		cin>>k;
		for(int i=0;i<k;i++)
			cin>>A[i];
		sort(A,A+k);
		for(int i=0;i<200;i++)
		{
			B[i]=j;
			if ((i+1)%2==0)
				j++;
		}
		for(int i=0;i<k;i++)
		{
			ans = ans + ((A[i]-B[i]) * (A[i]-B[i]));
		}
		cout<<"Case #"<<p<<": "<<ans<<endl;
		p++;
	}
	
}