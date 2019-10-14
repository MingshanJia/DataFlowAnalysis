#include<cstdio>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
enum
{
	A_START = 0,
	A_END = A_START+3,
	B_START = A_END,
	B_END = B_START+3,
	SRC = B_END,
	SNK,
	G,
};
ll N;
ll A[3],B[3];
ll Flow[G][G];
ll Cost[G][G];
ll Cap[G][G];
const ll offset = 0;
ll Reach[G];
int From[G];
ll Pot[G];


pll findEx()
{
	for (int q=0;q<G;++q)
	{
		From[q] = -1;//undefined
		Reach[q] = 0;
	}
	From[SRC] = G;//START
	for (int q=0;q<G;++q) for (int w=0;w<G;++w) 
	{
		if (From[w]<0) continue;
		for (int e=0;e<G;++e)
		{
			if (Flow[w][e]<Cap[w][e] || Flow[e][w])
			{
				//w->e
				ll adc = Flow[e][w] ? -Cost[e][w] : Cost[w][e];	
				if (From[e]<0 || Reach[e] > Reach[w] + Pot[w] - Pot[e] + adc)
				{
					From[e] = w;
					Reach[e] = Reach[w] + Pot[w] - Pot[e] + adc;
				}
			}
		}
	}
	if (From[SNK]<0) return pll(0,0);//not found
	ll ret = 0, minCap = N;
	for (int u=From[SNK],v=SNK;u!=G;u=From[u],v=From[v])
	{
		ll myCap = Flow[v][u] ? (Flow[v][u]) : (Cap[u][v]-Flow[u][v]);
		minCap = min(minCap,myCap);
	}
	for (int u=From[SNK],v=SNK;u!=G;u=From[u],v=From[v])
	{
		ll myCost = Flow[v][u] ? (-Cost[v][u]) : (Cost[u][v]);
		if (Flow[v][u]) Flow[v][u] -= minCap;
		else	        Flow[u][v] += minCap;
		ret += myCost * minCap;
	}
	for (int q=0;q<G;++q) Pot[q] += Reach[q];
	return pll(minCap,ret);
}

ll solve()
{
	//N= A[0] + A[1] + A[2];
	for (int q=A_START;q<A_END;++q) Cap[SRC][q] = A[q-A_START];
	for (int q=B_START;q<B_END;++q) Cap[q][SNK] = B[q-B_START];
	for (int q=A_START;q<A_END;++q) for (int w=B_START;w<B_END;++w)
		Cap[q][w] = N;

	ll ret = 0, flowed = 0;
	while (true)
	{
		pll i = findEx();
		if (i.first==0) break;
		flowed += i.first;
		ret += i.second;
	}
	if (flowed != N)
	{
		fprintf(stderr,"FYEAH!\n");
	}
	return offset*N - ret;
}

int main()
{
	int T; cin >> T;
	for (int kase=1;kase<=T;++kase)
	{
		memset(Flow,0,sizeof(Flow));
		memset(Cost,0,sizeof(Cost));
		memset(Cap,0,sizeof(Cap));
		memset(Pot,0,sizeof(Pot));
		cin >> N;
		for (int q=0;q<3;++q) cin >> A[q];
		for (int q=0;q<3;++q) cin >> B[q];
		for (int q=A_START;q<A_END;++q) for (int w=B_START;w<B_END;++w) 
		{
			cin >> Cost[q][w];
			Cost[q][w] = offset-Cost[q][w];
		}
		cout << "Case #" << kase << ": " << solve() << endl;
	}
	return 0;
}
