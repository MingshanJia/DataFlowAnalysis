#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<cmath>
using namespace std;
vector<int> ntable(vector<int> &v){
    int m=0;
    for(int i=0;i<v.size();i++){
        if(v[i]<v[m])m=i;
    }
    vector<int> nv(v.begin()+m,v.end());
    for(int i=0;i<m;i++)nv.push_back(v[i]);
    if(v.size()==1)return nv;
    if(nv[1]>nv[v.size()-1]){
        reverse(nv.begin()+1,nv.end());
    }
    return nv;

    
}
vector<vector<int> > normalize(vector<int>&v,int N,int K){
    vector<vector<int> > r;
    int left=N%K;
    int start=0;
    for(int i=0;i<K;i++){
        vector<int> tmp;
        int pp=N/K+1*(i<left);
        for(int j=0;j<pp;j++){
            tmp.push_back(v[start++]);
        }
        r.push_back(tmp);
    }
    for(int i=0;i<r.size();i++){
        r[i]=ntable(r[i]);
    }
    sort(r.begin(),r.end());
    return r;
    
}
int seating(int N, int K){
    vector<int> v;
    for(int i=0;i<N;i++){
        v.push_back(i);
    }
    set<vector<vector<int> > > ss;
    
    while(1){
        ss.insert(normalize(v,N,K));
        if(!next_permutation(v.begin(),v.end()))break;
        
    }
    return ss.size();
}
int main(){
    int num_cases;
    cin>>num_cases;
    for(int line=0;line<num_cases;line++){
        int N,K;
        cin >>N;
        cin>>K;
        int r=seating(N,K);
        cout<<"Case #"<<(line+1)<<":";
        cout<<" "<<r<<endl;
    }
    return 0;
}
