#include <iostream>
#include <cmath>
using namespace std;

int testCase,testNum;

int N;

const string ans[31]={"000","000","027","143","751","935","607","903","991","335","047","943","471","055","447","463","991","095","607","263","151","855","527","743","351","135","407","903","791","135","647"};

int main()
{
  cin>>testNum;
  for (testCase=1;testCase<=testNum;++testCase)
  {
    cin>>N;
    cout<<"Case #"<<testCase<<": ";
    cout<<ans[N]<<endl;
  }
}
