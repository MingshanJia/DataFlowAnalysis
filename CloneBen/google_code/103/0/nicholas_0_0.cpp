#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

int f[1024];
vector<int> A;
int main()
{
	int T,P,K,L;
	freopen("in.txt","r", stdin);
	freopen("out.txt", "w", stdout);
	cin>>T;
	for (int ctr = 1; ctr <= T; ctr++)
	{
		A.clear();
		cin>>P>>K>>L;
		for (int i = 0; i < L; i++)
		{
			int x;
			cin>>x;
			A.push_back( x );
		}
		
		sort(A.begin(), A.end());

		memset(f, 0, sizeof(f));
		int g = 0;

		long long ret = 0;

		for (int i = L-1; i >= 0; i--)
		{
			if (f[g] < P)
			{
				f[g]++;
				ret += (long long)(f[g]) * (long long)(A[i]);
				//cout<<ret<<endl;
				g++;
				if (g == K) g = 0;
			}
			else
				g = (g+1) % K;
			
		}

		cout<<"Case #"<<ctr<<": "<<ret<<endl;
	}
	return 0;
}

