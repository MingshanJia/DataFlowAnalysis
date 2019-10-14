#include <stdio.h>

int t,T;

long long m,d,w;
long long mshiftday;
long long recurrence;

long long numlines(long long nummonths){
	if (nummonths > recurrence){
		long long remnant = nummonths % recurrence;
		long long ret = numlines(remnant);
		ret += (nummonths / recurrence) * numlines(recurrence);
		return ret;
	}
	else{
		long long ret = 0;
		long long shifts = 0; 
		for (long long i=0;i<nummonths;++i){
			ret += (shifts + d) / w + (((shifts + d) % w )!=0);
			shifts += mshiftday;
			shifts %= w;
		}
		return ret;
	}
}

int main(){
	freopen("a-small.in","rt",stdin);
	freopen("a-small.out","wt",stdout);
	scanf("%d",&T);
	for (int t=1;t<=T;++t){

		scanf("%lld %lld %lld",&m,&d,&w);

		
		mshiftday = d % w;
		
		// mshiftday * k = w * l
		long long test = 0;

		for (recurrence = 1;;++recurrence){
			test += mshiftday;
			test %= w;
			if (test == 0){
				break;
			}
		}
		long long ans = numlines(m);
		printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}