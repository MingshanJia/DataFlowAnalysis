#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct board
{
	int** b;
	int n;
	int c;
} Board;

void board_dump (Board* b)
{
	int l1, l2;
	for (l1 = 0; l1 < b->n; l1++)
	{
		for (l2 = 0; l2 < b->n; l2++)
		{
			printf ("%4d ", b->b[l1][l2]);
		}
		printf ("\n");
	}
}

Board* board_new (int n)
{
	Board* b;
	int l;
	b = (Board*) calloc (1, sizeof (Board));
	assert (b);
	b->b = (int**) calloc (n, sizeof (int*));
	assert (b->b);
	for (l = 0; l < n; l++)
	{
		b->b [l] = (int*) calloc (n, sizeof (int));
		assert (b->b [l]);
	}
	b->n = n;
	return b;
}

void board_destroy (Board* b)
{
	if (!b)
		return;
	while (b->n--)
		free (b->b[b->n]);
	free (b->b);
	free (b);
}

void set_mine (Board* b, int x, int y)
{
	b->b [x][y] = -9;
	if (x - 1 >= 0)
	{
		if (y - 1 >= 0)
			b->b [x - 1] [y - 1]++;
		b->b [x - 1] [y - 0]++;
		if (y + 1 < b->n)
			b->b [x - 1] [y + 1]++;
	}
	if (x + 1 < b->n)
	{
		if (y - 1 >= 0)
			b->b [x + 1] [y - 1]++;
		b->b [x + 1] [y - 0]++;
		if (y + 1 < b->n)
			b->b [x + 1] [y + 1]++;
	}

	if (y - 1 >= 0)
		b->b [x - 0] [y - 1]++;
	if (y + 1 < b->n)
		b->b [x - 0] [y + 1]++;
}

void board_get (Board* b)
{
	int l1, l2;
	char inp;
	for (l1 = 0; l1 < b->n; l1++)
	{
		scanf ("%c", &inp);
		for (l2 = 0; l2 < b->n; l2++)
		{
			scanf ("%c", &inp);
			if (inp == '*')
			{
				set_mine (b, l1, l2);
			}
		}
	}
}

void board_flood_fill (Board* b, int x, int y, int* count)
{
	if (x >= 0 && x < b->n && y >= 0 && y < b->n)
	{
		if (b->b [x] [y] == 0)
		{
			b->b [x][y] = -1;
			*count = *count + 1;
			board_flood_fill (b, x - 1, y - 1, count);
			board_flood_fill (b, x - 1, y - 0, count);
			board_flood_fill (b, x - 1, y + 1, count);
			board_flood_fill (b, x - 0, y - 1, count);
			board_flood_fill (b, x - 0, y + 1, count);
			board_flood_fill (b, x + 1, y - 1, count);
			board_flood_fill (b, x + 1, y - 0, count);
			board_flood_fill (b, x + 1, y + 1, count);
		}
		else if (b->b [x] [y] > 0)
		{
			b->b [x] [y] = -1;
			*count = *count + 1;
		}
	}
}

int board_solve_zeros (Board* b)
{
	int count;
	int ret = 0;
	int l1, l2;
	for (l1 = 0; l1 < b->n; l1++)
	{
		for (l2 = 0; l2 < b->n; l2++)
		{
			count = 0;
			if (b->b [l1][l2] == 0)
				board_flood_fill (b, l1, l2, &count);
			if (count > 0)
				ret++;
		}
	}
	return ret;
}

int board_count_others (Board* b)
{
	int l1, l2, ret = 0;
	for (l1 = 0; l1 < b->n; l1++)
	{
		for (l2 = 0; l2 < b->n; l2++)
		{
			if (b->b [l1][l2] > 0)
			{
				b->b [l1][l2] = -1;
				ret++;
			}
		}
	}
	return ret;
}

void solve_board (int n, int c)
{
	Board* b;
	int ans = 0;
	b = board_new (n);
	board_get (b);
	ans += board_solve_zeros (b);
	ans += board_count_others (b);
	printf ("Case #%d: %d\n", c + 1, ans);
}

int main ()
{
	int t, l, n;
	scanf ("%d", &t);
	for (l = 0; l < t; l++)
	{
		scanf ("%d", &n);
		solve_board (n, l);
	}
	return EXIT_SUCCESS;
}
