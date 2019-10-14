// Using libUtil from libGlov (Graphics Library of Victory) available at http://bigscreensmallgames.com/libGlov
#include "utils.h"
#include "file.h"
#include "strutil.h"
#include "assert.h"
#include "array.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include "rand.h"
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int __cdecl cmpInt(const void *a, const void *b)
{
	return (int)(*(S64*)a - *(S64*)b);
}

/*
char *doA(char **&toks)
{
	int n = atoi(*toks++);
	S64 a1[1000], a2[1000];
	for (int i=0; i<n; i++) {
		a1[i] = atoi(*toks++);
	}
	for (int i=0; i<n; i++) {
		a2[i] = atoi(*toks++);
	}
	qsort(a1, n, 8, cmpInt);
	qsort(a2, n, 8, cmpInt);
	S64 ret = 0;
	for (int i=0; i<n; i++) {
		ret += a1[i] * a2[n - i - 1];
	}
	static char buf[1024];
	sprintf(buf, "%I64d", ret);
	return buf;
}

*/

typedef struct Cust 
{
	int T;
	int C[3001][2];
} Cust;

Cust c[2001];
int N;
int ncust;
int fixed[2001]; // 1 = yes, unmalted, 2 = yes, malted

void fix(int x, int y)
{
	fixed[x] = y+1;
	for (int i=ncust-1; i>=0; i--) {
		for (int j=c[i].T-1; j>=0; j--) {
			if (c[i].C[j][0] == x) {
				if (c[i].C[j][1] == y) {
					// satisfied
					c[i] = c[ncust-1];
					ncust--;
					break;
				} else {
					// unsatisfied
					copyVec2(c[i].C[j], c[i].C[c[i].T-1]);
					c[i].T--;
				}
			}
		}
	}
}

char *doB(char **&toks)
{
	N = atoi(*toks++);
	ncust = atoi(*toks++);
	for (int i=0; i<ncust; i++) {
		c[i].T = atoi(*toks++);
		for (int j=0; j<c[i].T; j++) {
			c[i].C[j][0] = atoi(*toks++) - 1;
			c[i].C[j][1] = atoi(*toks++);
		}
	}
	memset(fixed, 0, sizeof(fixed));

doit:
	// find customers with only one choice
	for (int i=0; i<ncust; i++) {
		if (c[i].T == 0)
		{
			return "IMPOSSIBLE";
		}
		else if (c[i].T == 1)
		{
			int x = c[i].C[0][0];
			int y = c[i].C[0][1];
			assert(!fixed[x]);
			fix(x, y); // May remove any number of customers
			goto doit;
		}
	}
	// Good!
	static char buf[20000];
	for (int i=0; i<N; i++) {
		buf[i*2] = (fixed[i]==0)?'0':(fixed[i]==1)?'0':'1';
		buf[i*2+1] = ' ';
	}
	buf[N*2-1] = 0;
	return buf;
}

/*
char *doC(char **&toks)
{
	int n = atoi(*toks++);
	// Lookup generated from a calculator
	static const char * lookup[] = 
	{"001",
	"005",
	"027",
	"143",
	"751",
	"935",
	"607",
	"903",
	"991",
	"335",
	"047",
	"943",
	"471",
	"055",
	"447",
	"463",
	"991",
	"095",
	"607",
	"263",
	"151",
	"855",
	"527",
	"743",
	"351",
	"135",
	"407",
	"903",
	"791",
	"135",
	"647"};
	return (char*)lookup[n];
}
*/