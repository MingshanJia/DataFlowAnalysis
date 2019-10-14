#include <iostream>

#define DIM 110

using namespace std;

pair<int, int> v[DIM];
bool vis[DIM];

int main() {
    
    int testsCount;
    cin >> testsCount;
    
    for(int test = 1; test <= testsCount; test++) {
    
        int n, m;
        cin >> n >> m;
        
        for(int i = 1; i <= n; i++)
            cin >> v[i].first >> v[i].second;
            
        int solution = 0;
            
        for(int i = 1; i <= m; i++) {
            
            for(int j = 1; j <= m; j++) 
                vis[j] = false;
            
            int crt = 0;
            
            for(int j = 1; j <= n; j++) {
                
                if(v[j].first == i && !vis[v[j].second]) {
                    
                    vis[v[j].second] = true;
                    crt++;
                    
                }
                
                if(v[j].second == i && !vis[v[j].first]) {
                    
                    vis[v[j].first] = true;
                    crt++;
                    
                }
                
            }
            
            solution = max(solution, crt);
            
        }
        
        cout << "Case #" << test << ": " << solution << "\n";
        
    }
    
    
    return 0;
    
}