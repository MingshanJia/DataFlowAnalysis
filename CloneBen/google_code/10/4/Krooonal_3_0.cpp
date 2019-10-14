#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0
#define all(C) (C).begin() , (C).end()
#define tr(C , it) for(typeof((C).begin()) it = (C).begin() ; it != (C).end() ; it++)
#define present(C , key) ((C).find(key) != (C).end())
#define cpresent(C , key) (find(all(C) , key) != (C).end())
#define sz(a) int((a).size())
#define pb push_back
#define MOD 1000000007


typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<long long , long long> PI;

int main()
{
	int _T;
	scanf("%d" , &_T);
	
	int N , i , cnt , flag , temp;
	long long M , x , y , z ;
	//int tiles[21]; 
	int visited[21];
	PI cdim;
	vector<int> tiles;

	for(int _a = 1 ; _a <= _T ; _a++)
	{
		printf("Case #%d: " , _a);
		scanf("%d %lld" , &N , &M);
		memset(visited , 0 , sizeof(visited));
		tiles.clear();
		for(i=0 ; i<N ; i++)
		{
			scanf("%d" , &temp);
			tiles.pb(temp);
		}
		sort(tiles.rbegin() , tiles.rend());
		queue<PI> Q;
		cnt = 0;
		do
		{
			cnt++;
			Q.push(PI(M , M));
			while(!Q.empty())
			{
				cdim = Q.front();
				Q.pop();
				
				for(i=0 ; i<N ; i++)
				{
					if(visited[i])
						continue;
					x = ((long long)1 << tiles[i]);	
					if(x <= cdim.first && x <= cdim.second)
					{
						visited[i] = 1;
						y = (cdim.first - x);
						z = (cdim.second - x);
						if(y != 0 )
						{
							Q.push(PI(x , y));
						}
						if(z != 0 )
						{
							Q.push(PI(x , z));
						}
						if(y != 0 && z != 0)
						{
							Q.push(PI(y , z));
						}
						break;
					}
				}
			}
			flag = 0;
			for(i=0 ; i<N ; i++)
			{
				if(!visited[i])
				{
					flag = 1;
					break;
				}
			}
		}while(flag);
		printf("%d\n" ,cnt);
		
	}
	return 0;
}
