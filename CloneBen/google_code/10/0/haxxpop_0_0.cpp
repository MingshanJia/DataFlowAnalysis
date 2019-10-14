#include<stdio.h>
char ori[10][8] = { "1111110","0110000","1101101","1111001","0110011","1011011","1011111","1110000","1111111","1111011" };
int broken[10];
int match(char *s,int num){
	for(int i = 0 ;i < 7 ; i++ ) broken[i] = 0;
	for(int i = 0 ;i < 7 ; i++ ){
		if( ori[num][i] == 0 && s[i] == 1 ) return 0;
		if( ori[num][i] == 1 && s[i] == 0 ) broken[i] = 1;
	}
	return 1;
}
char inp[200][8];
int main(){
	int t;
	scanf("%d",&t);
	for(int i = 0 ;i < 10 ; i++ ){
		for(int j = 0 ;j < 7 ; j++ ) ori[i][j] -= '0';
	}
	for(int e = 0 ; e < t ; e++ ){
		int n;
		scanf("%d",&n);
		for(int i = 0 ; i < n ; i++ ){
			scanf("%s",inp[i]);
			for(int j =0 ;j < 7 ;j++ ) inp[i][j] -='0';
		}
		int ans = -1;
		int err = 0;
		for(int start = 9 ; start >=0 ; start-- ){
			for(int k = 0 ; k < (1<<7) ; k++ ){
				int chk = 1;
				for(int i = 0 ; i < n ; i++ ){
					int now = (start-i)%10;
					if( now < 0 ) now += 10;

					for(int j = 0 ; j < 7 ; j++ ){
						/*if( ori[now][j] == 1 && (k>>j)%2 == 1  ){
							chk = 0;
							break;
						}*/
						if( (k>>j)%2 == 0 && ori[now][j] != inp[i][j] ){
							chk = 0;
						//	if( start == 9 && k == 2 && chk == 0 ) printf("dam %d, %d %d\n",j,ori[now][i],inp[i][j]);
							break;
						}
						if( inp[i][j] == 1 && (k>>j)%2 == 1 ){
							chk = 0;
							break;
						}
					}
					if( start == 9 && k == 2 && chk == 0 ){
						//printf("i %d\n",i);
					}
					if( chk == 0 ) break;
				}
				if( chk ){
					//printf("%d %d\n",start,k);
					int next = (start-n)%10;
					if( next < 0 ) next+=10;
					int res = 0;
					for(int i = 6 ; i >=0 ; i-- ){
						res *=2;
						if( (k>>i)%2 == 1 ) res += 0;
						else if( ori[next][i] == 1 ) res +=1;
						else res += 0;
					}
					if( ans == -1 ) ans = res;
					else {
						if( ans != res ) err = 1;
					}
				}
			}
		}
		printf("Case #%d: ",e+1);
		if( err == 1 || ans == -1 ){
			printf("ERROR!\n");
		}else{
			for(int i = 0 ;i < 7 ; i++ ){
				printf("%d",ans%2);
				ans >>=1;
			}
			printf("\n");
		}
	}
}
