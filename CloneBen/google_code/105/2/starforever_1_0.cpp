#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int testNum,testCase;

int N,M;

bool malt[2000];

vector<pair<int,int> > cust[2000];

int adjust ()
{
  bool allsatisfy=true;
  for (int i=0;i<M;++i)
  {
    bool satisfy=false;
    for (int j=0;j<int(cust[i].size());++j)
      if (cust[i][j].second==0 && !malt[cust[i][j].first] || cust[i][j].second==1 && malt[cust[i][j].first])
        satisfy=true;
//     cout<<"satisfy: "<<i<<' '<<satisfy<<endl;
    if (!satisfy)
    {
      allsatisfy=false;
      int j;
      for (j=0;j<int(cust[i].size()) && cust[i][j].second!=1;++j);
      if (j>=int(cust[i].size()))
        return -1;
      malt[cust[i][j].first]=true;
    }
  }
  if (allsatisfy)
    return 1;
  else
    return 0;
}

int main()
{
  cin>>testNum;
  for (testCase=1;testCase<=testNum;++testCase)
  {
    cin>>N>>M;
    for (int i=0;i<M;++i)
      cust[i].clear();
    for (int i=0;i<M;++i)
    {
      int tt;
      cin>>tt;
      for (int j=0;j<tt;++j)
      {
        int a,b;
        cin>>a>>b;
        --a;
        cust[i].push_back(make_pair(a,b));
      }
    }
    memset(malt,false,sizeof(malt));
    int rr;
    while (true)
    {
      rr=adjust();
      if (rr==-1 || rr==1)
        break;
    }
    cout<<"Case #"<<testCase<<":";
    if (rr==-1)
      cout<<" IMPOSSIBLE";
    else
      for (int i=0;i<N;++i)
        cout<<" "<<malt[i];
    cout<<endl;
  }
}
