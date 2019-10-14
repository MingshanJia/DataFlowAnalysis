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

char *doB(char **&toks)
{
	return "";
}


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
