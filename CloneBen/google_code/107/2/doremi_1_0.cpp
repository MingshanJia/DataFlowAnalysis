#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef pair<ll,ll> pll;

ll cnt[MAX+10];
vector<pll>v;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    ll t,ti,i,j,k,l,ch;
    scanf("%lld",&t);
    for(ti=1; ti<=t; ti++)
    {
        v.clear();
        memset(cnt,0,sizeof(cnt));
        ch=0;
        scanf("%lld",&l);
        for(i=0; i<l; i++)
        {
            scanf("%lld %lld",&j,&k);
            v.push_back({k,j});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        ch=v[0].second;
      //  dbg(ch);
        cnt[v[0].first]+=v[0].second*v[0].first;
        ll curr=v[0].first;
        ll lft;
        for(i=1; i<v.size(); i++)
        {
            lft=v[i].second;
            cnt[v[i].first]+=v[i].second*v[i].first;
            while(curr>v[i].first)
            {
                if(lft<=cnt[curr])
                {
                    cnt[curr]-=lft;
                    lft=0;
                    break;
                }
                else
                {
                    lft-=cnt[curr];
                    cnt[curr]=0;
                    curr--;
                }
            }
            ch+=lft;
        }
        printf("Case #%lld: %lld\n",ti,max(v[0].first+1,ch));
       // dbg(ch);
    }
    return 0;
}
