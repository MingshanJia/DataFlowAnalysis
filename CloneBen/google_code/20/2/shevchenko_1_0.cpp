#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n1,n2,n3,fin=0;
char a1[300],a2[300],a3[300];
char op[2],ans[300];

int check(){
	int m1,m2,m3;
	char temp[300];
	m1=atoi(a1);
	m2=atoi(a2);
	if(op[0]=='+') m3=m1+m2;
	else m3=m1-m2;
	if(m3<0) return 0;
	itoa(m3,temp,10);
	if(strlen(temp)!=n3) return 0;
	int i;
	for(i=0;i<n3;i++){
		if(a3[i]=='?') continue;
		if(a3[i]!=temp[i]) return 0;
	}
	strcat(ans,a1);
	strcat(ans," ");
	strcat(ans,op);
	strcat(ans," ");
	strcat(ans,a2);
	strcat(ans," = ");
	strcat(ans,temp);
	return 1;
}

void dfs(int l1, int l2){
	if(fin==1) return;
	if(l1==n1 && l2==n2){
		if(check()){
			fin=1;
		}
		return;
	}
	int i;
	if(l1==n1){
		if(a2[l2]=='?'){
			for(i='0';i<='9';i++){
				if(l2==0 && i=='0' && n2>1) continue;
				a2[l2]=i;
				dfs(l1,l2+1);
			}
			a2[l2]='?';
		}
		else dfs(l1,l2+1);
	}
	else{
		if(a1[l1]=='?'){
			for(i='0';i<='9';i++){
				if(l1==0 && i=='0' && n1>1) continue;
				a1[l1]=i;
				dfs(l1+1,l2);
			}
			a1[l1]='?';
		}
		else dfs(l1+1,l2);
	}
}

void process(){
	n1=strlen(a1); n2=strlen(a2); n3=strlen(a3);
	dfs(0,0);
	fin=0;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t, i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		scanf("%s %s %s = %s",a1,op,a2,a3);
		process();
		printf("%s\n",ans);
		ans[0]='\0';
	}
	return 0;
}