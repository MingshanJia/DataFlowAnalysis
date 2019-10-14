//-----------------------------------------------------------------------------
// >>Code Template<< (for Visual C++)

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
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

void case_main( ostream& os )
{
	int W, H; cin>>W>>H;
	int X1,Y1; cin>>X1>>Y1;
	int X2,Y2; cin>>X2>>Y2;
	int XS,YS; cin>>XS>>YS;
	END_OF_INPUT_FOR_THIS_TEST_CASE();

	set<int> visited;
	queue<int> Q;
	Q.push( XS*100 + YS );
	visited.insert( XS*100 + YS );
	while( !Q.empty() )
	{
		int P = Q.front(); Q.pop();
		int x = P/100, y = P%100;
		int x1=x+X1, y1=y+Y1, p1=x1*100+y1;
		int x2=x+X2, y2=y+Y2, p2=x2*100+y2;
		if( 0<=x1 && x1<W && 0<=y1 && y1<H && !visited.count(p1) )
			Q.push(p1), visited.insert(p1);
		if( 0<=x2 && x2<W && 0<=y2 && y2<H && !visited.count(p2) )
			Q.push(p2), visited.insert(p2);
	}
	os << visited.size() << endl;
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
