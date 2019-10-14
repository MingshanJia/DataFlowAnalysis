#include <stdio.h>
#include <string.h>
#include <memory.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
char a[505],b[505],c[505];
int T,t,l,i,j,k;
int D[505][2];
int A[505],B[505],C[505];
int fa[505],fb[505],fc[505];
int va[505][2],vb[505][2];
int main(){
	fscanf(in,"%d",&T);
	while(T--){
		fprintf(out,"Case #%d: ",++t);
		char c1,c2;
		fscanf(in,"%s",a);
		fscanf(in," %c",&c1);
		fscanf(in,"%s",b);
		fscanf(in," %c",&c2);
		fscanf(in,"%s",c);
		int len1=strlen(a); int len2=strlen(b); int len3=strlen(c);
		memset(A,0,sizeof(A)); memset(fa,0,sizeof(fa));
		memset(B,0,sizeof(B)); memset(fb,0,sizeof(fb));
		memset(C,0,sizeof(C)); memset(fc,0,sizeof(fc));
		for(i=500,j=len1-1;j>=0;) A[i--]=a[j--]-'0'; if(len1>1) fa[i+1]=1;
		for(i=500,j=len2-1;j>=0;) B[i--]=b[j--]-'0'; if(len2>1) fb[i+1]=1;
		for(i=500,j=len3-1;j>=0;) C[i--]=c[j--]-'0'; if(len3>1) fc[i+1]=1;
		if(c1=='+'){
			
			//Select A
			memset(D,0,sizeof(D));
			D[500][0]=1;
			for(l=500;l>=1;l--){
				for(i=0;i<=9;i++){
					if(A[l]!=15&&A[l]!=i) continue;
					if(fa[l]&&!i) continue;
					for(j=0;j<=9;j++){
						if(B[l]!=15&&B[l]!=j) continue;
						if(fb[l]&&!j) continue;
						for(k=0;k<=9;k++){
							if(C[l]!=15&&C[l]!=k) continue;
							if(fc[l]&&!k) continue;
							if(i+j==k) D[l-1][0]|=D[l][0];
							if(i+j==k+10) D[l-1][1]|=D[l][0];
							if(i+j+1==k) D[l-1][0]|=D[l][1];
							if(i+j+1==k+10) D[l-1][1]|=D[l][1];
						}
					}
				}
			}

			//Select A path

			memset(va,0,sizeof(va));
			va[0][0]=1;

			for(l=1;l<=500;l++){
				for(i=0;i<=9;i++){
					if(A[l]!=15&&A[l]!=i) continue;
					if(fa[l]&&!i) continue;
					for(j=0;j<=9;j++){
						if(B[l]!=15&&B[l]!=j) continue;
						if(fb[l]&&!j) continue;
						for(k=0;k<=9;k++){
							if(C[l]!=15&&C[l]!=k) continue;
							if(fc[l]&&!k) continue;
							if(i+j==k&&va[l-1][0]&&D[l][0]) va[l][0]=1;
							if(i+j==k+10&&va[l-1][1]&&D[l][0]) va[l][0]=1;
							if(i+j+1==k&&va[l-1][0]&&D[l][1]) va[l][1]=1;
							if(i+j+1==k+10&&va[l-1][1]&&D[l][1]) va[l][1]=1;							
						}
					}
					if(va[l][0]||va[l][1]) break;
				}
				A[l]=i;
			}

			//Select B
			memset(D,0,sizeof(D));
			D[500][0]=1;
			for(l=500;l>=1;l--){
				for(i=0;i<=9;i++){
					if(A[l]!=15&&A[l]!=i) continue;
					if(fa[l]&&!i) continue;
					for(j=0;j<=9;j++){
						if(B[l]!=15&&B[l]!=j) continue;
						if(fb[l]&&!j) continue;
						for(k=0;k<=9;k++){
							if(C[l]!=15&&C[l]!=k) continue;
							if(fc[l]&&!k) continue;
							if(i+j==k) D[l-1][0]|=D[l][0];
							if(i+j==k+10) D[l-1][1]|=D[l][0];
							if(i+j+1==k) D[l-1][0]|=D[l][1];
							if(i+j+1==k+10) D[l-1][1]|=D[l][1];
						}
					}
				}
			}

			//Select B path

			memset(vb,0,sizeof(vb));
			vb[0][0]=1;

			for(l=1;l<=500;l++){
				for(i=0;i<=9;i++){
					if(A[l]!=15&&A[l]!=i) continue;
					if(fa[l]&&!i) continue;
					for(j=0;j<=9;j++){
						if(B[l]!=15&&B[l]!=j) continue;
						if(fb[l]&&!j) continue;
						for(k=0;k<=9;k++){
							if(C[l]!=15&&C[l]!=k) continue;
							if(fc[l]&&!k) continue;
							if(i+j==k&&vb[l-1][0]&&D[l][0]) vb[l][0]=1;
							if(i+j==k+10&&vb[l-1][1]&&D[l][0]) vb[l][0]=1;
							if(i+j+1==k&&vb[l-1][0]&&D[l][1]) vb[l][1]=1;
							if(i+j+1==k+10&&vb[l-1][1]&&D[l][1]) vb[l][1]=1;							
						}
						if(vb[l][0]||vb[l][1]) break;
					}
					B[l]=j;
				}
			}

			// Calc C

			memset(C,0,sizeof(C));
			for(i=500;i>=1;i--){
				C[i]+=A[i]+B[i];
				if(C[i]>=10) C[i]-=10,C[i-1]++;
			}

			// output

			for(i=0;A[i]==0&&i<=500;i++); if(i==501) fprintf(out,"0");
			for(;i<=500;i++) fprintf(out,"%d",A[i]); fprintf(out," + ");
			for(i=0;B[i]==0&&i<=500;i++); if(i==501) fprintf(out,"0");
			for(;i<=500;i++) fprintf(out,"%d",B[i]); fprintf(out," = ");
			for(i=0;C[i]==0&&i<=500;i++); if(i==501) fprintf(out,"0");
			for(;i<=500;i++) fprintf(out,"%d",C[i]); 

			fprintf(out,"\n");
		}
		else{

			//Select A
			memset(D,0,sizeof(D));
			D[500][0]=1;
			for(l=500;l>=1;l--){
				for(i=0;i<=9;i++){
					if(A[l]!=15&&A[l]!=i) continue;
					if(fa[l]&&!i) continue;
					for(j=0;j<=9;j++){
						if(B[l]!=15&&B[l]!=j) continue;
						if(fb[l]&&!j) continue;
						for(k=0;k<=9;k++){
							if(C[l]!=15&&C[l]!=k) continue;
							if(fc[l]&&!k) continue;
							if(i-j==k) D[l-1][0]|=D[l][0];
							if(i-j==k-10) D[l-1][1]|=D[l][0];
							if(i-j-1==k) D[l-1][0]|=D[l][1];
							if(i-j-1==k-10) D[l-1][1]|=D[l][1];
						}
					}
				}
			}

			//Select A path

			memset(va,0,sizeof(va));
			va[0][0]=1;

			for(l=1;l<=500;l++){
				for(i=0;i<=9;i++){
					if(A[l]!=15&&A[l]!=i) continue;
					if(fa[l]&&!i) continue;
					for(j=0;j<=9;j++){
						if(B[l]!=15&&B[l]!=j) continue;
						if(fb[l]&&!j) continue;
						for(k=0;k<=9;k++){
							if(C[l]!=15&&C[l]!=k) continue;
							if(fc[l]&&!k) continue;
							if(i-j==k&&va[l-1][0]&&D[l][0]) va[l][0]=1;
							if(i-j==k-10&&va[l-1][1]&&D[l][0]) va[l][0]=1;
							if(i-j-1==k&&va[l-1][0]&&D[l][1]) va[l][1]=1;
							if(i-j-1==k-10&&va[l-1][1]&&D[l][1]) va[l][1]=1;							
						}
					}
					if(va[l][0]||va[l][1]) break;
				}
				A[l]=i;
			}

			//Select B
			memset(D,0,sizeof(D));
			D[500][0]=1;
			for(l=500;l>=1;l--){
				for(i=0;i<=9;i++){
					if(A[l]!=15&&A[l]!=i) continue;
					if(fa[l]&&!i) continue;
					for(j=0;j<=9;j++){
						if(B[l]!=15&&B[l]!=j) continue;
						if(fb[l]&&!j) continue;
						for(k=0;k<=9;k++){
							if(C[l]!=15&&C[l]!=k) continue;
							if(fc[l]&&!k) continue;
							if(i-j==k) D[l-1][0]|=D[l][0];
							if(i-j==k-10) D[l-1][1]|=D[l][0];
							if(i-j-1==k) D[l-1][0]|=D[l][1];
							if(i-j-1==k-10) D[l-1][1]|=D[l][1];
						}
					}
				}
			}

			//Select B path

			memset(vb,0,sizeof(vb));
			vb[0][0]=1;

			for(l=1;l<=500;l++){
				for(i=0;i<=9;i++){
					if(A[l]!=15&&A[l]!=i) continue;
					if(fa[l]&&!i) continue;
					for(j=0;j<=9;j++){
						if(B[l]!=15&&B[l]!=j) continue;
						if(fb[l]&&!j) continue;
						for(k=0;k<=9;k++){
							if(C[l]!=15&&C[l]!=k) continue;
							if(fc[l]&&!k) continue;
							if(i-j==k&&vb[l-1][0]&&D[l][0]) vb[l][0]=1;
							if(i-j==k-10&&vb[l-1][1]&&D[l][0]) vb[l][0]=1;
							if(i-j-1==k&&vb[l-1][0]&&D[l][1]) vb[l][1]=1;
							if(i-j-1==k-10&&vb[l-1][1]&&D[l][1]) vb[l][1]=1;							
						}
						if(vb[l][0]||vb[l][1]) break;
					}
					B[l]=j;
				}
			}

			// Calc C

			memset(C,0,sizeof(C));
			for(i=500;i>=1;i--){
				C[i]+=A[i]-B[i];
				if(C[i]<0) C[i]+=10,C[i-1]--;
			}

			// output

			for(i=0;A[i]==0&&i<=500;i++); if(i==501) fprintf(out,"0");
			for(;i<=500;i++) fprintf(out,"%d",A[i]); fprintf(out," - ");
			for(i=0;B[i]==0&&i<=500;i++); if(i==501) fprintf(out,"0");
			for(;i<=500;i++) fprintf(out,"%d",B[i]); fprintf(out," = ");
			for(i=0;C[i]==0&&i<=500;i++); if(i==501) fprintf(out,"0");
			for(;i<=500;i++) fprintf(out,"%d",C[i]); 

			fprintf(out,"\n");

		}
	}
	return 0;
}