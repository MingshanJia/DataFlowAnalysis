#pragma warning(disable:4996)

#include<stdio.h>
#include<vector>

#define Swap(aa,bb) {cc=aa;aa=bb;bb=cc;}

int cc;

using namespace std;

int T, l0;

char a[111][111][111];
int b[111][111][111];
int counter1, counter2;
int n, m, k;

int q1[111111];
int q2[111111];
int qhead, qtail;


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void Sort(int l, int r)
{
	if(l < r)
	{
		int i = l-1, j = r+1;
		int mid1 = q1[(l+r) >> 1];
		int mid2 = q2[(l+r) >> 1];

		while(1)
		{
			do
			{
				i++;
			} while(q1[i] < mid1 || (q1[i] == mid1 && q2[i] < mid2));
			do
			{
				j--;
			} while(q1[j] > mid1 || (q1[j] == mid1 && q2[j] > mid2));
			if(i >= j) break;
			Swap(q1[i], q1[j]);
			Swap(q2[i], q2[j]);
		}
	}
}

#define MAXV 100000
vector< vector<int> > AL;
int Mat1[MAXV], Mat2[MAXV], q[MAXV], head, tail, Back[MAXV], TM;
struct MM
{
	int V1, V2;
	MM(int v1, int v2) : V1(v1), V2(v2)
	{
		int l1;
		AL.clear(); AL.resize(V1);
		for(l1=0;l1<V1;l1++) Mat1[l1] = -1;
		for(l1=0;l1<V2;l1++) Mat2[l1] = -1;
		TM = 0;
	}
	void Add(int t1, int t2)
	{
		AL[t1].push_back(t2);
		if(Mat1[t1] == -1 && Mat2[t2] == -1)
		{
			Mat1[t1] = t2; Mat2[t2] = t1; TM++;
		}
	}
	int Go()
	{
		int l1, l2, t1, t2;
		while(1)
		{
			head = tail = 0;
			for(l1=0;l1<V1;l1++)
			{
				if(Mat1[l1] == -1) q[tail++] = l1;
				Back[l1] = -1;
			}
			while(head<tail)
			{
				l1 = q[head++];
				for(l2=0;l2<AL[l1].size();l2++)
				{
					if(Mat2[AL[l1][l2]] == -1) goto maki;
					else if(Back[Mat2[AL[l1][l2]]] == -1)
					{
						Back[Mat2[AL[l1][l2]]] = l1;
						q[tail++] = Mat2[AL[l1][l2]];
					}
				}
			}
			break; maki: l2 = AL[l1][l2];
			while(1)
			{
				t1 = Back[l1]; t2 = Mat1[l1];
				Mat1[l1] = l2; Mat2[l2] = l1;
				l1 = t1; l2 = t2;
				if(l1 == -1) break;
			}
			TM++;
		}
		return TM;
	}
};

int main(void)
{
	int l1, l2, l3, l4, t1, t2, v1, v2;
	//freopen("input.txt","r",stdin);

	freopen("c1.in","r",stdin);
	freopen("c1.out","w",stdout);

	scanf("%d",&T);
	for(l0=1;l0<=T;l0++)
	{
		scanf("%d %d %d",&n,&m,&k);

		for(l1=0;l1<k;l1++)
		{
			for(l2=0;l2<n;l2++)
			{
				scanf("%s",a[l1][l2]);
				for(l3=0;l3<m;l3++)
				{
					b[l1][l2][l3] = 0;
				}
			}
		}

		counter1 = counter2 = 0;
		int the_room;

		for(l1=0;l1<k;l1++)
		{
			for(l2=0;l2<n;l2++)
			{
				for(l3=0;l3<m;l3++)
				{
					if(a[l1][l2][l3] == '#') continue;
					if(b[l1][l2][l3]) continue;

					if(l1 & 1)
					{
						++counter2;
						the_room = counter2;
					}
					else
					{
						++counter1;
						the_room = counter1;
					}

					b[l1][l2][l3] = the_room;
					q1[0] = l2;
					q2[0] = l3;
					qhead = 0;
					qtail = 1;
					while(qhead < qtail)
					{
						t1 = q1[qhead];
						t2 = q2[qhead];
						qhead++;

						for(l4=0;l4<4;l4++)
						{
							v1 = t1 + dx[l4];
							if(v1 < 0 || v1 >= n) continue;
							v2 = t2 + dy[l4];
							if(v2 < 0 || v2 >= m) continue;
							if(a[l1][v1][v2] == '#') continue;
							if(b[l1][v1][v2]) continue;

							b[l1][v1][v2] = the_room;
							q1[qtail] = v1;
							q2[qtail] = v2;
							qtail++;
						}
					}
				}
			}
		}

		MM mm = MM(counter1, counter2);

		qtail = 0;

		for(l1=0;l1+1<k;l1++)
		{
			if(l1 & 1)
			{
				for(l2=0;l2<n;l2++) for(l3=0;l3<m;l3++)
				{
					if(b[l1][l2][l3] == 0) continue;
					if(b[l1+1][l2][l3] == 0) continue;

					q1[qtail] = b[l1+1][l2][l3];
					q2[qtail] = b[l1][l2][l3];
					qtail++;
				}
			}
			else
			{
				for(l2=0;l2<n;l2++) for(l3=0;l3<m;l3++)
				{
					if(b[l1][l2][l3] == 0) continue;
					if(b[l1+1][l2][l3] == 0) continue;

					q1[qtail] = b[l1][l2][l3];
					q2[qtail] = b[l1+1][l2][l3];
					qtail++;
				}
			}
		}

		Sort(0, qtail-1);

		for(l1=0;l1<qtail;l1++)
		{
			if(l1 > 0)
			{
				if(q1[l1] == q1[l1-1] && q2[l1] == q2[l1-1]) continue;
			}

			mm.Add(q1[l1] - 1, q2[l1] - 1);
			//printf("%d %d\n",q1[l1],q2[l1]);
		}

		printf("Case #%d: %d\n",l0,counter1+counter2-mm.Go());
	}

	return 0;
}