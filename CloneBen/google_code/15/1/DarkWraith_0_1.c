#include <stdio.h>


int main (int argc, char* argv[]) {
    FILE* f;
    FILE* out;
    char outputFilename[] = "output.txt";
    out = fopen(outputFilename, "w");
    int T = 1;
    int N = 1;
    float avg;
    int i, j, k;


    f = fopen(argv[1], "r");
    fscanf(f, "%d", &T);
    for (i = 0; i < T; i++) {
        fscanf(f, "%d", &N);
        float H[N];
        for (j = 0; j < N; j++) {
            fscanf(f, "%f", &H[j]);
        }
        for (k = 1; k < (N-1); k++) {
            avg = (H[k-1] + H[k+1])/2;
            if (H[k] > avg) {
                H[k] = avg;
            }
        }
        fprintf(out, "Case #%d: ", i+1);
        fprintf(out, "%.6f \n", H[N-2]);
    }
    return (0);
}
