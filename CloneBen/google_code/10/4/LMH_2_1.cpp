#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define FI(i,a, b) for(i=a;i<=b;i++)
#define FD(i,a, b) for(i=a;i>=b;i--)

#define CL(x, y) memset(x, y, sizeof(x))
#define INF 100000000
#define MAXN ?
#include<map>
#define MAXE ?
#define pb push_back
#define ll long long
#include<vector>
#define mod 1000000007LL
using namespace std;
int i, j, k, N, M, K, P, Q, R, S;
int dat[5005][5], query[5005][3], m[200005][3];
char str[100], name[50050][20], s1[100], s2[100], s3[100];
struct node{
	int v, w;
};//, e[1000000];
struct state{
	int v, w, st;
}t1, t2;

queue<state> q;
vector<node> e[100000];
void init(){
	int i, j, k;
	P = Q = R = S = M = N = 0;
	CL(name, 0);
	CL(m, -1);
	FI(i, 0, 99999) while(e[i].size()) e[i].pop_back();
}
int find(char a[]){
	int i, j, k;
	k = 0;
	FI(i, 1, P) if(strcmp(name[i], a) == 0){
		k = i;
		break;
	}
	if(!k){
		sprintf(name[++P], "%s", a);
		return P;
	}else return k;
	
}
int bfs(int st, int en){
	int i, j, k;
	while(!q.empty()) q.pop();
	CL(m, -1);
	m[st][0] = 0;
	t1 = (state){st, 0, 0};
	q.push(t1);
	while(!q.empty()){
		t1 = q.front(), q.pop();
		//printf("%d %d\n", t1.v, t1.st);
		if(t1.v == en && t1.st){
			return t1.w;
		}
		int a = t1.v, b, c = t1.st, d = t1.w;
		if(e[a].size()){
			FI(i, 0, e[a].size() - 1){
				b = e[a][i].v;
				if(m[b][c ^ 1] == -1){
					m[b][c ^ 1] = d + e[a][i].w;
					if(c == 0)
					t2 = (state){b, d + e[a][i].w, c ^ 1};
					else
					t2 = (state){b, d - e[a][i].w, c ^ 1};
					q.push(t2);
				}
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d", &K);
	FI(k, 1, K){
		init();
		int pos;
		scanf("%d", &N);
		FI(i, 1, N){
			scanf("%s", str);
			M = strlen(str);
			int a, b;
			FI(j, 0, M - 1){
				if(str[j] == '+') a = j;
				else if(str[j] == '=') b = j;
			}
			CL(s1, 0);CL(s2, 0);CL(s3, 0);
			FI(j, 0, a - 1) s1[j] = str[j];
			FI(j, a + 1, b - 1) s2[j - a - 1] = str[j];
			FI(j, b + 1, M - 1) s3[j - b - 1] = str[j];
			pos = find(s1);
			dat[i][0] = pos; pos = find(s2); dat[i][1] = pos; dat[i][2] = atoi(s3);
		}
		scanf("%d", &Q);
		FI(i, 1, Q){
			scanf("%s", str);
			M = strlen(str);
			int a,b ;
			CL(s1, 0);CL(s2, 0);
			FI(j, 0, M - 1){
				if(str[j] == '+') a = j;
			}
			FI(j, 0, a - 1) s1[j] = str[j];
			FI(j, a + 1, M - 1) s2[j - a - 1] = str[j];
			pos = find(s1); query[i][0] = pos; pos = find(s2); query[i][1] = pos; 
		}
		FI(i, 1, N){
			int a = dat[i][0], b = dat[i][1], c = dat[i][2];
			e[a].pb((node){b, c});
			e[b].pb((node){a, c});
			
		}
		printf("Case #%d:\n", k);
		FI(i, 1, Q){
			int a = query[i][0], b = query[i][1], ans = bfs(a, b);
			//printf("i = %d ans = %d\n", i, ans);
			if(ans){
				printf("%s+%s=%d\n", name[a], name[b], ans);
			}
		}
	}
}
