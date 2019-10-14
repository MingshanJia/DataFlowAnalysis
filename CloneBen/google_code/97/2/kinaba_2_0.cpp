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

bool match(int M, int b[50][50], int R, int C)
{
	int m[52][52]={};
	for(int y=0; y<R; ++y)
		for(int x=0; x<C; ++x)
			if( (M>>C*y)&(1<<x) )
				m[y+1][x+1] = 1;

	for(int y=0; y<R; ++y)
		for(int x=0; x<C; ++x)
		{
			int b2 =
				m[y][x] + m[y][x+1] + m[y][x+2] +
				m[y+1][x] + m[y+1][x+1] + m[y+1][x+2] +
				m[y+2][x] + m[y+2][x+1] + m[y+2][x+2];
			if( b2 != b[y][x] )
				return false;
		}
	return true;
}

void case_main( ostream& os )
{
	int R, C; cin>>R>>C;
	int b[50][50];
	for(int y=0; y<R; ++y)
		for(int x=0; x<C; ++x)
			cin >> b[y][x];
	END_OF_INPUT_FOR_THIS_TEST_CASE();

	int ans = 0;
	for(int m=1; m<(1<<R*C); ++m)
	{
		int mm = (m>>C*(R/2))&((1<<C)-1);
		int mb = 0;
		for(int i=1; i<=mm; i<<=1)
			if(mm&i)
				mb++;
		if( ans<mb && match(m, b, R, C) )
			ans = mb;
	}
	os << ans << endl;
}

//-----------------------------------------------------------------------------
// >>Code Template<< (Multi-Thread Solver)

#undef cout
#include <windows.h>
#include <process.h>

static const int THREAD_NUM = 2;
volatile int     g_id;
int              g_nCase;
CRITICAL_SECTION g_cs;
vector<string>   g_output;

unsigned __stdcall thread_main( void* t_id ) {
	for(;;) {
		EnterCriticalSection(&g_cs);
		const int id = ++g_id;
		if(id>g_nCase) { LeaveCriticalSection(&g_cs); break; }
		cerr << setw(4) << id << " @ " << (int)t_id << " start" << endl;

		ostringstream ss;
		ss << "Case #" << id << ": ";
		case_main( ss );

		EnterCriticalSection(&g_cs);
		if(g_output.size()<id) g_output.resize(id);
		g_output[id-1] = ss.str();
		cerr << setw(4) << id << " @ " << (int)t_id << " end" << endl;
		LeaveCriticalSection(&g_cs);
	}
	return 0;
}

void END_OF_INPUT_FOR_THIS_TEST_CASE() { LeaveCriticalSection(&g_cs); }

int main() {
	cin >> g_nCase;

	InitializeCriticalSection(&g_cs);
	vector<HANDLE> thread;
	for(int i=0; i<THREAD_NUM; ++i)
		thread.push_back( (HANDLE)_beginthreadex(0, 0, &thread_main, (void*)i, 0, 0) );
	WaitForMultipleObjects( thread.size(), &thread[0], TRUE, INFINITE );
	DeleteCriticalSection(&g_cs);

	copy( g_output.begin(), g_output.end(), ostream_iterator<string>(cout) );
}
