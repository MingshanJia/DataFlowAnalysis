#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#define ll long long
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
using namespace std;
#define MN 50
#define NO 29
#define FIN 30
int U, N, A, B;
set<vector<int> > s, ss;
int d[MN], a[MN], b[MN];
int go[MN][5];
void upd(int p, int v1, int v2, int v3, int v4, int v5) {
	go[p][0] = v1; 
	go[p][1] = v2;
	go[p][2] = v3;
	go[p][3] = v4;
	go[p][4] = v5;
}
int help(int t, int p)
{return p >= 3 ? t : 1-t;}
bool check(vector<int> p)
{
	vector<int> q;
	if (p.size() == 0) {
		q = p; q.push_back(0);
		if (check(q)) return 1;
		q = p; q.push_back(1);
		if (check(q)) return 1;
	}
	else if (p.size() == 1) {
		if (0 < A) {
			q = p; q.push_back(a[0]);
			if (check(q)) return 1;
		}
		else {
			q = p; q.push_back(NO);
			if (check(q)) return 1;
			q = p; q.push_back(FIN);
			if (check(q)) return 1;
		}
	}
	else if (p.size() == 2) {
		if (1 < A) {
			q = p; q.push_back(a[1]);
			if (check(q)) return 1;
		}
		else {
			q = p; q.push_back(NO);
			if (check(q)) return 1;
			q = p; q.push_back(FIN);
			if (check(q)) return 1;
		}
	}
	else if (p.size() == 3) {
		if (0 < B) {
			q = p; q.push_back(b[0]);
			if (check(q)) return 1;
		}
		else {
			q = p; q.push_back(NO);
			if (check(q)) return 1;
			q = p; q.push_back(FIN);
			if (check(q)) return 1;
		}
	}
	else if (p.size() == 4) {
		if (1 < B) {
			q = p; q.push_back(b[1]);
			if (check(q)) return 1;
		}
		else {
			q = p; q.push_back(NO);
			if (check(q)) return 1;
			q = p; q.push_back(FIN);
			if (check(q)) return 1;
		}
	}
	else {
		if (s.find(p) != s.end()) return 1;
	}
	return 0;
}
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j, k;
	char str[8];
	vector<int> p, q;
	set<vector<int> >::iterator it;

	upd(0,FIN,FIN,FIN,FIN,FIN);
	upd(1,2,3,4,5,6);
	upd(2,3,4,5,6,7);
	upd(3,4,5,6,7,8);
	upd(4,5,6,7,8,9);
	upd(5,20,21,22,23,24);
	upd(6,7,8,9,10,11);
	upd(7,8,9,10,11,12);
	upd(8,9,10,11,12,13);
	upd(9,10,11,12,13,14);
	upd(10,25,26,22,27,28);
	upd(11,12,13,14,15,16);
	upd(12,13,14,15,16,17);
	upd(13,14,15,16,17,18);
	upd(14,15,16,17,18,19);
	upd(15,16,17,18,19,0);
	upd(16,17,18,19,0,FIN);
	upd(17,18,19,0,FIN,FIN);
	upd(18,19,0,FIN,FIN,FIN);
	upd(19,0,FIN,FIN,FIN,FIN);
	upd(20,21,22,23,24,15);
	upd(21,22,23,24,15,16);
	upd(22,27,28,0,FIN,FIN);
	upd(23,24,15,16,17,18);
	upd(24,15,16,17,18,19);
	upd(25,26,22,27,28,0);
	upd(26,22,27,28,0,FIN);
	upd(27,28,0,FIN,FIN,FIN);
	upd(28,0,FIN,FIN,FIN,FIN);
	upd(NO,1,2,3,4,5);
	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("%d\n",t);
		fprintf(out,"Case #%d: ",t);
		fscanf(in,"%d%d%d%d",&U,&N,&A,&B);
		for (i = 0; i < N; i++) {
			fscanf(in,"%s",str);
			if (str[0] == 'D') d[i] = 0;
			else if (str[0] == 'G' && str[1] == 'a') d[i] = 1;
			else if (str[0] == 'G') d[i] = 2;
			else if (str[0] == 'Y') d[i] = 3;
			else if (str[0] == 'M') d[i] = 4;
			else printf("NO!!!!!!!!\n");
		}
		for (i = 0; i < A; i++)
			fscanf(in,"%d",&a[i]);
		for (i = 0; i < B; i++)
			fscanf(in,"%d",&b[i]);
		s.clear();
		p.clear(); p.push_back(0);
		for (i = 0; i < U; i++) p.push_back(NO);
		for (; i < 2; i++) p.push_back(FIN);
		for (i = 0; i < U; i++) p.push_back(NO);
		for (; i < 2; i++) p.push_back(FIN);
		s.insert(p);
		for (i = 0; i < N; i++) {
			ss.clear();
			for (it = s.begin(); it != s.end(); it++) {
				p = (*it);
				if (p[0] == 0) {
					if (p[3] == FIN && p[4] == FIN) continue; // game is over					
					if (p[1] == p[2] && p[1] != NO) { // dummy
						j = p[1];
						if (j != FIN) {
							// let's move
							j = go[j][d[i]];
							if (j != FIN) {
								// checking eat
								if (p[3] == p[4] && p[3] == j) { // double eat
									q = p;
									q[1] = q[2] = j; q[3] = q[4] = NO;
									ss.insert(q);
								}
								else if (p[3] == j) { // single eat
									q = p;
									q[1] = q[2] = j; q[3] = NO;
									ss.insert(q);
								}
								else if (p[4] == j) { // single eat
									q = p;
									q[1] = q[2] = j; q[4] = NO;
									ss.insert(q);
								}
								else {
									q = p;
									q[0] = help(p[0],d[i]); q[1] = q[2] = j;
									ss.insert(q);
								}
							}
							else { // cannot eat
								q = p;
								q[0] = help(p[0],d[i]); q[1] = q[2] = j;
								ss.insert(q);
							}
						}
						else ; // cannot move
					}
					else {
						// p[1] move
						j = p[1];
						if (j != FIN) {
							// let's move
							j = go[j][d[i]];
							if (j != FIN) {
								// checking eat
								if (p[3] == p[4] && p[3] == j) { // double eat
									q = p;
									q[1] = j; q[3] = q[4] = NO;
									ss.insert(q);
								}
								else if (p[3] == j) { // single eat
									q = p;
									q[1] = j; q[3] = NO;
									ss.insert(q);
								}
								else if (p[4] == j) { // single eat
									q = p;
									q[1] = j; q[4] = NO;
									ss.insert(q);
								}
								else {
									q = p;
									q[0] = help(p[0],d[i]); q[1] = j;
									ss.insert(q);
								}
							}
							else { // cannot eat
								q = p;
								q[0] = help(p[0],d[i]); q[1] = j;
								ss.insert(q);
							}
						}
						else ; // cannot move

						// p[2] move
						j = p[2];
						if (j != FIN) {
							// let's move
							j = go[j][d[i]];
							if (j != FIN) {
								// checking eat
								if (p[3] == p[4] && p[3] == j) { // double eat
									q = p;
									q[2] = j; q[3] = q[4] = NO;
									ss.insert(q);
								}
								else if (p[3] == j) { // single eat
									q = p;
									q[2] = j; q[3] = NO;
									ss.insert(q);
								}
								else if (p[4] == j) { // single eat
									q = p;
									q[2] = j; q[4] = NO;
									ss.insert(q);
								}
								else {
									q = p;
									q[0] = help(p[0],d[i]); q[2] = j;
									ss.insert(q);
								}
							}
							else { // cannot eat
								q = p;
								q[0] = help(p[0],d[i]); q[2] = j;
								ss.insert(q);
							}
						}
						else ; // cannot move
					}
				}
				else {
					if (p[0] == FIN && p[1] == FIN) continue; // game is over					
					if (p[3] == p[4] && p[3] != NO) { // dummy
						j = p[3];
						if (j != FIN) {
							// let's move
							j = go[j][d[i]];
							if (j != FIN) {
								// checking eat
								if (p[1] == p[2] && p[1] == j) { // double eat
									q = p;
									q[3] = q[4] = j; q[1] = q[2] = NO;
									ss.insert(q);
								}
								else if (p[1] == j) { // single eat
									q = p;
									q[3] = q[4] = j; q[1] = NO;
									ss.insert(q);
								}
								else if (p[2] == j) { // single eat
									q = p;
									q[3] = q[4] = j; q[2] = NO;
									ss.insert(q);
								}
								else {
									q = p;
									q[0] = help(p[0],d[i]); q[3] = q[4] = j;
									ss.insert(q);
								}
							}
							else { // cannot eat
								q = p;
								q[0] = help(p[0],d[i]); q[3] = q[4] = j;
								ss.insert(q);
							}
						}
						else ; // cannot move
					}
					else {
						// p[3] move
						j = p[3];
						if (j != FIN) {
							// let's move
							j = go[j][d[i]];
							if (j != FIN) {
								// checking eat
								if (p[1] == p[2] && p[1] == j) { // double eat
									q = p;
									q[3] = j; q[1] = q[2] = NO;
									ss.insert(q);
								}
								else if (p[1] == j) { // single eat
									q = p;
									q[3] = j; q[1] = NO;
									ss.insert(q);
								}
								else if (p[2] == j) { // single eat
									q = p;
									q[3] = j; q[2] = NO;
									ss.insert(q);
								}
								else {
									q = p;
									q[0] = help(p[0],d[i]); q[3] = j;
									ss.insert(q);
								}
							}
							else { // cannot eat
								q = p;
								q[0] = help(p[0],d[i]); q[3] = j;
								ss.insert(q);
							}
						}
						else ; // cannot move

						// p[4] move
						j = p[4];
						if (j != FIN) {
							// let's move
							j = go[j][d[i]];
							if (j != FIN) {
								// checking eat
								if (p[1] == p[2] && p[1] == j) { // double eat
									q = p;
									q[4] = j; q[1] = q[2] = NO;
									ss.insert(q);
								}
								else if (p[1] == j) { // single eat
									q = p;
									q[4] = j; q[1] = NO;
									ss.insert(q);
								}
								else if (p[2] == j) { // single eat
									q = p;
									q[4] = j; q[2] = NO;
									ss.insert(q);
								}
								else {
									q = p;
									q[0] = help(p[0],d[i]); q[4] = j;
									ss.insert(q);
								}
							}
							else { // cannot eat
								q = p;
								q[0] = help(p[0],d[i]); q[4] = j;
								ss.insert(q);
							}
						}
						else ; // cannot move
					}
				}
			}
			s = ss;
		}
		fprintf(out,"%s\n",check(vector<int>()) ? "YES" : "NO");		
	}
	return 0;
}