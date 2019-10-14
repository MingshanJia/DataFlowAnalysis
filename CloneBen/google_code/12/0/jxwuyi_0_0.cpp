#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cassert>
#include<complex>
using namespace std;

char S[10000], P[1000], sub[1000];
int n;

string pat[]={"","","double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple","decuple"};
string dig[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void run()
{
	scanf("%s", S); n = strlen(S);
	scanf("%s", P);
	int l = strlen(P);
	for(int i=0;i<l;++i) if(P[i]=='-') P[i]=' ';
	stringstream ss(P);
	char *s = S;
	while(ss >> l)
	{
		for(int i=0;i<l;++i)
			sub[i] = *s, s++;
		int i = 0, j;
		for(; i < l;)
		{
			for(j = i; j <l && sub[i] == sub[j]; ++ j);
			int rep = j - i;
			if(rep == 1 || rep > 10)
			{
				for(int k=i;k<j;++k)
					printf(" %s", dig[sub[k]-'0'].c_str());
			} else
			{
				printf(" %s %s", pat[rep].c_str(), dig[sub[i]-'0'].c_str());
			}
			i = j;
		}
	}
	puts("");
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	int test;
	scanf("%d", &test);
	for(int no=1;no<=test;++no)
	{
		printf("Case #%d:", no);
		run();
	}
}
