#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int List[100][2];

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; ++t) {
		int M, C, W;
		scanf("%d%d%d", &M, &C, &W);
		for(int i=0; i<C; ++i) {
			scanf("%d%d", &List[i][0], &List[i][1]);
		}
		int w = W - 1;
		for(int i=C-1; 0<=i; --i) {
			int a = List[i][0] - 1;
			int b = List[i][1];
			if(w<a+b) {
				if(w<b) {
					w += a;
				}
				else {
					w -= b;
				}
			}
		}
		printf("Case #%d: %d\n", t+1, w+1);
	}
	return 0;
}
