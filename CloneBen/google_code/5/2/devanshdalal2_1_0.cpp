#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
#include<cassert>
#include<vector>
#include<math.h>
#include <iomanip>
#include<cstring>

#define _USE_MATH_DEFINES
#define G 9.8
#define Degree(rad) 180.0*rad/M_PI
typedef long long ll;

int main(){
	std::ios_base::sync_with_stdio(0);
	int t;
	double V,D;

	std::cin >> t;

	for (int j = 1; j <=t; ++j)
	{
		std::cin >> V >> D;
		V=V*V;

		// std::cerr << D*G/V << "\n";
		// std::cerr << "a " << asin(D*G/V)/2.0 << "\n";
		// std::cout.setf( std::ios::fixed, std:: ios::floatfield );
		std::cout << "Case #" << j << ": "  << std::fixed << std::setprecision(10) <<  Degree( asin(D*G/V)/2.0 ) << "\n";
		

	}

	

	return 0;
}