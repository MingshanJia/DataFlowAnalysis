#include <iostream>
using namespace std;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);

	int tcn;
	cin>>tcn;

	int n, a[210], chk[210];
	
	for(int tc=1;tc<=tcn;tc++)
	{
		cin>>n;
		for(int i=0;i<2*n;i++)
		{
			cin>>a[i];
			chk[i] = 0;
		}

		cout<<"Case #"<<tc<<": ";

		for(int i=0;i<2*n;i++)
		{
			if( chk[i] ) continue;
			cout<<a[i]<<' ';
			for(int j=i+1;j<2*n;j++)
			{
				if( a[j]*3 == a[i]*4 && !chk[j] )
				{
					chk[j] = 1;
					break;
				}
			}
		}
		cout<<endl;
	}

	return 0;
}