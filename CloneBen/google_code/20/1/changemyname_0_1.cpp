#include <stdio.h>
long long print,line[201],status[201],year,month,week;
void pro(){
	int cnt,stat;
	long long a,i;
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
		if(stat==0) break;
	}
	i++;
	a=year/i;
	print*=a;
	i=i*a;
	stat=0;
	for(;i<year;i++){
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
		fscanf(in,"%lld %lld %lld",&year,&month,&week);
		pro();
		fprintf(out,"Case #%d: %lld\n",test,print);
	}
	fcloseall();
	return 0;
}
