#include <stdio.h>
#include <string.h>

#define Max(x,y) ((x)>(y)?(x):(y))

FILE *in=fopen("B-small-attempt1.in","rt");
FILE *out=fopen("output.txt","wt");

int l[4],maxl;
char num[4][255],oper;
bool flag;

void reverse(char c_[], int len)
{
	char tmp[255];
	int i;
	for(i=1;i<=len;i++) tmp[i]=c_[len-i+1];
	for(i=1;i<=len;i++) c_[i]=tmp[i];
}

void input()
{
	int i;
	char tmp;
	fscanf(in," %s %c %s %c %s",&num[0][1],&oper,&num[1][1],&tmp,&num[2][1]);
	for(i=0;i<3;i++){
		l[i]=strlen(&num[i][1]);
		reverse(num[i],l[i]);
	}
}


long long string_to_int(char num[], int len)
{
	int i;
	long long t=0;
	for(i=len;i>=1;i--) t=t*10+num[i]-'0';
	return t;
}

bool go_check()
{
	int i;
	long long a[3];
	for(i=0;i<3;i++) a[i]=string_to_int(num[i],l[i]);
	if(oper=='+')
	{
		if(a[0]+a[1]==a[2]) return true;
		return false;
	}
	if(a[0]-a[1]==a[2]) return true;
	return false;
}

void process(int lev, int x)
{
	int i;
	if(flag) return;
	if(x==0)
	{
		if(lev==2){ 
			if(go_check()) flag=true;
		}
		else process(lev+1,l[lev+1]);
		return;
	}

	if(num[lev][x]=='?'){
		for(i=0;i<=9;i++)
		{
			if(x==l[lev] && l[lev]>1 && i==0) continue;
			num[lev][x]='0'+i;
			process(lev,x-1);
			if(flag) break;
			num[lev][x]='?';
		}
	}

	else process(lev,x-1);
}



int main()
{
	int t,i,j;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		flag=false;
		input();
		process(0,l[0]);
		for(j=0;j<3;j++) reverse(num[j],l[j]);
		fprintf(out,"Case #%d: %s %c %s = %s\n",i,&num[0][1],oper,&num[1][1],&num[2][1]);
	}
	fclose(in);
	fclose(out);
	return 0;
}