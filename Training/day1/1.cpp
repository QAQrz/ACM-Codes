#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL sum[1024][1024],a[2][1024],t=1,k=2,p,n,m,mod=1000000007;
int main(){
	freopen("test.out","w",stdout);
	for(LL i=1;i<=1000;i++)
		sum[0][i]=a[0][i]=i;
	for(LL i=1;i<1000;i++){
		if(!(i%1000))
			p++;
		for(LL j=t*i+1;j<=1000;j++){
			a[i%2][j]=(a[i%2][j-t]-(j>(k+1)*t?a[(i%2)^1][j-(k+1)*t]:0)+a[(i%2)^1][j-t]+mod)%mod;
			if(!(i%1000))
				sum[p][j]=a[i%2][j];
		}
	}
	for(LL i=0;i<1000;i++)
		for(LL j=1;j<=1000;j++)
			printf("sum[%lld][%lld]=%lld;\n",i+1,j,sum[i][j]);
	return 0;
}