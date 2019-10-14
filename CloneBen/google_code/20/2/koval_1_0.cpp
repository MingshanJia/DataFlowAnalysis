#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <memory.h>
#include <string>

int t,T;

#define LEN 300

char a[LEN],b[LEN],c[LEN];
char aa[LEN],bb[LEN],cc[LEN];
char op;

int dy[LEN][10][10][10][5];


struct path_t{
	int j;
	int k;
	int l;
	int m;
	path_t(int j,int k,int l,int m)
		: j(j),k(k),l(l),m(m){}
	path_t() : j(0), k(0), l(0), m(0){}
};

path_t path[LEN][10][10][10][5];

std::string makeseq(int n, const path_t& patt){
	path_t pat = patt;
	std::string ap,bp,cp;
	for (int i=n;i>=0;--i){
		ap += pat.j + '0';
		bp += pat.k + '0';
		cp += pat.l + '0';
		pat = path[i][pat.j][pat.k][pat.l][pat.m];
	}
	return ap+bp+cp;
}

int valid(char *str, int num, int n){
	if (strlen(str) <= n){
		return (num==0);
	}
	if (str[n] == '?'){
		if (strlen(str)-1 == n){
			return num!=0 || (n==0);
		}
		return true;
	}
	else
		return str[n] == num+'0';
}

void assign(char *str, int n, int num){
	if (strlen(str) <= n) return;
	str[n] = num + '0';
}

int oper(int a,int b, int c, char op){
	if (op == '-')
		return c - (a - b);
	else
		return c - (a + b);
}

int main(){
	//freopen("b.in","rt",stdin);
	//freopen("b.out","wt",stdout);
	freopen("b-small.in","rt",stdin);
	freopen("b-small.out","wt",stdout);
	scanf("%d\n",&T);
	for (t=1;t<=T;++t){
		strset(a,0);
		strset(b,0);
		strset(c,0);
		strset(aa,0);
		strset(bb,0);
		strset(cc,0);
		memset(dy,0,sizeof(dy));
		memset(path,0,sizeof(path));

		scanf("%s %c %s %*c %s",a,&op,b,c);
		strcpy(aa,a);
		strcpy(bb,b);
		strcpy(cc,c);
		strrev(aa);
		strrev(bb);
		strrev(cc);

		int ii;
		for (ii=0;ii<std::max(std::max(strlen(aa),strlen(bb)),strlen(cc));++ii){

			for (int j=0;j<=9;++j){

				if (valid(aa,j,ii));
				else continue;

				for (int k=0;k<=9;++k){

					if (valid(bb,k,ii));
					else continue;

					for (int l=0;l<=9;++l){
						if (valid(cc,l,ii));
						else continue;
						
						int value = oper(j,k,l,op);


						if (ii==0){
							if (value == -10 || value == 0 || value == 10 || value == -20 || value == 20);
							else continue;
							value /= 10;
							dy[ii][j][k][l][value + 2] = 1;
							//printf("%d, %d, %d, %d, %d\n",ii,j,k,l,value+2);
							continue;
						}

						for (int mm=-2;mm<=2;++mm){
							int vvalue = mm + value;
							if (vvalue == -10 || vvalue == 0 || vvalue == 10 || vvalue == -20 || vvalue == 20);
							else continue;
							vvalue /= 10;
							vvalue += 2;

							int mp = vvalue;

							int m = mm + 2;
							std::string optseq = "";

							for (int jj=0;jj<=9;++jj){
								if (valid(aa,jj,ii-1));
								else continue;
								for (int kk=0;kk<=9;++kk){
									if (valid(bb,kk,ii-1));
									else continue;
									for (int ll=0;ll<=9;++ll){
										if (valid(cc,ll,ii-1));
										else continue;

										if (dy[ii-1][jj][kk][ll][m]){
											//printf("%d, %d, %d, %d, %d\n",ii,j,k,l,mp);
											dy[ii][j][k][l][mp] = 1;

											if (optseq=="" || optseq > makeseq(ii-1,path_t(jj,kk,ll,m))){
												optseq = makeseq(ii-1,path_t(jj,kk,ll,m));
												path[ii][j][k][l][mp] = path_t(jj,kk,ll,m);
											}
										}

									}
								}
							}					
endpnt:;
						}
					}
				}
			}
		}

		path_t pat;

		for (int j=0;j<=9;++j){
			for (int k=0;k<=9;++k){
				for (int l=0;l<=9;++l){
					if (dy[ii-1][j][k][l][2]){
						pat.j = j;
						pat.k = k;
						pat.l = l;
						pat.m = 2;
						goto ep2;
					}
				}
			}
		}

ep2:;

		for (int i=ii-1;i>=0;--i){
			assign(aa,i,pat.j);
			assign(bb,i,pat.k);
			assign(cc,i,pat.l);
			pat = path[i][pat.j][pat.k][pat.l][pat.m];
		}

		strrev(aa);
		strrev(bb);
		strrev(cc);

		
		int aaa,bbb,ccc;
		aaa = atoi(aa);
		bbb = atoi(bb);
		ccc = atoi(cc);
		if (op=='-'){
			if (aaa-bbb == ccc);
			else{
				exit(0);
			}
		}
		else{
			if (aaa+bbb == ccc);
			else{
				exit(0);
			}
		}


		printf("Case #%d: %s %c %s = %s\n",t,aa,op,bb,cc);
	}
	return 0;
}