#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
	freopen("in.in","rt",stdin);
	freopen("out.out","w",stdout);
	int test,n,m,x,y,z;
	char c;

	cin >> test;

	for( int t = 0 ; t < test ; t++ )
	{
		map<int,vector<int> > truth,liar;
		map<int,vector<pair<int,int> > > same,dif;
		vector<int> from;

		cin >> n >> m;

		vector<vector<int> >res;

		for( int i = 0 ; i < m ; i++ )
		{
			cin >> x >> c >> y;

			if( c == 'S' || c == 'D' )
				cin >> z;

			switch( c )
			{
			case 'T':
				truth[x].push_back(y);
				break;
				
			case 'L':
				liar[x].push_back(y);
				break;

			case 'S':
				same[x].push_back(make_pair(y,z));
				break;

			case 'D':
				dif[x].push_back(make_pair(y,z));
				break;
			}
		}

		for( int i = 0 ; i < (1<<n) ; i++ )
		{
			vector<int> o(n+1,0);

			for( int j = 0 ; j < n ; j++ )
			{
				if( (i>>j)&1 )
					o[j+1] = 1;

				else
					o[j+1] = 2;
			}

			bool flag = false;

			for( int j = 0 ; j < n ; j++ )
			{
				bool p = (1<<j)&i;

				for( int k = 0 ; k < truth[j+1].size() ; k++ )
				{
					if( p )
					{
						if( o[truth[j+1][k]] == 2 )
						{
							flag = true;
							break;
						}
						continue;
					}

					if( o[truth[j+1][k]] == 1 )
					{
						flag = true;
						break;
					}
				}

				for( int k = 0 ; k < liar[j+1].size() ; k++ )
				{
					if( p )
					{
						if( o[liar[j+1][k]] == 1 )
						{
							flag = true;
							break;
						}
						continue;
					}

					if(o[liar[j+1][k]] == 2 )
					{
						flag = true;
						break;
					}
				}

				for( int k = 0 ; k < same[j+1].size() ; k++ )
				{
					if( p && o[same[j+1][k].first] != o[same[j+1][k].second] )
					{
						flag = true;
						break;
					}

					if( !p && o[same[j+1][k].first] == o[same[j+1][k].second] )
					{
						flag = true;
						break;
					}
				}

				for( int k = 0 ; k < dif[j+1].size() ; k++ )
				{
					if( p && o[dif[j+1][k].first] == o[dif[j+1][k].second] )
					{
						flag = true;
						break;
					}

					if( !p && o[dif[j+1][k].first] != o[dif[j+1][k].second] )
					{
						flag = true;
						break;
					}
				}

				
			}
			if( flag )
					continue;

				res.push_back(o);
		}

		vector<int> fin(n+1,0);

		for( int i = 0 ; i < res.size() ; i++ )
		{
			for( int j = 1 ; j < n+1 ; j++ )
			{
				fin[j] |= res[i][j];
			}
		}

		cout << "Case #" << t+1 << ":";

		for( int i = 1 ; i < n+1 ; i++ )
		{
			switch( fin[i] )
			{
			case 0:
			case 3:
				cout << " -";
				break;

			case 1:
				cout << " T";
				break;
			
			case 2:
				cout << " L";
			}
		}

		cout << endl;
	}

	return 0;
}
