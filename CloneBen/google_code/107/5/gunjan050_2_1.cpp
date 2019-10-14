
#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0)
using namespace std;
int L;
string fans[5];
string A[5];
int cnt[5];
bool f(int i)
{
    if(cnt[i])
        return true;
    return false;
}
void func(int x,int y,int z)
{
    set<pair<int,int> > S;
    for(int i=0;i<L;i++){
        if(A[x][i] != A[y][i]){
            S.insert(make_pair(A[x][i]-'A',A[y][i]-'A'));
            break;
        }
    }
    for(int i=0;i<L;i++){
        if(A[y][i] != A[z][i]){
            int zz = A[z][i]-'A';
            int yy = A[y][i]-'A';
            if(S.find(make_pair(zz,yy)) != S.end()){
                return ;
            }
            else{
                cnt[y]++;
                return ;
            }
        }
    }

}
void pre()
{
    func(1,2,3);
    func(1,3,2);
    func(2,1,3);
    func(2,3,1);
    func(3,1,2);
    func(3,2,1);
}
int main()
{
    boost;
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++){
        cin>>L;
        for(int i=1;i<=3;i++){
            cnt[i] = 0;
        }
        for(int i=1;i<=3;i++){
            cin>>A[i];
        }
        pre();
        for(int i=1;i<=3;i++){
            if(f(i)){
                fans[i] = "YES";
            }
            else{
                fans[i] = "NO";
            }
        }
        cout<<"Case #"<<tt<<": ";
        for(int i=1;i<=3;i++){
            cout<<fans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}