#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int testCase;
int testNum;

int N;

long long s1[800],s2[800];

int main()
{
  cin>>testNum;
  for (testCase=1;testCase<=testNum;++testCase)
  {
    cin>>N;
    for (int i=0;i<N;++i)
      cin>>s1[i];
    for (int i=0;i<N;++i)
      cin>>s2[i];
    sort(s1,s1+N);
    sort(s2,s2+N,greater<long long>());
    long long ans=0;
    for (int i=0;i<N;++i)
      ans+=s1[i]*s2[i];
    cout<<"Case #"<<testCase<<": "<<ans<<endl;
  }
}
