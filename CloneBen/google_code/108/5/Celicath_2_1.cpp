/* 2017.3.12 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>

FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");

char board[50][50];

int calc(int rc)
{
	int result = 0;
	for (int i = 0; i < rc; i++)
		for (int j = 0; j < rc; j++)
		{
			bool back = false;
			if (board[i][j] == 'O')
				back = true;
			else if (board[i][j] == '/')
				continue;

			for (int k = 0; k < 4; k++)
			{
				int dx = 1, dy = 0;
				if (k == 1) dy = 1;
				else if (k == 2)
					dx = 0, dy = 1;
				else if (k == 3) dy = -1;
				if (i + 2 * dx >= rc || j + 2 * dy >= rc || j + 2 * dy < 0)
					continue;

				if (board[i + dx][j + dy] == '/' &&
					(board[i + 2 * dx][j + 2 * dy] == (back ? 'I' : 'O')))
					result++;
			}
		}
	return result;
}

void init(int rc)
{
	for (int i = 0; i < rc; i++)
		for (int j = 0; j < rc; j++)
		{
			if (i % 4 == 0)
				board[i][j] = 'I';
			else if (i % 2 == 1)
				board[i][j] = '/';
			else board[i][j] = 'O';
		}
}
int table[50];

int main()
{
	int T;
	fscanf(fin, "%d", &T);

	for (int i = 1; i <= 15; i += 2)
	{
		init(i);
		table[i] = calc(i);
	}

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int D, N;
		fscanf(fin, "%d%d", &D, &N);

		int rc = 1;
		for (; rc < 15; rc += 2)
			if (table[rc] >= N) break;

		init(rc);
		int result = table[rc];

		// do a random algorithm, wish me luck
		for (int i = 0; ; i++)
		{
			if (result == N) break;
			int x = rand() % rc;
			int y = rand() % rc;
			char backup = board[x][y];
			board[x][y] = "I/O"[rand()%3];
			result = calc(rc);
			if (result < N) board[x][y] = backup;
		}

		fprintf(fout, "Case #%d:\n", c_n, result);
		printf("Case #%d:\n", c_n, result);

		for (int i = 0; i < rc; i++)
		{
			for (int j = 0; j < rc; j++)
			{
				fprintf(fout, "%c", board[i][j]);
				printf("%c", board[i][j]);
			}
			fprintf(fout, "\n");
			printf("\n");
		}
	}
	return -0;
}
