#include<stdio.h>
#include<string.h>
int tab[1000][1000];
int tmp[1000][1000];
int n;
int rotate(){
	for(int i = 0 ; i < n ; i++ )
		for(int j = 0 ; j < n ; j++ )
			tmp[j][n-1-i] = tab[i][j];
	
	for(int i = 0 ; i < n ; i++ )
		for(int j = 0 ; j < n ; j++ )
			tab[i][j] = tmp[i][j];
}
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e< t ; e++ ){
		scanf("%d",&n);
		char dir[100];
		scanf("%s",dir);
		for(int i = 0 ; i < n ; i++ )
			for(int j = 0 ;j <n ; j++ ) scanf("%d",&tab[i][j]);

		if( strcmp(dir,"down") == 0 ) rotate();
		if( strcmp(dir,"up") == 0 ){ rotate(); rotate(); rotate(); }
		if( strcmp(dir,"right") == 0 ){ rotate(); rotate(); }

		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ;j < n ; j++ ) tmp[i][j] = tab[i][j];
/*
		for(int i = 0 ; i < n ; i++ ){
			for(int j = 0 ;j < n ; j++ ){
				if( j != 0 ) printf(" "); 
				printf("%d",tmp[i][j]);
			}
			printf("\n");
		}
*/
		for(int k = 0 ;k < n ; k++ ){
			int cur = 0;
			for(int i = 0 ; i < n ; i++ ){
				if( tmp[k][i] != 0 ){
					tmp[k][cur] = tmp[k][i];
					cur++;
				}
			}
			for( ; cur < n ; cur++ ) tmp[k][cur] = 0;
			for(int i = 0 ; i < n-1 ; i++ ){
				if( tmp[k][i] == tmp[k][i+1] ){
					tmp[k][i+1] = 0;
					tmp[k][i]*=2;
				}
			}
			cur = 0;
			for(int i = 0 ; i < n ; i++ ){
				if( tmp[k][i] != 0 ){
					tmp[k][cur] = tmp[k][i];
					cur++;
				}
			}
			for( ; cur < n ; cur++ ) tmp[k][cur] = 0;
		}
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ;j < n ; j++) tab[i][j] = tmp[i][j];
		if( strcmp(dir,"down") == 0){ rotate(); rotate(); rotate(); }
		if( strcmp(dir,"up") == 0) rotate();
		if( strcmp(dir,"right") == 0){ rotate(); rotate(); }
		printf("Case #%d:\n",e+1);
		for(int i = 0 ; i < n ; i++ ){
			for(int j = 0 ;j < n ; j++ ){
				if( j != 0 ) printf(" "); 
				printf("%d",tab[i][j]);
			}
			printf("\n");
		}

	}
}
