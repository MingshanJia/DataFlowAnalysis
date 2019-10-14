#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

int T,C,N,P[11],S[11],CHK[11],ANS;

void go(int a, int t)
{
	if (ANS < t) ANS = t;
	int i;

	for (i=0;i<N;i++) if (CHK[i] == 0 && t <= P[i]){
		CHK[i] = 1;
		go(a+1,t+S[i]);
		CHK[i] = 0;
	}
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int i;

	scanf ("%d",&T); while (T--){
		scanf ("%d",&N); ANS = 0;
		for (i=0;i<N;i++) scanf ("%d %d",&P[i],&S[i]);
		go(0,0);
		printf ("Case #%d: %d\n",++C,ANS);
	}

	return 0;
}