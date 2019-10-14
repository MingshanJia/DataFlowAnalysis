#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,t,n,m,a,grp[55][25][25],gn,d[]={0,1,0,-1,0},xq[410],yq[410],hd,tl,chk[10010],q[10010],via[10010][2],chkn;
char arr[55][25][25];
vector<int> lnk[10010];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,k,x,y,l;
	bool suc;
	for(scanf("%d",&T),t=1; T--; t++){
		scanf("%d%d%d",&n,&m,&a);
		for(i=0; i<a; i++){
			for(j=0; j<n; j++){
				scanf("%s",arr[i][j]);
				for(k=0; k<m; k++) grp[i][j][k]=0;
			}
		}
		for(i=0; i<=gn; i++){
			lnk[i].clear();
			chk[i]=0;
		}
		gn=2;
		for(i=0; i<a; i++){
			for(j=0; j<n; j++){
				for(k=0; k<m; k++){
					if(arr[i][j][k]=='#'||grp[i][j][k]) continue;
					hd=0,tl=0;
					xq[tl]=j; yq[tl]=k; tl++;
					grp[i][j][k]=gn;
					if(i&1) lnk[gn].push_back(1);
					else lnk[0].push_back(gn);
					if(i&&grp[i-1][j][k]&&chk[grp[i-1][j][k]]!=gn){
						chk[grp[i-1][j][k]]=gn;
						if(i&1) lnk[grp[i-1][j][k]].push_back(gn);
						else lnk[gn].push_back(grp[i-1][j][k]);
					}
					while(hd<tl){
						for(l=0; l<4; l++){
							x=xq[hd]+d[l]; y=yq[hd]+d[l+1];
							if(x<0||y<0||x>=n||y>=m||grp[i][x][y]||arr[i][x][y]=='#') continue;
							xq[tl]=x; yq[tl]=y;
							grp[i][x][y]=gn;
							if(i&&grp[i-1][x][y]&&chk[grp[i-1][x][y]]!=gn){
								chk[grp[i-1][x][y]]=gn;
								if(i&1) lnk[grp[i-1][x][y]].push_back(gn);
								else lnk[gn].push_back(grp[i-1][x][y]);
							}
							tl++;
						}
						hd++;
					}
					gn++;
				}
			}
		}
		for(i=0; i<=gn; i++) chk[i]=0;
		chkn=0;
		do{
			suc=0;
			chk[0]=++chkn;
			hd=0,tl=0;
			via[tl][0]=-1;
			via[tl][1]=-1;
			q[tl++]=0;
			while(hd<tl){
				for(i=0; !suc&&i<lnk[q[hd]].size(); i++){
					if(chk[lnk[q[hd]][i]]==chkn) continue;
					chk[lnk[q[hd]][i]]=chkn;
					q[tl]=lnk[q[hd]][i];
					via[tl][0]=hd;
					via[tl][1]=i;
					if(lnk[q[hd]][i]==1){
						k=tl;
						while(via[k][0]>=0){
							lnk[q[k]].push_back(q[via[k][0]]);
							swap(lnk[q[via[k][0]]][via[k][1]],lnk[q[via[k][0]]][lnk[q[via[k][0]]].size()-1]);
							lnk[q[via[k][0]]].pop_back();
							k=via[k][0];
						}
						suc=1;
					}
					tl++;
				}
				hd++;
			}
		}while(suc);
		printf("Case #%d: %d\n",t,(gn-2)-(chkn-1));
	}
	return 0;
}