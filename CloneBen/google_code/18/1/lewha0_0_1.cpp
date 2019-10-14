#pragma warning(disable:4996)

#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int T, l0;

long long N;
long long me[3];
long long you[3];
long long a[3][3];
long long b[3][3];
int c[3];
long long ret;
int flag;
const int n = 3;

vector< pair<int, int> > order;


int Feasible(void)
{
	int l1, l2;

	for(l1=0;l1<n;l1++) for(l2=0;l2<n;l2++) if(b[l1][l2] < 0) return 0;

	if(b[0][0] + b[0][1] + b[0][2] != me[0]) return 0;
	if(b[1][0] + b[1][1] + b[1][2] != me[1]) return 0;
	if(b[2][0] + b[2][1] + b[2][2] != me[2]) return 0;

	if(b[0][0] + b[1][0] + b[2][0] != you[0]) return 0;
	if(b[0][1] + b[1][1] + b[2][1] != you[1]) return 0;
	if(b[0][2] + b[1][2] + b[2][2] != you[2]) return 0;

	return 1;
}

void Go(void)
{
	int l1, l2, l3, l4;

	long long curr = 0;
	while(1)
	{
		if(Feasible())
		{
			break;
		}

		for(l1=0;l1<n;l1++)
		{
			if(b[0][l1] + b[1][l1] + b[2][l1] < you[l1]) break;
		}
		for(l2=0;l2<n;l2++)
		{
			if(b[0][l2] + b[1][l2] + b[2][l2] > you[l2]) break;
		}

		if((l1 == n && l2 == n) || (l1 == l2))
		{
			fprintf(stderr,"menboooooooooon\n");
		}


		long long amount1 = you[l1] - (b[0][l1] + b[1][l1] + b[2][l1]);
		long long amount2 = (b[0][l2] + b[1][l2] + b[2][l2]) - you[l2];

		long long amount = amount1;
		if(amount < amount2) amount = amount2;


		c[0] = c[1] = c[2] = 0;

		for(l3=0;l3<n;l3++)
		{
			int idx = -1;
			for(l4=0;l4<n;l4++)
			{
				if(c[l4]) continue;
				if(idx == -1) idx = l4;
				if(a[l4][l1] - a[l4][l2] > a[idx][l1] - a[idx][l2])
				{
					idx = l4;
				}
			}
			c[idx] = 1;

			long long thistime = amount;
			if(thistime > b[idx][l2])
			{
				thistime = b[idx][l2];
			}

			b[idx][l2] -= thistime;
			b[idx][l1] += thistime;

			amount -= thistime;
		}
	}

	while(1)
	{
		long long amount;
		int yuki = 0;
		long long gain = 0;
		int v1, v2, v3, v4;
		for(l1=0;l1<n;l1++)
		{
			for(l2=0;l2<n;l2++)
			{
				if(l1 == l2) continue;
				for(l3=0;l3<n;l3++)
				{
					for(l4=0;l4<n;l4++)
					{
						if(l3 == l4) continue;

						if(a[l1][l3] - a[l1][l4] - a[l2][l3] + a[l2][l4] > 0)
						{
							amount = b[l1][l4];
							if(amount > b[l2][l3]) amount = b[l2][l3];
							if(amount == 0) continue;

							if(gain < a[l1][l3] - a[l1][l4] - a[l2][l3] + a[l2][l4])
							{
								gain = a[l1][l3] - a[l1][l4] - a[l2][l3] + a[l2][l4];
								v1 = l1;
								v2 = l2;
								v3 = l3;
								v4 = l4;
							}

							yuki = 1;
						}
					}
				}
			}
		}

		if(gain == 0) break;

		amount = b[v1][v4];
		if(amount > b[v2][v3]) amount = b[v2][v3];

		b[v1][v3] += amount;
		b[v1][v4] -= amount;
		b[v2][v3] -= amount;
		b[v2][v4] += amount;

	}


	curr = 0;
	for(l1=0;l1<n;l1++) for(l2=0;l2<n;l2++)
	{
		curr += a[l1][l2] * b[l1][l2];
	}

	if(flag == 0 || curr > ret)
	{
		flag = 1;
		ret = curr;
	}
}

int main(void)
{
	int l1, l2;

	int t1, t2, t3, t4, t5, t6;

	//ifstream fin("input.txt"); ofstream fout("output.txt");

	ifstream fin("a2.in"); ofstream fout("a2.out");


	fin >> T;

	for(l0=1;l0<=T;l0++)
	{
		fin >> N;
		for(l1=0;l1<n;l1++) fin >> me[l1];
		for(l1=0;l1<n;l1++) fin >> you[l1];

		for(l1=0;l1<n;l1++) for(l2=0;l2<n;l2++) fin >> a[l1][l2];

		flag = 0;

		for(t2=0;t2<3;t2++)
		{
			for(t4=0;t4<3;t4++)
			{
				for(t6=0;t6<3;t6++)
				{

					for(l1=0;l1<n;l1++) for(l2=0;l2<n;l2++) b[l1][l2] = 0;
					b[0][t2] = me[0]; b[1][t4] = me[1]; b[2][t6] = me[2];
					Go();
				}
			}
		}

		order.clear();
		for(l1=0;l1<n;l1++) for(l2=0;l2<n;l2++)
		{
			order.push_back( make_pair(l1, l2) );
		}

		do
		{
			long long me_left[3];
			long long you_left[3];
			for(l1=0;l1<n;l1++)
			{
				me_left[l1] = me[l1];
				you_left[l1] = you[l1];
			}
			for(l1=0;l1<n;l1++) for(l2=0;l2<n;l2++) b[l1][l2] = 0;
			for(l1=0;l1<order.size();l1++)
			{
				t1 = order[l1].first;
				t2 = order[l1].second;

				long long amount = me_left[t1];
				if(amount > you_left[t2]) amount = you_left[t2];

				b[t1][t2] = amount;

				me_left[t1] -= amount;
				you_left[t2] -= amount;
			}
			Go();
		}
		while(next_permutation(order.begin(), order.end()));

		cout << "Case #" << l0 << ": " << ret << endl;
		fout << "Case #" << l0 << ": " << ret << endl;

		cout.flush();
		fout.flush();
	}
}