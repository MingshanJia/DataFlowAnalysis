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
typedef pair<int , int> PI;

int main()
{
	int _T;
	scanf("%d" , &_T);
	
	int N , i , j , k;
	string dir;
	long long ele[21][21];
	int mearged[21][21];
	for(int _a = 1 ; _a <= _T ; _a++)
	{
		printf("Case #%d:\n" , _a);
		cin >> N >> dir;
		for(i=0 ; i<N ; i++)
		{
			for(j=0 ; j<N ; j++)
			{
				scanf("%lld" , &ele[i][j]);
			}
		}
		memset(mearged , 0 , sizeof(mearged));
		if(dir == "right")
		{
			for(i=0 ; i<N ; i++)
			{
				for(j=N-2 ; j>=0 ; j--)
				{
					k = j+1;
					while(k < N && ele[i][k] == 0)
					{
						k++;
					}
					if(k < N && ele[i][k] == ele[i][j] && !mearged[i][k])//merge
					{
						ele[i][k] += ele[i][k];
						ele[i][j] = 0;
						mearged[i][k] = 1;
					}
					else //if(k == N)
					{
						swap(ele[i][k-1] , ele[i][j]);
					}
				}
			}
		}
		else if(dir == "left")
		{
			for(i=0 ; i<N ; i++)
			{
				for(j=1 ; j<N ; j++)
				{
					k = j-1;
					while(k >= 0 && ele[i][k] == 0)
					{
						k--;
					}
					if(k < N && ele[i][k] == ele[i][j] && !mearged[i][k])//merge
					{
						ele[i][k] += ele[i][k];
						ele[i][j] = 0;
						mearged[i][k] = 1;
					}
					else //if(k == N)
					{
						swap(ele[i][k+1] , ele[i][j]);
					}
				}
			}
		}
		else if(dir == "up")
		{
			for(j=0 ; j<N ; j++)
			{
				for(i=1 ; i<N ; i++)
				{
					k = i-1;
					while(k >= 0 && ele[k][j] == 0)
					{
						k--;
					}
					if(k < N && ele[k][j] == ele[i][j] && !mearged[k][j])//merge
					{
						ele[k][j] += ele[k][j];
						ele[i][j] = 0;
						mearged[k][j] = 1;
					}
					else //if(k == N)
					{
						swap(ele[k+1][j] , ele[i][j]);
					}
				}
			}
		}
		else
		{
			for(j=0 ; j<N ; j++)
			{
				for(i=N-2 ; i>=0 ; i--)
				{
					k = i+1;
					while(k < N && ele[k][j] == 0)
					{
						k++;
					}
					if(k < N && ele[k][j] == ele[i][j] && !mearged[k][j])//merge
					{
						ele[k][j] += ele[k][j];
						ele[i][j] = 0;
						mearged[k][j] = 1;
					}
					else //if(k == N)
					{
						swap(ele[k-1][j] , ele[i][j]);
					}
				}
			}
		}
		for(i=0 ; i<N ; i++)
		{
			for(j=0 ; j<N ; j++)
			{
				printf("%lld " , ele[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
