#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define NN 22
#define KK 52
#define MMM 10003

int t,T;
int N,M,K;
int C;

char map[NN][NN][KK];
int number[NN][NN][KK];
std::vector<int> vege[MMM];

std::vector<int> aset;
std::vector<int> bset;

int capacity[MMM][MMM];
int flow[MMM][MMM];
int path[MMM];
int value[MMM];


void call(int n,int m,int k,int numb){
	number[n][m][k] = numb;
	int dx[6]={-1,1,0,0,0,0},dy[6]={0,0,-1,1,0,0},dz[6]={0,0,0,0,-1,1};
	for (int i=0;i<4;++i){
		int x,y,z;
		x = n + dx[i];
		y = m + dy[i];
		z = k + dz[i];
		if (map[x][y][z] == '.' && !number[x][y][z]){
			call(x,y,z,numb);
		}
	}
}

std::vector<int> startsets;
bool flag[MMM],fflag[MMM][2];
int D[MMM][2];

void caller(int city,int bip){
	flag[city] = true;
	if (!bip){
		aset.push_back(city);
	}
	else{
		bset.push_back(city);
	}
	for (int i=0;i<vege[city].size();++i){
		int dest = vege[city][i];
		for (int j=0;j<vege[dest].size();++j){
			if (flag[vege[dest][j]]){
				vege[dest][j] = vege[dest].back();
				vege[dest].resize(vege[dest].size()-1);
				j--;
			}
		}
	}
	for (int i=0;i<vege[city].size();++i){
		int dest = vege[city][i];
		if (!flag[vege[city][i]]){
			caller(dest,!bip);
		}
	}
}

int cvalue(int city,int checked){
	int ret = 0;
	//if (!fflag[city][checked]){
		//fflag[city][checked] = true;
		for (int i=0;i<vege[city].size();++i){
			int dest = vege[city][i];
			if (checked){
				ret += cvalue(dest,0);
			}
			else{
				ret += std::max(cvalue(dest,0), cvalue(dest,1));
			}
		}
		D[city][checked] = ret + checked;
	//}
	return D[city][checked];
}

std::vector<int> movelist(int n,int m,int k,int numb){
	std::vector<int> ret;
	int dx[6]={-1,1,0,0,0,0},dy[6]={0,0,-1,1,0,0},dz[6]={0,0,0,0,-1,1};
	for (int i=4;i<6;++i){
		int x,y,z;
		x = n + dx[i];
		y = m + dy[i];
		z = k + dz[i];
		if (map[x][y][z] == '.' && number[x][y][z]){
			ret.push_back(number[x][y][z]);
		}
	}
	std::sort(ret.begin(),ret.end());
	ret.resize(std::unique(ret.begin(),ret.end())-ret.begin());
	return ret;
}

int main(){
	//freopen("c.in","rt",stdin);
	//freopen("c.out","wt",stdout);
	freopen("c-small-attempt5.in","rt",stdin);
	freopen("c-small-attempt5.out","wt",stdout);
	scanf("%d",&T);
	for (t=1;t<=T;++t){
		scanf("%d %d %d",&N,&M,&K);
		memset(map,0,sizeof(map));
		for (int i=1;i<=K;++i){
			char smap[NN]={0,};
			for (int j=1;j<=N;++j){
				scanf("%s",smap+1);
				for (int k=1;k<=M;++k){
					map[j][k][i] = smap[k];
				}
			}
		}
		C=0;
		memset(number,0,sizeof(number));
		memset(capacity,0,sizeof(capacity));
		memset(flow,0,sizeof(flow));
		for (int i=1;i<=N;++i){
			for (int j=1;j<=M;++j){
				for (int k=1;k<=K;++k){
					if (!number[i][j][k] && map[i][j][k]=='.'){
						call(i,j,k,++C);
					}
				}
			}
		}

		for (int i=1;i<=C;++i){
			vege[i].clear();
		}
		
		for (int i=1;i<=N;++i){
			for (int j=1;j<=M;++j){
				for (int k=1;k<=K;++k){
					if (number[i][j][k]){
						int numb = number[i][j][k];
						std::vector<int> tomove = movelist(i,j,k,numb);
						for (int l=0;l<tomove.size();++l){
							capacity[numb][tomove[l]] = 10000000+2;
							vege[numb].push_back(tomove[l]);
						}
						std::sort(vege[numb].begin(),vege[numb].end());
						vege[numb].resize(std::unique(vege[numb].begin(),vege[numb].end())-vege[numb].begin());
					}
				}
			}
		}

		//for (int i=1;i<=C;++i){
			//for (int j=1;j<=C;++j){
				//capacity[i][j] = 1;
				//capacity[i][j] = MMM+2;
			//}
		//}
	
		startsets.clear();
		memset(flag,0,sizeof(flag));
//		memset(fflag,0,sizeof(fflag));
		memset(D,0,sizeof(D));
		aset.clear();
		bset.clear();
		
		for (int i=1;i<=C;++i){
			if (!flag[i]){
				startsets.push_back(i);
				caller(i,0);
			}
		}

		for (int i=0;i<aset.size();++i){
			capacity[0][aset[i]] = 1;//MMM+2;
		}

		for (int i=0;i<bset.size();++i){
			capacity[bset[i]][C+1] = 1;//MMM+2;
		}

		for (int i=0;i<aset.size();++i){
			for (int j=0;j<bset.size();++j){
				capacity[bset[j]][aset[i]] = 0;
			}
		}


		int ans = 0;
		int flowed;
		do{
			flowed = 0;
			std::queue<int> q;
			q.push(0);

			memset(path,0,sizeof(path));
			memset(flag,0,sizeof(flag));
			memset(value,0,sizeof(value));

			value[0] = 10000000+2;
			flag[0] = true;

			while(!q.empty()){
				int node = q.front();
				if (node == C+1 || value[C+1]){
					break;
				}
				q.pop();
				for (int i=0;i<=C+1;++i){
					if (capacity[node][i] - flow[node][i] > 0 && !flag[i]){
						flag[i] = true;
						path[i] = node;
						value[i] = std::min(value[node],capacity[node][i] - flow[node][i]);
						q.push(i);
					}
				}
			}
			if (!value[C+1]){
				break;
			}
			else{
				int city = C+1;
				flowed = value[C+1];
				int back;
				do{
					back = path[city];
					flow[back][city] += flowed;
					flow[city][back] -= flowed;
					city = back;
				}while(back);
			}
			ans += flowed;
		}while(flowed);


		/*int ans = 0;
		for (int i=0;i<startsets.size();++i){
			int val = 0;
			val = std::max(cvalue(startsets[i],0),cvalue(startsets[i],1));
			ans += val;
		}*/


		printf("Case #%d: %d\n",t,C-ans);
	}
	return 0;
}