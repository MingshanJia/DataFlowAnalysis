#include <stdio.h>
#include <algorithm>
using namespace std;

int N,C[10000];

int main()
{
	freopen ("1.in","r",stdin);
	freopen ("1.out","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);
		for (int i=0;i<10000;i++) C[i] = 0;
		scanf ("%d",&N); while (N--){
			int a,b; scanf ("%d %d",&a,&b);
			C[a]++; C[b+1]--;
		}
		for (int i=1;i<10000;i++) C[i] += C[i-1];

		int P,x; scanf ("%d",&P); while (P--){
			scanf ("%d",&x);
			printf ("%d ",C[x]);
		}
		puts("");
	}

	return 0;
}