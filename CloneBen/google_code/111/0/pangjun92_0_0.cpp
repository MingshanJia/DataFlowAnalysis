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
int main(){
    int num_cases;
    cin>>num_cases;
    string tmp;
    getline(cin,tmp);
    for(int line=0;line<num_cases;line++){
        string in;
        getline(cin,in);
        int l=in.size();
        cout<<"Case #"<<(line+1)<<":"<<endl;
        cout<<"+";
        for(int i=0;i<l+2;i++){
            cout<<"-";
        }
        cout<<"+";
        cout<<endl;
        cout<<"| "<<in<<" |"<<endl;
        cout<<"+";
        for(int i=0;i<l+2;i++){
            cout<<"-";
        }
        cout<<"+"<<endl;
    }
    return 0;
}
