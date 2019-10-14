#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double black_whole_coor[3][3];

int main(){
    
    FILE *err;
    err = fopen("stderr.txt", "w");
    
    int T;
    scanf("%d", &T);
    for(int currentT=1; currentT<=T; currentT++){
        fprintf(err, "T=%d\n", currentT);
        
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                scanf("%lf", &black_whole_coor[i][j]);
            
        double maxX = black_whole_coor[0][0];
        double minX = black_whole_coor[0][0];
        for(int i=0;i<3;i++){
            maxX = max(maxX, black_whole_coor[i][0]);
            minX = min(minX, black_whole_coor[i][0]);
        }
        double R=(maxX-minX)/6.0;
            
        printf("Case #%d: %.10lf\n", currentT, R);
    }
    fclose(err);
    
    return 0;
}
    