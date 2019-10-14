/* 2017.3.12 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>

FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");

double line[400];
int main()
{
	int T;
	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int N;
		fscanf(fin, "%d", &N);
		for (int i = 0; i < 2 * N; i++)
			fscanf(fin, "%lf", line + i);

		std::sort(line, line + 2 * N);

		double result = 1;
		for (int i = 0; i < N; i++)
		{
			result *= 1 - line[i] * line[2 * N - i - 1];
		}

		fprintf(fout, "Case #%d: %f\n", c_n, result);
		printf("Case #%d: %f\n", c_n, result);
	}
	return -0;
}
