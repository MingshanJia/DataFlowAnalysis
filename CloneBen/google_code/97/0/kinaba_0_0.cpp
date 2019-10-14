//-----------------------------------------------------------------------------
// >>Code Template<< (for Visual C++)

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <complex>
#include <cmath>
#define  cout os
using namespace std;
typedef long long LL;
void END_OF_INPUT_FOR_THIS_TEST_CASE(); // stub for multi-threading

//-----------------------------------------------------------------------------
// >>Main<<

bool more(LL a, LL b, LL c, LL d) // a/b > c/d?
{
	return a*d > b*c;
}

bool sat(int m, vector<LL>& A, vector<LL>& B, vector<LL>& C)
{
	int MA=-1, MB=-1, MC=-1;
	for(int i=1,j=0; i<=m; i<<=1,++j)
		if( m&i ) // must consider j
		{
			if( MA==-1 || A[j]>A[MA] ) MA=j;
			if( MB==-1 || B[j]>B[MB] ) MB=j;
			if( MC==-1 || C[j]>C[MC] ) MC=j;
		}
	return A[MA]+B[MB]+C[MC]<=10000;
}

void case_main( ostream& os )
{
	int N; cin>>N;
	vector<LL> A(N),B(N),C(N);
	for(int i=0; i<N; ++i)
		cin >> A[i] >> B[i] >> C[i];
	END_OF_INPUT_FOR_THIS_TEST_CASE();

	int ans = 1;
	for(int m=1; m<(1<<N); ++m)
	{
		int b = 0;
		for(int i=1; i<=m; i<<=1)
			if( m&i )
				b++;

		if( ans<b && sat(m, A, B, C) )
			ans = b;
	}
	os << ans << endl;
}

//-----------------------------------------------------------------------------
// >>Code Template<< (Single-Thread Solver)

#undef cout
void END_OF_INPUT_FOR_THIS_TEST_CASE() {}
int main() {
	int nCase; cin >> nCase;
	for(int id=1; id<=nCase; ++id) {
		cout << "Case #" << id << ": ";
		case_main( cout );
	}
}
