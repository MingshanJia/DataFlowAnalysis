#include <stdio.h>
#include <memory.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int U,N,A,B,T,t,q,i,j,k,l,f;
int D[51][31][31][31][31][2];
int a[3],b[3];
inline int up(int A,int B){
	if(A==29) return B;
	if(A==5) return 19+B;
	if(A==10){
		if(B==3) return 22;
		if(B<3) return 24+B;
		if(B>3) return 23+B;
	}
	if(A==22){
		if(B<3) return 26+B;
		if(B==3) return 0;
		if(B>3) return 30;
	}
	if(A==25){
		if(B==1) return 26;
		if(B==2) return 22;
		if(B==3) return 27;
		if(B==4) return 28;
		if(B==5) return 0;
	}
	if(A==26){
		if(B==1) return 22;
		if(B==2) return 27;
		if(B==3) return 28;
		if(B==4) return 0;
		if(B==5) return 30;
	}
	if(A==27){
		if(B==1) return 28;
		if(B==2) return 0;
		return 30;
	}
	if(A==28){
		if(B==1) return 0;
		return 30;
	}
	if(A==0){
		return 30;
	}
	if(A==23){
		if(B==1) return 24;
		else return 13+B;
	}
	if(A==24){
		return 14+B;
	}
	if(A==16){
		if(B==4) return 0;
		if(B==5) return 30;
		return A+B;
	}
	if(A==17){
		if(B==3) return 0;
		if(B==4||B==5) return 30;
		return A+B;
	}
	if(A==18){
		if(B==2) return 0;
		if(B==3||B==4||B==5) return 30;
		return A+B;
	}
	if(A==19){
		if(B==1) return 0;
		return 30;
	}
	return A+B;
}
inline void match(int a1,int a2,int b1,int b2,int c){
	int c1=0,c2=0;
	if(a1!=29) c1++;
	if(a2!=29) c1++;
	if(b1!=29) c2++;
	if(b2!=29) c2++;
	if(c1>U||c2>U) return;
	
	if(c==0){
		int o=1;
		if(f==4||f==5){
			if(a1==30&&a2==30){
				if(q!=N-1) return;
			}
			o=0;
		}
		if(a1!=29&&a1!=30&&a1==b1){
			b1=29; o=0;
		}
		if(a1!=29&&a1!=30&&a1==b2){
			b2=29; o=0;
		}
		if(a2!=29&&a2!=30&&a2==b1){
			b1=29; o=0;
		}
		if(a2!=29&&a2!=30&&a2==b2){
			b2=29; o=0;
		}
		D[q+1][a1][a2][b1][b2][0^o]=1;
	}
	else if(c==1){
		int o=1;
		if(f==4||f==5){
			if(b1==30&&b2==30){
				if(q!=N-1) return;
			}
			o=0;
		}
		if(b1!=29&&b1!=30&&b1==a1){
			a1=29; o=0;
		}
		if(b1!=29&&b1!=30&&b1==a2){
			a2=29; o=0;
		}
		if(b2!=29&&b2!=30&&b2==a1){
			a1=29; o=0;
		}
		if(b2!=29&&b2!=30&&b2==a2){
			a2=29; o=0;
		}
		D[q+1][a1][a2][b1][b2][1^o]=1;
	}
}
int main(){
	for(fscanf(in,"%d",&T);T--;){
		fscanf(in,"%d%d%d%d",&U,&N,&A,&B);
		memset(D,0,sizeof(D));
		D[0][29][29][29][29][0]=1;
		for(q=0;q<N;q++){
			char s[30]={0,};
			fscanf(in,"%s",&s);
			if(s[0]=='D') f=1;
			else if(s[0]=='G'){
				if(s[1]=='a') f=2;
				else f=3;
			}
			else if(s[0]=='Y') f=4;
			else f=5;
			for(i=0;i<=30;i++){
				for(j=0;j<=30;j++){
					for(k=0;k<=30;k++){
						for(l=0;l<=30;l++){
							if(D[q][i][j][k][l][0]){
								if(i!=30&&i!=29&&i==j){
									match(up(i,f),up(j,f),k,l,0);
								}
								else{
									if(i!=30) match(up(i,f),j,k,l,0);		
									if(j!=30) match(i,up(j,f),k,l,0);
								}
							}
							if(D[q][i][j][k][l][1]){
								if(k!=30&&k!=29&&k==l){
									match(i,j,up(k,f),up(l,f),1);
								}
								else{
									if(k!=30) match(i,j,up(k,f),l,1);		
									if(l!=30) match(i,j,k,up(l,f),1);
								}
							}
						}
					}
				}
			}
		}
		for(i=0;i<A;i++) fscanf(in,"%d",&a[i]);
		for(i=0;i<B;i++) fscanf(in,"%d",&b[i]);
		int dap=0;
		for(i=0;i<=30;i++){
			for(j=0;j<=30;j++){
				for(k=0;k<=30;k++){
					for(l=0;l<=30;l++){
						if(!D[N][i][j][k][l][0]&&!D[N][i][j][k][l][1]) continue;
						int c1=0,c2=0;
						if(i!=29&&i!=30) c1++;
						if(j!=29&&j!=30) c1++;
						if(k!=29&&k!=30) c2++;
						if(l!=29&&l!=30) c2++;
						if(c1==A&&c2==B){
							int ok=0;
							if(A==0) ok++;
							if(A==1){
								if(i==a[0]||j==a[0]) ok++;
							}
							if(A==2){
								if((i==a[0]&&j==a[1])||(i==a[1]&&j==a[0])) ok++;
							}
							if(B==0) ok++;
							if(B==1){
								if(k==b[0]||l==b[0]) ok++;
							}
							if(B==2){
								if((k==b[0]&&l==b[1])||(k==b[1]&&l==b[0])) ok++;
							}
							if(ok==2) dap=1;
						}
					}			
				}
			}
		}
		if(dap==1) fprintf(out,"Case #%d: YES\n",++t);
		else fprintf(out,"Case #%d: NO\n",++t);
	}
	return 0;
}