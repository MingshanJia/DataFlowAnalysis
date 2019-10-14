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
	return *(S64*)a - *(S64*)b;
}

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
