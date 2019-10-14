#include<cstdio>
#include<algorithm>
#include<cstring>

void mul(double ans[][105], double a[][105], double b[][105], int n, int p, int m)
{
	for(int i = 1 ; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			ans[i][j] = 0.0;

			for(int k = 1; k <= p; k++)
			{
				// fprintf(stderr, "%d %d   %lf %lf %lf\n", i, j, ans[i][j], a[i][k], b[k][j]);

				ans[i][j] += a[i][k] * b[k][j];
			}

		}
	}	
}


int n, m, p;
int dist[105][105];

double mat[105][105];
double vec[105][105];

double temp[105][105];

void work(int case_id)
{
	scanf("%d%d%d", &n, &m, &p);
	memset(dist, 0x2f, sizeof dist);
	for(int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}

	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);

		dist[u][v] = std::min(dist[u][v], w);
		dist[v][u] = std::min(dist[v][u], w);
	}

	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}


	for(int i = 1; i <= n; i++)
	{
		dist[i][0] = 0;

		for(int j = 1; j <= n; j++)
		{
			dist[i][0] += dist[i][j];
		}
	}

	/*
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			fprintf(stderr, "%d ", dist[i][j]);
		}
		fprintf(stderr, "\n");
	}
	*/
	
	for(int i = 1; i <= n + 1; i++)
	{
		for(int j = 1; j <= n + 1; j++)
		{
			mat[i][j] = vec[i][j] = 0.0;
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			mat[i][j] = (i == j) ? 0 : (1.0 / (double)(n - 1));
		}
		mat[i][n + 1] = dist[i][0] / (double)(n - 1);
	}
	mat[n + 1][n + 1] = 1.0;
	vec[n + 1][1] = 1.0;

		
	
	
	/*

	for(int i = 1; i <= n + 1; i++)
	{
		for(int j = 1; j <= n + 1; j++)
		{
			fprintf(stderr, "%lf ", mat[i][j]);
		}
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "\n");

	for(int i = 1; i <= n + 1; i++)
	{
		for(int j = 1; j <= 1; j++)
		{
			fprintf(stderr, "%lf ", vec[i][j]);
		}
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "\n");
	*/


	/*
	for(int r = 1; r <= p; r++)
	{
		mul(temp, mat, vec, n + 1, n + 1, 1);

		for(int i = 1; i <= n + 1; i++)
		{
			for(int j = 1; j <= n + 1; j++)
			{
				vec[i][j] = temp[i][j];
			}
		}
	}
	*/

	for(;p > 0;)
	{
		if(p & 1)
		{
			mul(temp, mat, vec, n + 1, n + 1, 1);

			for(int i = 1; i <= n + 1; i++)
			{
				for(int j = 1; j <= n + 1; j++)
				{
					vec[i][j] = temp[i][j];
				}
			}
		}

		{
			p >>= 1;
			mul(temp, mat, mat, n + 1, n + 1, n + 1);

			for(int i = 1; i <= n + 1; i++)
			{
				for(int j = 1; j <= n + 1; j++)
				{
					mat[i][j] = temp[i][j];
				}
			}
		}

	}

	/*

	for(int i = 1; i <= n + 1; i++)
	{
		for(int j = 1; j <= 1; j++)
		{
			fprintf(stderr, "%lf ", temp[i][j]);
		}
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "\n");

	*/

	fprintf(stdout, "Case #%d: %lf\n", case_id, vec[1][1]);
}
	
int main()
{
	int total_case;
	scanf("%d", &total_case);
	
	for(int i = 1; i <= total_case; i++)
	{
		work(i);
	}



}