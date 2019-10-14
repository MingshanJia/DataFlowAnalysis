#include <stdio.h>
int year,month,week;
long long print,line[201],status[201];
void pro(){
	int i,cnt,stat;
	for(i=0;i<week;i++){
		stat=i;
		cnt=1;
		line[i]=1;
		while(cnt+week<=month){
			cnt+=week;
			line[i]++;
		}
		while(cnt!=month){
			cnt++;
			stat++;
			if(stat==week){
				line[i]++;
				stat=0;
			}
		}
		status[i]=stat;
	}
	stat=print=0;
	for(i=0;i<year;i++){
		print+=line[stat];
		stat=status[stat]+1;
		if(stat==week)
			stat=0;
	}
}
int main(){
	int test,testt;
	FILE *in,*out;
	in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	fscanf(in,"%d",&testt);
	for(test=1;test<=testt;test++){
		fscanf(in,"%d %d %d",&year,&month,&week);
		pro();
		fprintf(out,"Case #%d: %lld\n",test,print);
	}
	fcloseall();
	return 0;
}
