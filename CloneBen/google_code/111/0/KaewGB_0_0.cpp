#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void solve(){
	int i;
	string line;
	getline(cin, line);
	printf("+");
	for(i=0;i<line.length()+2;i++)
		printf("-");
	printf("+\n| %s |\n+", line.c_str());
	for(i=0;i<line.length()+2;i++)
		printf("-");
	printf("+");
}

int main(int argc, char *argv[]){
	int i, t;
	scanf("%d\n", &t);
	for(i=0;i<t;i++){
		printf("Case #%d:\n", i+1);
		solve();
		printf("\n");
	}
	return 0;
}

