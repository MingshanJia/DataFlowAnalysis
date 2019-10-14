#include <stdio.h>
#include <string.h>
int n,su[101],len;
char mun[101];
bool fi;
long long convert(int i){
	long long sum=0;
	for(;i<len;i++){
		if(mun[i]>'9' || mun[i]<'0') break;
		sum*=10;
		sum+=mun[i]-'0';
	}
	return sum;
}
bool check(){
	int i;
	long long sum=convert(0);
	for(i=0;i<len;i++){
		if(mun[i]==' '){
			if(mun[i+1]=='+'){
				sum+=convert(i+3);
				i+=3;
			}
			else if(mun[i+1]=='-'){
				sum-=convert(i+3);
				i+=3;
			}
			else{
				if(sum==convert(i+3))
					return true;
				return false;
			}
		}
	}
}
void back(int k){
	if(k==n){
		if(check())
			fi=1;
	}
	else{
		int i=0;
		if(su[k]==0 || mun[su[k]-1]==' '){
			i=1;
			if(mun[su[k]+1]==' ' || su[k]+1==len)
				i=0;
		}
		for(;i<10;i++){
			mun[su[k]]=i+'0';
			back(k+1);
			if(fi) break;
		}
	}
}
int main(){
	int testt,test,i;
	FILE *in,*out;
	in=fopen("input.txt","r");
	fscanf(in,"%d\n",&testt);
	out=fopen("output.txt","w");
	for(test=1;test<=testt;test++){
		fgets(mun,1000,in);
		len=strlen(mun);
		n=0;
		if(mun[len-1]==10){
			mun[len-1]='\0';
			len--;
		}
		for(i=0;i<len;i++){
			if(mun[i]=='?')
				su[n++]=i;
		}
		fi=0;
		back(0);
		fprintf(out,"Case #%d: %s\n",test,mun);
	}
	fcloseall();
	return 0;
}
