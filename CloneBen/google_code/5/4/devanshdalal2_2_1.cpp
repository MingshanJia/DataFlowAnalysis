#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
#include<cassert>
#include<vector>
#define N 100001

typedef long long ll;

int main(){
	std::ios_base::sync_with_stdio(0);
	int t,n,ans;

	std::cin >> t;

	for(int j=1;j<=t;j++){
		std::cin >> n ;
		ans=0;
		// std::cerr << n << "\n";
		std::string name,maximum;
		while(maximum.size()==0)std::getline (std::cin,maximum);
		// std::cerr<< "maximum " << maximum << "ss "<< maximum.size() << "\n";
		for (int i = 1; i < n; ++i)
		{
			std::getline (std::cin,name);
			// std::cerr<< "name " << name << "ss "<< name.size() << "\n";
			int res=name.compare(maximum);
			assert(res!=0);
			if (res<0)
			{
				ans++;
			}else{
				maximum=name;
			}
		}
		
		std::cout << "Case #"<< j << ": " << ans << "\n" ;
	}



	return 0;
}