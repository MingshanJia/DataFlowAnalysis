#include <iostream>
#include<algorithm>
using namespace std;
int main() {
  long long int t;
  cin>>t;
  int p=1;
  while(t--){
    long long int k;
    cin>>k;
    long long int a[k];
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    long long int res[k] ;
    long long int opt[k];
    sort(a,a+k);
    if(k%2==0){
        long long int temp = (k/2)-1;
        for(long long int i=0;i<k;i++){
            if(i<=((k/2)-1)){
                res[i] = i;
            }else{
                res[i] = temp;
                temp--;
            }
        }
        long long int i = 0;
        long long int j=k-1;
        long long int x = 0;
        while(i<j){
            opt[i++] = a[x++];
            opt[j--] = a[x++];
        }
       
    }else{
       long long int  temp = ((k-1)/2)-1;
        for(long long int i=0;i<k;i++){
            //cout<<i<<" "<<temp<<endl;
            if(i<=((k)/2)){
                res[i] = i;
            }else{
                res[i] = temp;
                //cout<<"hello"<<temp<<endl;
                temp--;
            }
        }
        long long int i = 0;
        long long int j=k-1;
        long long int x=0;
        while(i<=j){
            opt[i++] = a[x++];
            if(x<k-1){
            
                opt[j--] = a[x++];
            }
            
        }
        
    }
    long long int sum = 0;
    for(int i=0;i<k;i++){
        sum += (opt[i]-res[i])*(opt[i]-res[i]);
    }
    
    cout<<"Case #"<<p<<": ";
    cout<<sum<<endl;
    p++;
  }
  return 0;
}