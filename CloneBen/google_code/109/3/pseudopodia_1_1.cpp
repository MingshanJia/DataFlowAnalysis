#include <iostream>
using namespace std;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);

	int tcn;
	cin>>tcn;

	for(int tc=1;tc<=tcn;tc++)
	{
		long long int D, K, N;
		cin>>D>>K>>N;
		K--;

		long long int a=K+1+D, b=K-1+D;

		//N%=(D/2);
		if( K%2 )
		{
			a-=2*N;
			b-=2*N;
		}
		else
		{
			a+=2*N;
			b+=2*N;
		}

		a%=D;
		b%=D;

		a+=D;
		b+=D;

		a%=D;
		b%=D;

		a++;
		b++;

		cout<<"Case #"<<tc<<": "<<a<<' '<<b<<endl;
	}

	return 0;
}