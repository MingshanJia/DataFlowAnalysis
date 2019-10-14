#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define infile "b.in"

FILE *fin=fopen(infile,"r"),
	*fout=fopen("b.out","w");

int L, P, C;

int work(int a, int b)
{
	int start, stop, mid, t1, t2, jl=1000000000;
	
	if ((b%C==0)&&(a>=b/C))
		return 0;
	if ((b%C!=0)&&(a>b/C))
		return 0;
	start = a+1;
	stop = b-1;
	while (start<=stop)
	{
		mid = (start+stop)/2;
		t1 = work(a,mid);
		t2 = work(mid, b);
		if (t1==t2)
			return t1+1;
		if (t1<t2)
		{
			jl=t2+1;
			start=mid+1;
		}
		else {
			jl=t1+1;
			stop=mid-1;
		}
	}
	return jl;
}

int main()
{
	int i,j,w,t,result;
	fscanf(fin,"%d",&t);
	for (w=1; w<=t; ++w)
	{
		fscanf(fin,"%d%d%d", &L, &P, &C);
		result = work(L, P);
		fprintf(fout,"Case #%d: %d\n", w, result);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}