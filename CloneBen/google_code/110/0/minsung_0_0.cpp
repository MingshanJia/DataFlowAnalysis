#include<cstdio>

using namespace std;

int n;
char ans [1005];
char data[8005];
int main() {
	int tcc;
	scanf("%d", &tcc);
	int i,j,k;
	for (int tc=1; tc<=tcc; tc++) {
		scanf("%d", &n);
		scanf("%s", data);
		for (i = 0; i < n; i++) {
			ans[i] = 0;
			for (j = 8*i; j < 8*(i+1); j++) {
			  ans[i]*=2;
				if (data[j] == 'I')
					ans[i]++;
			}
		}	
		ans[n] = '\0';
		printf("Case #%d: %s\n", tc, ans);
	}
	return 0;
}
