#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

char s[128];

void go(){
	gets(s);
	int n = strlen(s);
	putchar('+');
	for(int i=0;i<n+2;++i)
		putchar('-');
	putchar('+');
	putchar('\n');
	printf("| %s |\n", s);
 	putchar('+');
	for(int i=0;i<n+2;++i)
		putchar('-');
	putchar('+');
	putchar('\n');
}

int main(){
	int T;
	scanf("%d\n", &T);
	for(int i=1;i<=T;++i){
		printf("Case #%d:\n", i);
		go();
	}
}
