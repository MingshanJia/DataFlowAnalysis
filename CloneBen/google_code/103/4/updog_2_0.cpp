#include <myheading.h>

const int MAXN = 500000  ;
const int mod = 1000000007 ;


int n; 

int a[ MAXN+1 ];

void readin()
{
	int t[ 200 ] ;
	int m ;
	uint64 x, y, z ;
	
	cin>> n>>m>>x>>y>>z ;
	myfor( i, 0, m-1 ) cin>>t[i]; 

	myfor( i, 0, n-1 )
	{
		a[i+1] = t[ i%m ] ;
		t[i%m] = ( x * t[i%m] + y*(i+1) ) % z ;
	}
}

unsigned int f[ MAXN+1 ];

void work()
{
	memset( f, 0, sizeof(f) ) ;

	f[1] = 1 ;
	myfor( i, 2, n )
	{
		f[i] = 1 ;
		myfor( j, 1, i-1 )
			if( a[j]<a[i] ) f[i] = ( f[i] + f[j] ) % mod;
	}

	uint64 ans = 0;
	myfor( i, 1, n )
		ans = ( ans + f[i] ) % mod ;

	cout<<ans<<endl;
}


int main()
{
	//freopen( "d-large.in", "r", stdin ); freopen( "d-large.out", "w", stdout );
	freopen( "C-small-attempt0.in", "r", stdin );
	freopen( "C-small-attempt0.out", "w", stdout );
	//freopen( "in.txt", "r", stdin );
	//freopen( "out.txt", "w", stdout );

	int test ; cin>>test ;

	myfor( i, 1, test )
	{ 
		cout<<"Case #"<<i<<": ";

		readin() ;
		work() ;
		//cout<<ans<<endl;

	}

	if( !seekeof( cin ) ) cout<<("wrong")<<endl;

	fclose( stdin ); fclose( stdout );
	return 0;
}
