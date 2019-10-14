#include<stdio.h>
#include<algorithm>
int T, N, P, M, edge;
struct PERSON{
	int city;
	int v;
} person[200];

struct LIST{
	int s, e, len;
} list[300005];
struct SORTF{
	bool inline operator () (LIST a, LIST b){ return a.s < b.s; }
};

int sp[10005], vis[10005];
__int64 d[10005];

int heap[10005], hptr[10005], heapsize;

void swap(int s, int e)
{
	int tmp = heap[e];
	heap[e] = heap[s];
	heap[s] = tmp;
	hptr[heap[s]] = s;
	hptr[heap[e]] = e;
}
void up_heap(int s)
{
	while(s > 1){
		if(d[heap[s]] < d[heap[s>>1]])
			swap(s, s>>1);
		else break;
		s >>= 1;
	}
}
void down_heap()
{
	int next, s = 1;
	while(1){
		if((s << 1) > heapsize) break;
		if((s << 1) == heapsize) next = s << 1;
		else {
			if(d[heap[(s<<1) + 1]] > d[heap[s<<1]]) next = s << 1;
			else next = (s << 1) + 1;
		}

		if(d[heap[s]] > d[heap[next]]){
			swap(s, next);
			s = next;
		}
		else break;
	}
}
void dijkstra(int S)
{
	int i, now;
	for(i = 1; i <= N; i++){ vis[i] = 0; d[i] = 2147483647; }
	d[S] = 0;
	heapsize = 0; heap[++heapsize] = S; hptr[S] = 1;
	for(i = 1; i <= N; i++) if(i != S){
		heap[++heapsize] = i;
		hptr[i] = heapsize;
	}

	while(heapsize) {
		now = heap[1]; vis[now] = 1;

		swap(1, heapsize--);
		down_heap();

		for(i = sp[now]; list[i].s == now; i++)
		{
			if(vis[list[i].e] == 0 && d[list[i].e] > d[list[i].s] + list[i].len){
				d[list[i].e] = d[list[i].s] + list[i].len;
				up_heap(hptr[list[i].e]);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, i, j, D, L, l, k, chk;
	__int64 cur, min;
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		edge = 0;
		min = 2147483647; min *= min;
		scanf("%d %d %d", &N, &P, &M);
		for(i = 1; i <= P; i++) scanf("%d %d", &person[i].city, &person[i].v);
		for(i = 1; i <= M; i++)
		{
			scanf("%d %d %d", &D, &L, &l);
			for(j = 1; j < L; j++){
				scanf("%d", &k);
				++edge; list[edge].s = l; list[edge].e = k; list[edge].len = D;
				++edge; list[edge].e = l; list[edge].s = k; list[edge].len = D;
				l = k;
			}
		}
		std::sort(list+1, list+1+edge, SORTF());
		for(i = edge; i >= 1; i--) sp[list[i].s] = i;
		list[edge+1].s = -1;

		for(i = 1; i <= N; i++) // chosen city
		{
			dijkstra(i);
			cur = 0;
			chk = 0;

			for(j = 1; j <= P; j++){
				if(d[person[j].city] == 2147483647) chk = 1;
				if(cur < d[person[j].city] * person[j].v) cur = d[person[j].city] * person[j].v;
			}
			if(chk == 0 && cur < min) min = cur;
		}
		if(min > 2147483647) min = -1;
		printf("Case #%d: %I64d\n", t, min);
	}
}