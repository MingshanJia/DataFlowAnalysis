#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2200;
int cases;
int n;
int up[N], down[N];
int deg[N];
bool g[N][N];
bool vis[N];
int ans[N];

void run() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
	scanf("%d", &up[i]);
    for (int i = 1; i <= n; i++)
	scanf("%d", &down[i]);

    memset(g, 0, sizeof g);
    for (int i = 1; i <= n; i++) {
	bool flag = false;
	for (int j = i - 1; j; j--) {
	    if (up[j] + 1 == up[i])
		if (!flag) {
		    g[j][i] = true;
		    flag = true;
		}
	    if (up[j] >= up[i])
		g[i][j] = true;
	}
    }
    
    for (int i = 1; i <= n; i++) {
	bool flag = false;
	for (int j = i + 1; j <= n; j++) {
	    if (down[j] + 1 == down[i])
		if (!flag) {
		    g[j][i] = true;
		    flag = true;
		}
	    if (down[j] >= down[i]) 
		g[i][j] = true;
	}
    }

    memset(deg, 0, sizeof deg); 
    for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	    if (g[i][j]) 
		++deg[j];
    //for (int i = 1; i <= n; i++)
//	printf("%d ", deg[i]);
  //  printf("\n");
    memset(vis, 0, sizeof vis);
     
    for (int k = 1; k <= n; k++) {	
	int w = 0;
	for (int i = 1; i <= n; i++)
	    if (!vis[i] && deg[i] == 0) {
		w = i;
		break;
	    }
	if (w == 0) printf("error\n");	
	vis[w] = true;
	ans[w] = k;
	for (int i = 1; i <= n; i++)
	    if (g[w][i])
		--deg[i];
    }	

    for (int i = 1; i <= n; i++)
	printf(" %d", ans[i]);
    printf("\n");

//    for (int i = 1; i <= n; i++) {
//	for (int j = 1; j <= n; j++)
//	    printf("%d ", g[i][j]);
//	printf("\n");
    //}
}

int main() {
    scanf("%d", &cases);
    for (int ca = 1; ca <= cases; ++ca) {
	printf("Case #%d:", ca);
	run();
    }	
}
