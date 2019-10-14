#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void solve(int time){
    int e,n;
    cin >> e >> n;
    vector<int> s(n);
    for(int i = 0;i < n;i++){
        cin >> s[i];
    }
    sort(s.begin(),s.end());
    int small = 0,large = n-1;
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(e > s[small]){
            ans++;
            e-=s[small];
            small++;
        }
        else if(ans > 0 && large-small>0){
            ans--;
            e+=s[large];
            large--;
        }
        else{
            break;
        }
    }
    cout << "Case #" << time << ": ";
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++){
        solve(i);
    }
}
