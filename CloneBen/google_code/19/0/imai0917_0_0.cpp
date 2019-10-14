#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

FILE *fin = fopen("input.txt", "r");
FILE *fout = fopen("output.txt", "w");

void process(void)
{
	int N;
	int P[20], S[20];
	int i;
	fscanf(fin, "%d", &N);
	for (i=0;i<N;++i){
		fscanf(fin, "%d %d", &P[i], &S[i]);
	}

	vector<int> a;
	for (i=0;i<N;++i){
		a.push_back(i);
	}

	int res=0;
	do{
		int t=0;
		int k=0;
		bool flag = true;
		for (k=0;k<N;++k){
			i = a[k];
			if (P[i] < t){
				flag = false;
				break;
			}
			t = t + S[i];
		}
		if (res < t) res = t;
	}while(next_permutation(a.begin(), a.end()));
	fprintf(fout, "%d\n", res);
}

int main(void)
{
	int T, t;
	fscanf(fin, "%d", &T);
	for (t=1;t<=T;++t){
		fprintf(fout, "Case #%d: ", t);
		process();
	}
	fclose(fout);
	fclose(fin);
	return 0;
}
