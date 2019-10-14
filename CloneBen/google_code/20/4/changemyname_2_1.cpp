#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int n,p,m,kk[10001],head,tail,k;
long long print,val[101][10001],su[101][2];
struct q2{
	int no,su;
};
vector<q2> list[10001];
struct q{
	int no,su;
	bool operator() (q a,q b){
		return a.su>b.su;
	}
}heap[1000002];
void pro(){
	int i,t,j;
	long long max;
	q a;
	for(i=0;i<p;i++){
		heap[0].no=su[i][0];
		heap[0].su=0;
		val[i][su[i][0]]=0;
		k++;
		while(k!=0){
			a=heap[0];
			std::pop_heap(heap,heap+k,q());
			k--;
			if(val[i][a.no]<a.su) continue;
			for(j=0;j<kk[a.no];j++){
				if(val[i][list[a.no][j].no]>list[a.no][j].su+a.su){
					val[i][list[a.no][j].no]=list[a.no][j].su+a.su;
					heap[k].no=list[a.no][j].no;
					heap[k++].su=list[a.no][j].su+a.su;
					std::push_heap(heap,heap+k,q());
				}
			}
		}
	}
	print=100000000000;
	for(i=0;i<n;i++){
		max=0;
		for(j=0;j<p;j++){
			if(max<val[j][i]*su[j][1])
				max=val[j][i]*su[j][1];
		}
		if(max<print)
			print=max;
	}
}
int main(){
	int test,testt,i,j,nn,cost,a,b;
	q2 save;
	FILE *in,*out;
	in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	fscanf(in,"%d",&testt);
	for(test=1;test<=testt;test++){
		fscanf(in,"%d %d %d",&n,&p,&m);
		for(i=0;i<n;i++){
			list[i].clear();
			kk[i]=0;
			for(j=0;j<p;j++)
				val[j][i]=100000000000;
		}
		for(i=0;i<p;i++){
			fscanf(in,"%d %d",&su[i][0],&su[i][1]);
			su[i][0]--;
		}
		for(i=0;i<m;i++){
			fscanf(in,"%d %d",&save.su,&nn);
			fscanf(in,"%d",&a);
			a--;
			for(j=1;j<nn;j++){
				fscanf(in,"%d",&b);
				b--;
				save.no=b;
				list[a].push_back(save);
				kk[a]++;
				save.no=a;
				list[b].push_back(save);
				kk[b]++;
				a=b;
			}
		}
		pro();
		if(print==100000000000)
			print=-1;
		fprintf(out,"Case #%d: %d\n",test,print);
	}
	fcloseall();
	return 0;
}
