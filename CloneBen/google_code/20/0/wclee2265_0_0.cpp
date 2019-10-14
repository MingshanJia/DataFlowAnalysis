#include <stdio.h>

FILE *in=fopen("A-small-attempt0.in","rt");
FILE *out=fopen("output.txt","wt");

int m,md,wd,ans;

void process()
{
	int i,prev=0;
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
		fscanf(in,"%d %d %d",&m,&md,&wd);
		process();
		fprintf(out,"Case #%d: %d\n",i,ans);
	}
	return 0;
}