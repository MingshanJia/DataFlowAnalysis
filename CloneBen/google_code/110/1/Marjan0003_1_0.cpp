#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>


using namespace std;
ifstream in("in2");



int main(){
	
	int casenum=0;
	in>>casenum;
	long long int k;
	long long int v;
	for (int c=0;c<casenum;c++){
		in>>k>>v;
		long long int numsol=0;
		long long int temp=0;
		long long int zero=0;
		/*if(k-2*v+1>=0)
			numsol=(k-2*v+1)*(3*v*v+3*v+1);*/
		
		for(long long int i=0;i<=k;i++){
			for(long long int j=max(zero,i-v);j<=min(k,i+v);j++){
				long long int ip=min(i,j);
				long long int jp=max(i,j);
				long long  int f=max(jp-v,zero);
				long long int e=min(k,ip+v);
				if(e>=f)
					temp+=(e-f+1);
				}
			}
			//cout<<numsol<<" "<<temp<<endl;
			numsol=numsol+temp;
			//cout<<numsol<<endl;
			
			/*temp=0;
			
			for(long long int i=k-v+1;i<=v-1;i++){
				for(long long int j=max(zero,i-v);j<=min(k,i+v);j++){
					long long int ip=min(i,j);
					long long int jp=max(i,j);
					long long  int f=max(jp-v,zero);
					long long int e=min(k,ip+v);
					if(e>=f)
						temp+=(e-f+1);
				
				}
			}
			//cout<<"temp"<<temp<<endl;
			numsol=numsol-temp;		*/
			cout<<"Case #"<<c+1<<": "<<numsol<<endl;
		}
		
		
		
	return 0;
	
}
