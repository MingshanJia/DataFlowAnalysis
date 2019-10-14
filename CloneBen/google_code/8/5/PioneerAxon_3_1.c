#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct board
{
	char ** b;
	int *c;
	int w, h;
}Board;

char map [7][4][4][4]=
{
	{
		{"    ","x   ","xx  "," x  "},
		{"    ","    "," xx ","xx  "},
		{"    ","x   ","xx  "," x  "},
		{"    ","    "," xx ","xx  "},
	},
	{
		{"    "," x  ","xx  ","x   "},
		{"    ","    ","xx  "," xx "},
		{"    "," x  ","xx  ","x   "},
		{"    ","    ","xx  "," xx "},
	},
	{
		{"    ","x   ","x   ","xx  "},
		{"    ","    ","  x ","xxx "},
		{"    ","xx  "," x  "," x  "},
		{"    ","    ","xxx ","x   "},
	},
	{
		{"    "," x  "," x  ","xx  "},
		{"    ","    ","xxx ","  x "},
		{"    ","xx  ","x   ","x   "},
		{"    ","    ","x   ","xxx "},
	},
	{
		{"    ","    ","xx  ","xx  "},
		{"    ","    ","xx  ","xx  "},
		{"    ","    ","xx  ","xx  "},
		{"    ","    ","xx  ","xx  "},
	},
	{
		{"x   ","x   ","x   ","x   "},
		{"    ","    ","    ","xxxx"},
		{"x   ","x   ","x   ","x   "},
		{"    ","    ","    ","xxxx"},
	},
	{
		{"    ","    "," x  ","xxx "},
		{"    "," x  ","xx  "," x  "},
		{"    ","    ","xxx "," x  "},
		{"    ","x   ","xx  ","x   "},
	},
};


Board* board_new (int w, int h)
{
	int l;
	Board* new = (Board*) calloc (1, sizeof (Board));
	assert (new);
	new->h = h;
	new->w = w;
	new->b = (char**) calloc (h, sizeof (char*));
	assert (new->b);
	new->c = (int*) calloc (h, sizeof (int));
	assert (new->c);
	for (l = 0; l < h; l++)
	{
		new->b [l] = (char*) calloc (w, sizeof (char));
		assert (new->b[l]);
	}
	return new;
}

void board_destroy (Board* b)
{
	int l;
	if (!b)
		return;
	if (b->c)
		free (b->c);
	if (b->b)
	{
		for (l = 0; l < b->h; l++)
		{
			free (b->b [l]);
		}
		free (b->b);
	}
	free (b);
}

int board_insert (Board* b, int t, int r, int x)
{
	int l1, l2, l3, found;
	int min_height = b->h;
	int ret = 1;
	for (l1 = 0; l1 < 4; l1++)
	{
		if (x + l1 >= b->w)
			break;
		found = 0;
		for (l2 = 3; l2 >= 0; l2--)
		{
			if (map [t - 1] [r][l2][l1] == 'x')
			{
				found = 1;
				break;
			}
		}
		if (!found)
			continue;
		l2 = 3 - l2;
		for (l3 = 0; l3 < b->h; l3++)
		{
			if (b->b [l3] [x + l1] == 'x')
			{
				break;
			}
		}
		l3 = l3 + l2;
		min_height = min_height < l3? min_height : l3;
	}
	min_height--;
	for (l1 = 0; l1 < 4; l1++)
	{
		if (x + l1 >= b->w)
			break;
		for (l2 = 3; l2 >= 0; l2--)
		{
			if (map [t - 1] [r][l2][l1] == 'x')
			{
				if (min_height - 3 + l2 < 0)
					ret = 0;
				if (min_height - 3 + l2 >= 0)
				{
					b->b [min_height - 3 + l2] [l1 + x] = 'x';
					b->c [min_height - 3 + l2]++;
				}
			}
		}
	}
	return ret;
}

void board_clear_any (Board* b)
{
	int l1, count = 0;
	for (l1 = b->h - 1; l1 >= count; l1--)
	{
		if (b->c [l1] == b->w)
		{
			free (b->b [l1]);
			count ++;
			l1++;
		}
		if (l1 -1 - count >= 0)
		{
			b->b [l1 - 1] = b->b [l1 - 1 - count];
			b->c [l1 - 1] = b->c [l1 - 1 - count];
		}
	}
	for (l1 = 0; l1 < count; l1++)
	{
		b->b [l1] = (char*) calloc (b->w, sizeof (char));
		assert (b->b [l1]);
		b->c [l1] = 0;
	}
}

void board_dump (Board* b)
{
	int l1, l2;
	for (l1 = 0; l1 < b->h; l1++)
	{
		for (l2 = 0; l2 < b->w; l2++)
		{
			if (b->b [l1] [l2] == 'x')
				printf ("x");
			else
				printf (".");
		}
		printf("\n");
	}
}

void play_board (int w, int h, int n, int c)
{
	int l, t, r, x;
	Board* b;
	b = board_new (w, h);
	printf ("Case #%d:\n", c + 1);
	for (l = 0; l < n; l++)
	{
		scanf ("%d %d %d", &t, &r, &x);
		if (board_insert (b, t, r, x) == 0)
		{
			printf ("Game Over!\n");
			l++;
			for (; l < n; l++)
				scanf ("%d %d %d", &t, &r, &x);
			return;
		}
		board_clear_any (b);
	}
	board_dump (b);
	board_destroy (b);
}

int main ()
{
	int t, w, n, h;
	int l;
	scanf ("%d", &t);
	for (l = 0; l < t; l++)
	{
		scanf ("%d %d %d", &w, &h, &n);
		play_board (w, h, n, l);
	}
	return EXIT_SUCCESS;
}
