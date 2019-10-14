#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <queue>
#include <list>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

long long a[32];
long long b[32];
long long have[32];
int answer;

void make(long long x) {
	memset(a,0,sizeof(a));
	for (long long i = 0, w = 1; w <= x; ++i, w <<= 1) {
		if (x & w) {
			a[i] = ((x >> i) << 1) - 1;
		}
	}
}

void cut(int x) {
	for (int i = x; i < 32; ++i) {
		
		if (have[i] > 0) {
			--have[i];
			for (--i;i >= x;--i) {
				have[i] += 3;
			}
			return;
		}
		
	}
	++answer;
	for (int i = 0; i < 32; ++i) {
		have[i] += a[i];
	}
	for (int i = x; i < 32; ++i) {
                if (have[i] > 0) {
                        --have[i];
                        for (--i;i >= x;--i) {
                                have[i] += 3;
                        }
                        return;
                }

        }

}
	
int main() {
	FILE *infp, *outfp;
	infp = fopen( "input.in","r" );
	outfp = fopen( "output.txt","w" );

	if (!infp) {
		printf( "cannnot open input file\n" );
		return 0;
	}
	if(!outfp) {
		printf( "cannnot open output file\n" );
		return 0;
	}
	int zz;
	fscanf(infp, "%d", &zz);
	for (int z = 1; z <= zz; ++z) {
		int n,m;
		fscanf(infp, "%d%d", &n,&m);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(have,0,sizeof(have));
		make(m);
		for (int i = 0; i < n; ++i) { 
			int x;
			fscanf(infp, "%d", &x);
			++b[x];
		}
		answer = 0;
		for (int i = 31; i >= 0; --i) {
			while (b[i]) {
				cut(i);
				--b[i];
			}
		}
		fprintf(outfp, "Case #%d: %d\n",z,answer);
	}
	
	return 0;
}