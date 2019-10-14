#include <stdio.h>
#include <memory.h>
int main()
{
    FILE *in=fopen("input.txt","r");
    FILE *out=fopen("output.txt","w");
    __int64 t, T, i, j, k;
    __int64 m, md, wd, v;
    
    fscanf(in,"%I64d",&T);
    for (t = 1; t <= T; t++) {
        fprintf(out,"Case #%I64d: ",t);
        fscanf(in,"%I64d%I64d%I64d",&m,&md,&wd);
        k = 0; v = 0;
        for (i = 1; i <= m; i++) {
            if (k+md-1 < wd) {
               v++;
               k += md-1;
            }
            else {
                 j = k+md-1-wd;
                 v += 1 + j/wd + 1;
                 k = j%wd;
            }
            if (++k >= wd) k -= wd;
            if (k == 0) {                  
               j = m/i;
               v *= j;
               i = i*j+1;
               break;
            }
        }
        for (; i <= m; i++) {
            if (k+md-1 < wd) {
               v++;
               k += md-1;
            }
            else {
                 j = k+md-1-wd;
                 v += 1 + j/wd + 1;
                 k = j%wd;
            }
            if (++k >= wd) k -= wd;
        }
        fprintf(out,"%I64d\n",v);
    }
    return 0;
}
