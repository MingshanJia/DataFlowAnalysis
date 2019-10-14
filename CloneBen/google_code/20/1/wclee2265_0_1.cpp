#include <stdio.h>

FILE *in=fopen("A-large.in","rt");
FILE *out=fopen("output.txt","wt");

long long m,md,wd,ans;

long long get_gcd(long long x, long long y)
{
	long long tmp;
	while(x%y!=0){
		tmp=x%y;
		x=y;
		y=tmp;
	}
	return y;
}

void get_cycle(long long &cycle_month, long long &cycle_line)
{
	long long i,prev=0;
	cycle_month=wd/get_gcd(md%wd,wd);
	for(i=1;i<=cycle_month;i++)
	{
		cycle_line+=(prev+md)/wd+((prev+md)%wd!=0);
		prev=(prev+md)%wd;
	}
}

void process()
{
	long long i,prev=0;
	long long cycle_line=0,cycle_month=0;

	get_cycle(cycle_month,cycle_line);
	ans+=(m/cycle_month)*cycle_line;
	m%=cycle_month;
	for(i=1;i<=m;i++)
	{
		ans+=(prev+md)/wd+((prev+md)%wd!=0);
		prev=(prev+md)%wd;
	}
}

int main()
{
	int t,i;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++){
		ans=0;
		fscanf(in,"%lld %lld %lld",&m,&md,&wd);
		process();
		fprintf(out,"Case #%d: %lld\n",i,ans);
	}
	return 0;
}