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
/*
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
*/
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

005
027
143
751
935

607
903
991
335
047
943
471
055
447
463
991
095
607
263
151
855
527
743
351
135

407
903
791
135
647
343
471
455
847
263
191
095
807
463
551
455
527
343
951
335
207
903
591
935
247
743
471
855
247
063
391
095
007
663
951
055
527
943
551
535
007
903
391
735
847
143
471
255
647
863
591
095
207
863
351
655
527
543
151
735
807
903
191
535
447
543
471
655
047
663
791
095
407
063
751
255
527
143
751
935
607
903
991
335
047
943
471
055
447
463
991
095
607
263
151
855
527
743
351
135

407
903
791
135
647
343
471
455
847
263
191
095
807
463
551
455
527
343
951
335
207
903
591
935
247
743
471
855
247
063
391
095
007
663
951
055
527
943
551
535
007
903
391
735
847
143
471
255
647
863
591
095
207
863
351
655
527
543
151
735
807
903
191
535
447
543
471
655
047
663
791
095
407
063

	return (char*)lookup[n];
}
*/

char *doC(char **&toks)
{
	// first hundred or so, outputted by "Precise Calculator" running this script at 1K digit precision:
// n=1;    x = (3+sqrt(5))^n; v = x - int(x); vv = (x - v) % 1000; print vv; n++; if(n<200, goto1, 0);
	static char *pattern[] = {
"001",
"005",
"027", // r0 repeat start
"143",
"751",
"935",
"607", // r1 repeat start
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

"407", // r2 repeat
"903",
"791",
"135",
"647",
"343",
"471",
"455",
"847",
"263",
"191",
"095",
"807",
"463",
"551",
"455",
"527",
"343",
"951",
"335",
"207",
"903",
"591",
"935",
"247",
"743",
"471",
"855",
"247",
"063",
"391",
"095",
"007",
"663",
"951",
"055",
"527",
"943",
"551",
"535",
"007",
"903",
"391",
"735",
"847",
"143",
"471",
"255",
"647",
"863",
"591",
"095",
"207",
"863",
"351",
"655",
"527",
"543",
"151",
"735",
"807",
"903",
"191",
"535",
"447",
"543",
"471",
"655",
"047",
"663",
"791",
"095",
"407",
"063",
"751",
"255",
"527",
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
};
int r0 = 2; int r0l = 4;
int r1 = 6; int r1l = 20;
int r2 = 26; int r2l = ARRAY_SIZE(pattern) - r2;

	int n = atoi(*toks++);
	if (n<3)
		return pattern[n];
	static char v[4];
	v[2] = pattern[((n - r0) % r0l) + r0][2];
	v[1] = pattern[((n - r1) % r1l) + r1][1];
	v[0] = pattern[((n - r2) % r2l) + r2][0];
	v[4] = '\0';
	return v;
}