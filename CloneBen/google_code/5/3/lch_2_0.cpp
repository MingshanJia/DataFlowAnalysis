#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    string max;
    for(int x = 1; x <= t; x++) {
	int n;
	int res = 0;
	scanf("%d", &n);
	getline(cin, max);
	getline(cin, max);
	for(int i = 1; i < n; i++) {
	    string tmp;
	    getline(cin, tmp);
	    if(tmp >= max) {
		max = tmp;
	    }
	    else {
		res++;
	    }
	}
	printf("Case #%d: %d\n", x, res);
    }
}
