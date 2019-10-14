#include <iostream>
#include <iomanip>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;
const int MAXN = 110;
const long long MOD = 1000000007;
long long S[MAXN][MAXN];
long long J[MAXN];


void preCout(int LM) {
	S[1][1]	= 1;
	S[2][1] = S[2][2] = 1;
	for (int i = 3; i <= LM; i++) {
		S[i][1] = S[i][i] = 1;
		for (int j = 2; j <= i-1; j++)
			S[i][j] = (S[i-1][j-1] + (long long)j*S[i-1][j])%MOD;
	}
	/*
	for (int i = 3; i <= LM; i++) {
		for (int j = 2; j <= i-1; j++)
			cout << S[i][j] << "\t";
		cout << endl;
	}
	*/
	J[0]= J[1] = 1;
	for (int i = 2; i < LM; i++)
		J[i] = J[i-1]*i%MOD;
}

int main()
{
	int T, M, N;
	cin >> T;
	preCout(106);
	for (int caseI = 1; caseI <= T; caseI++){
		cin >> M >> N;
		long long ret = J[M]*S[N][M]%MOD;
		//cout << J[M] << "\t" << S[N][M]<< endl;
		cout << "Case #"<<caseI<<": " << ret << endl;
	}
	return 0;
}
