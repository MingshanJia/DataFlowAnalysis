#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	freopen("in.in","rt",stdin);
	freopen("out.out","w",stdout);
	int test;
	int p,a,x;
	long long mx,mn;

	cin >> test;

	for( int t = 0 ; t < test ; t++ )
	{
		vector<int> s;

		cin >> p >> a;

		for( int i = 0 ; i < p ; i++ )
		{
			cin >> x;
			s.push_back(x);
		}

		mx = 1ll<<60;
		mn = 0;

		while( mx > mn ) 
		{
			long long mid = (mx + mn + 1) / 2;
			long long v = 0;

			for( int i = 0; i < s.size(); i++ )
				v += s[i] < mid ? s[i] : mid;

			if( v >= a * mid ) 
				mn = mid;

			else 
				mx = mid-1;
		}

		cout << "Case #" << t+1 << ": " << mx << endl;
	}

	return 0;
}
