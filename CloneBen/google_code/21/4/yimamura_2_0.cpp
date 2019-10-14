#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

int MSB(long long n) {
	for(int i=63; 0<=i; --i) {
		if(n & (((long long)1) << i)) {
			return i;
		}
	}
	return -1;
}
int countBits(unsigned long long n) {
	n = (n & 0x5555555555555555LL) + ((n >> 1) & 0x5555555555555555LL);
	n = (n & 0x3333333333333333LL) + ((n >> 2) & 0x3333333333333333LL);
	unsigned int b = (unsigned int)(n + (n >> 32));
	b = (b & 0x0f0f0f0f) + ((b>>4) & 0x0f0f0f0f);
	b = b + (b>>8);
	b = (b + (b>>16)) & 0x000000ff;
	return b;
}
int func(long long n) {
	if(n==0) {
		return 0;
	}
	if(n==1) {
		return 1;
	}
	int msb = MSB(n);
	assert(0<=msb);
	long long mask = (((long long)1) << msb) - 1;
	return msb + countBits(n - mask);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; ++t) {
		long long N;
		scanf("%lld", &N);
		printf("Case #%d: %d\n", t+1, func(N));
	}
	return 0;
}
