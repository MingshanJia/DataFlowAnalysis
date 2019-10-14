#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include<math.h>
#include<set>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <algorithm>
#include <vector>
#include <math.h> 


using namespace std;

int main(){
	int T,D,N;

	cin>>T;
	for (int tnum=0;tnum<T;tnum++){
		cout<<"Case #"<<(tnum+1)<<":"<<endl;
		cin>>D>>N;
		N=287-N;

		int rem3=floor(N/3);
		if (rem3>91)
			rem3=91;
		int rem1=N-(rem3*3);
		if (rem1>14)
			cout<<"errrror"<<endl;
		
		for (int i=1;i<=15;i++){
			if(i%2==1){
				if(i%4==1){
					for(int j=1;j<=15;j++)
						cout<<"O";
					cout<<endl;
				}
				if(i%4==3){
					for(int j=1;j<=15;j++)
						cout<<"I";
					cout<<endl;
				}	

			}
			if(i%2==0){

				if(rem1>0){
					cout<<"O";
					rem1--;
				}
				else{
					cout<<"/";
				}

				for(int j=2;j<=14;j++){
					if(rem3>0){
						cout<<"O";
						rem3--;
					}
					else{
						cout<<"/";
					}
				}

				if(rem1>0){
					cout<<"O";
					rem1--;
				}
				else{
					cout<<"/";
				}
				cout<<endl;
			}

			
		}



		
		
	}
	
	return 0;
}