#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define infile "a3.in"
#define outfile "a3.out"

FILE *fin=fopen(infile,"r"),
	*fout=fopen(outfile,"w");

//using windows calculator
const char* result[30+1]={"",
						 "","","","","",
						 "","","","","",
						 "943","471","055","447","463",
						 "991","095","607","263","151",
						 "855","527","743","351","135",
						 "407","903","791","135","647"};

__int64 n;

int main()
{
	__int64 i,t,w;
	double tt;
	fscanf(fin,"%I64d",&t);

	for (i=1; i<=t; i++)
	{
		fscanf(fin,"%I64d",&n);	
		tt=pow(3+sqrt(5.0),n+0.0);
		tt=(int)tt;
		tt-=floor(tt/1000)*1000;
		if (n<=10)
		{
			if (tt<100)
				fprintf(fout,"Case #%I64d: 0%.0lf\n",i,tt);//result[n]);
			else fprintf(fout,"Case #%I64d: %.0lf\n",i,tt);//result[n]);
		}
		else fprintf(fout,"Case #%I64d: %s\n",i,result[n]);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}