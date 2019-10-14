//#include "TC.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T,N;
string card[100];
int main()
{
	freopen("C-small-2-attempt0.in","r",stdin);
	freopen("Ans.out","w",stdout);
	//ifstream fin("dict.out");
	//ofstream fout("Ans.out");
	//FILE *fin=fopen("table.txt","r");
	//FILE *fout=fopen("Ans.out","w");
	cin>>T;
	for(int cas=1;cas<=T;cas++){
		cin>>N; char get[150];
		getchar();
		for(int i=0;i<N;i++){
			gets(get);
			card[i].assign(get);
		}
		string mm=card[0];
		int ans=0;
		for(int i=1;i<N;i++){
			if(card[i]<mm) ans++;
			else mm=card[i];
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	
	return 0;
}