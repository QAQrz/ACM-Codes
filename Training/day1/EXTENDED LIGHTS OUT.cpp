#include <cstdio>
#include <cstring>
using namespace std;
int t,a[9][9],b[9][9],c[9][9],i;
int main(){
	scanf("%d",&t);
	for(int p=1;p<=t;p++){
		for(i=0;i<5;i++)
			for(int j=0;j<6;j++)
				scanf("%d",&a[i][j]);
		for(int k=1<<6;~k;k--){
			memcpy(b,a,sizeof a);
			memset(c,0,sizeof c);
			for(i=0;i<6;i++)
				if((k>>i)&1){
					if(i)
						b[0][i-1]^=1;
					b[0][i]^=1,b[1][i]^=1,c[0][i]=1;
					if(i<5)
						b[0][i+1]^=1;
				}
			for(i=0;i<4;i++){
				for(int j=0;j<6;j++)
					if(b[i][j]){
						b[i][j]^=1,b[i+1][j]^=1,c[i+1][j]=1;
						if(j)
							b[i+1][j-1]^=1;
						if(j<5)
							b[i+1][j+1]^=1;
						if(i<3)
							b[i+2][j]^=1;
					}
			}
			for(i=0;i<6;i++)
				if(b[4][i])
					break;
			if(i>5)
				break;
		}
		printf("PUZZLE #%d\n",p);
		for(i=0;i<5;i++)
			for(int j=0;j<6;j++)
				printf("%d%c",c[i][j],j<5?' ':'\n');
	}
	return 0;
}