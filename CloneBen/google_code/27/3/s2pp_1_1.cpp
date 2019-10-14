#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	freopen("in.in","rt",stdin);
	freopen("out.out","w",stdout);
	int test,N,T,E,H,P;
	map<int,vector<int> > mp;
	map<int,int> mpc;
	map<int,int> mc;
	bool flag;

	cin >> test;

	for( int t = 0 ; t < test ; t++ )
	{
		flag = false;

		mp.clear();
		mpc.clear();
		mc.clear();

		cin >> N >> T >> E;

		for( int i = 0 ; i < E ; i++ )
		{
			cin >> H >> P;

			if( P )
				mp[H].push_back(P);

			mpc[H] += P;
			mc[H]++;
		}

		cout << "Case #" << t+1 << ":";

		for( int i = 1 ; i <= N ; i++ )
		{
			if( i == T )
				continue;

			if( mc[i] > mpc[i] )
			{
				flag = true;
				break;
			}
		}

		if( flag )
		{
			cout << " IMPOSSIBLE\n";
			continue;
		}

		for( int i = 1; i <= N ; i++ )
		{
			if( i == T )
			{
				cout << " 0";
				continue;
			}

			sort(mp[i].begin(),mp[i].end());
			reverse(mp[i].begin(),mp[i].end());

			int c = mc[i];
			int cnt = 0;
			int j = 0;

			while( c > 0 )
			{
				c -= mp[i][j];
				cnt++;
				j++;
			}

			cout << " " << cnt;
		}

		cout << endl;
	}

	return 0;
}
