#include <bits/stdc++.h>
using namespace std;
int t;
int n;
vector<string> v;
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        cin>>n;
        cin.ignore();
        v.clear();
        string s;
        for(int i=0;i<n;i++){
            getline(cin,s);
            v.push_back(s);
        }
        int ans = 0;
        set<string> st;
        for(int i=0;i<n;i++){
            if(!st.empty() && v[i] < *st.rbegin()){
                ans+=1;
            }
            st.insert(v[i]);
        }

        cout<<"Case #"<<cs<<": ";
        cout<<ans<<endl;
    }
}
