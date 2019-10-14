#include<iostream>
#include<vector>
#include<string>
using namespace std;
long long arr[500000];
long long inp[500000];
long long soln[500000];
int main()
{ int T;
  cin>>T;
  for(int t=0;t<T;t++)
  { long long n,m,X,Y,Z;
    //cout<<"\n\n";
    cin>>n>>m>>X>>Y>>Z;
    for(int i=0;i<m;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
    { inp[i]=arr[i%m];
      //cout<<inp[i]<<" ";
      arr[i % m] = (X * arr[i % m] + Y * (i + 1)) % Z;
    }
    long long sum=0;
    for(int i=0;i<n;i++)
    { soln[i]=1;
      for(int j=0;j<i;j++)
      if(inp[j]<inp[i])
      { soln[i]+=soln[j];
        soln[i]=(soln[i]%1000000007);
      }
      sum=(sum+soln[i])%1000000007;
    }
    cout<<"Case #"<<t+1<<": "<<sum<<"\n";
  }
}
