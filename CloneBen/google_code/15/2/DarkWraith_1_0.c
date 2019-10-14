#include <stdio.h>
#include <math.h>


int main (int argc, char* argv[]) {
    FILE* f;
    FILE* out;
    char outputFilename[] = "output.txt";
    out = fopen(outputFilename, "w");
    int T = 1;
    int MF, MI, FF, FI;
    int MH, FH;
    float BH;
    int BHmin, BHmax, BFmin, BFmax, BImin, BImax;
    char S;
    int i;


    f = fopen(argv[1], "r");
    fscanf(f, "%d %*n", &T);
    for (i = 0; i < T; i++) {
        fscanf(f, "%c%d%*c%d%*c%*c%d%*c%d%*c%*c", &S, &MF, &MI, &FF, &FI);

        MH = MF*12 + MI;
        FH = FF*12 + FI;
        BH = MH + FH;
        if (S == 'B') {
            BH = BH + 5;
        }
        else {
            BH = BH - 5;
        }
        if (fmod(BH, 2)) {
            BH = BH/2;
            BHmin = BH - 3;
            BHmax = BH + 4;
        }
        else {
            BH = BH/2;
            BHmin = BH - 4;
            BHmax = BH + 4;
        }

        BFmin = BHmin/12;
        BImin = BHmin - 12*BFmin;

        BFmax = BHmax/12;
        BImax = BHmax - 12*BFmax;

        fprintf(out, "Case #%d: ", i+1);
        fprintf(out, "%d'%d\" to %d'%d\"\n", BFmin, BImin, BFmax, BImax);
    }
    return (0);
}
