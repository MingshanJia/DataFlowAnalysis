#include <iostream>
#define MOD 1000000007
using namespace std;

long long int a[510][2];

int main()
{
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C-small-1-attempt0.out","w",stdout);

	int tcn;
	cin>>tcn;

	long long int C, V;
	int n;
	for(int tc=1;tc<=tcn;tc++)
	{
		cin>>C>>V>>n;
		a[1][0] = C;
		a[1][1] = V;

		for(int i=2;i<=n;i++)
		{
			a[i][0] = (a[i-1][1]*C)%MOD;
			a[i][1] = ((a[i-1][0]+a[i-1][1])*V)%MOD;
		}

		cout<<"Case #"<<tc<<": "<<a[n][1]<<endl;
	}

	return 0;
}