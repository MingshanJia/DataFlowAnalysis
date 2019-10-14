#include<iostream>
#include<map>

using namespace std;

int main()
{
	freopen("in.in","rt",stdin);
	freopen("out.out","w",stdout);
	int n,g,c;

	cin >> n;

	for( int t = 0 ; t < n ; t++ )
	{
		map<int,int> mp;

		cin >> g;

		for( int i = 0 ; i < g ; i++ )
		{
			cin >> c;
			mp[c]++;
		}

		for(map<int,int>::iterator itr = mp.begin() ; itr != mp.end() ; itr++ )
		{
			if( itr->second != 2 )
			{
				c = itr->first;
				break;
			}
		}

		cout << "Case #" << t+1 << ": " << c << endl;
	}
}
