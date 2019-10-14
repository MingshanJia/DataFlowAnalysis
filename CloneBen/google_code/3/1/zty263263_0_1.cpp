#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_OP_NUM 99999

char S[1000];

int map[500][500][500];
int current_len_min_op[500];

int main(){
    
    FILE *err;
    err = fopen("stderr.txt", "w");
    
    int T;
    scanf("%d", &T);
    for(int currentT=1; currentT<=T; currentT++){
        fprintf(err, "T=%d\n", currentT);
        
        scanf("%s", S);
        int N=strlen(S);
        
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                for(int k=0;k<=N;k++)
                    map[i][j][k]=MAX_OP_NUM;
        for(int i=0;i<=N;i++)
            current_len_min_op[i]=MAX_OP_NUM;
        
        map[0][0][0]=0;
        fprintf(err, "MAX %d\n", map[N][0][0]);
        
        for(int i=1;i<=N;i++){
            
            for(int j=1;j<i;j++){
                char inputedStr[1000], toInputStr[1000];
                strncpy(inputedStr, S, j);
                inputedStr[j]='\0';
                strncpy(toInputStr, S+j, i-j);
                toInputStr[i-j]='\0';
                if(strlen(toInputStr)<=1)
                    continue;

                char* matchedPos = strstr(inputedStr, toInputStr);
                if(matchedPos!=NULL){
                    int matched_idx = (int)(matchedPos-inputedStr);
                    fprintf(err, "matched %s %s %d\n", inputedStr, toInputStr, matched_idx);
                    fflush(err);
                    //have copied
                    map[i][matched_idx][i-j] = min(map[i][matched_idx][i-j], map[j][matched_idx][i-j]+1);
                    
                    //have not copied
                    map[i][matched_idx][i-j] = min(map[i][matched_idx][i-j], current_len_min_op[j]+2);
                }
                
            }
            for(int j=0;j<i;j++)
                for(int k=0;j+k<=i;k++){
                    map[i][j][k] = min(map[i][j][k], map[i-1][j][k]+1);
                    current_len_min_op[i] = min(current_len_min_op[i], map[i][j][k]);
                }
        }
        
        int op_num = MAX_OP_NUM;
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
                op_num=min(op_num, map[N][j][k]);
        
        
        printf("Case #%d: %d\n", currentT, op_num);
    }
    fclose(err);
    
    return 0;
}
    