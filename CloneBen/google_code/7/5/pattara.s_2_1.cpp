#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
void solve(){
    int n;
    cin >> n ;
    map<string,string> nxt;
    map<string,int> deg;
    set<string> st;
    set<string> blk;
    for(int i = 0 ; i < n ;++ i ){
        string s,e;
        cin >>s >> e;
        if(blk.find(s)==blk.end())
        st.insert(s);
        nxt[s]=e;
        deg[e]++;
        st.erase(e);
        blk.insert(e);
    }
    string cur = *st.begin();
    for(int i = 0 ; i < n ; ++ i ){
        printf(" %s-%s",cur.c_str(),nxt[cur].c_str());
        cur=nxt[cur];
    }
    printf("\n");
}

int main(){
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    //printf("T=%d\n",T);
    //return 0;
    for(int i = 1 ; i<=T; ++ i ){
        printf("Case #%d:",i);
        solve();
    }
}
