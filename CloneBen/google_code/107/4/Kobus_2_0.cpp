#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
//#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 2123456
#define INF LLONG_MAX
#define MOD 999999599
#define cte 10002
#define MAX 21234

vector<int> are[1123];
string str[3];
int n;

bool run(string p,string s,string t,bool second){
    //cout<<"aa"<<endl;
    for(int i=0;i<100;i++)are[i].clear();
    bool ps=1,st=1;
    bool deu=1; 
    for(int i=0;i<n;i++){
        //cout<<p[i]<<" "<<s[i]<<" "<<t[i]<<endl;
        if(ps && st){
            if(p[i]==s[i]){
                if(s[i]!=t[i]){
                    are[s[i]-'A'].pb(t[i]-'A');
                    st=0;
                }
            }
            else{
                if(p[i]==t[i])deu=0;
                else if(s[i]==t[i]){
                    are[p[i]-'A'].pb(s[i]-'A');
                    ps=0;
                }
                else{
                    are[p[i]-'A'].pb(s[i]-'A');
                    are[s[i]-'A'].pb(t[i]-'A');
                    ps=0;
                    st=0;
                }
            }
        }
        else if(ps){
            if(p[i]!=s[i]){
                are[p[i]-'A'].pb(s[i]-'A');
                ps=0;
            }
        }
        else if(st){
            if(s[i]!=t[i]){
                are[s[i]-'A'].pb(t[i]-'A');
                st=0;
            }
        }
    }

    //cout<<"oie"<<endl;

    for(int i=0;i<100;i++){
        for(int j=0;j<are[i].size();j++){
            if(are[are[i][j]].size()!=0 && are[are[i][j]][0]==i)deu=0;
        }
    }

    if(second)return deu;
    if(deu||run(t,s,p,1))return 1;
    return 0;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int t;
    cin>>t;
    int num=1;
    while(t--){
        cout<<"Case #"<<num<<": ";
        num++;
        cin>>n;
        cin>>str[0]>>str[1]>>str[2];
        if(run(str[1],str[0],str[2],0))
            cout<<"YES ";
        else cout<<"NO ";

        if(run(str[0],str[1],str[2],0))
            cout<<"YES ";
        else cout<<"NO ";
        
        if(run(str[0],str[2],str[1],0))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }

    return 0;

}