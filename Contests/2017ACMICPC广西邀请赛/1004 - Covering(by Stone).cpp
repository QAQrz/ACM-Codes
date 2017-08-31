#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <queue>
typedef long long LL;
using namespace std;
const int MAX = 1e6+10;
LL n, b, t, c, f1, f2;
const LL N = 4;
const LL mod = 1e9+7;
struct Node{
	long long line, cal;
	long long a[N+1][N+1];
	Node(){
		line = 4;
		cal = 4;
		a[0][0]=1; a[0][1]=1;a[0][2]=0;a[0][3]=0;
		a[1][0]=5; a[1][1]=0;a[1][2]=1;a[1][3]=0;
		a[2][0]=1; a[2][1]=0;a[2][2]=0;a[2][3]=1;
		a[3][0]=-1;a[3][1]=0;a[3][2]=0;a[3][3]=0;
	}
};
Node isit(Node x, long long c){
	for(LL i=0;i<N; ++i){
		for(LL j = 0; j<N; ++j){
			x.a[i][j]=c;
		}
	}
	return x;
}
Node Matlab(Node x, Node s){
	Node ans;
	ans.line = x.line, ans.cal = s.cal;
	ans = isit(ans, 0);
	for(LL i = 0; i<x.line; ++i){
		for(LL k = 0; k<s.cal; ++k){
			for(LL j = 0; j<x.cal; ++j){
				ans.a[i][j]+=x.a[i][k]*s.a[k][j];
				ans.a[i][j] = (ans.a[i][j]+mod)%mod;
			}
		}
	}
	return ans;
}
LL Fast_Matrax(LL n){
	if(n==1)return 1;
	else if(n==2)return 5;
	else if(n==3)return 11;
	n-=4;
	Node ans, tmp;
	ans.line = 1;
	ans.cal = 4;
	ans.a[0][0] = 36, ans.a[0][1] = 11, ans.a[0][2] = 5;ans.a[0][3]=1;
	while(n>0){
		if(n%2){
			ans = Matlab(ans, tmp);
		}
		tmp=Matlab(tmp, tmp);
		n/=2;
	}
	return ans.a[0][0];
}
int main(){
	while(~scanf("%lld", &n)){
		printf("%lld\n", Fast_Matrax(n));
	}
	return 0;
}