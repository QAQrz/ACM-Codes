#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAX = 1e4+10;
const int mod = 1e9+7;
LL n, m, b[MAX], C[51][51], a[MAX];
void init(){
	memset(C, 0, sizeof(C));
	C[0][0] = 1;
	for(int i = 1; i<=50; ++i){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j<i; ++j){
			C[i][j] = C[i-1][j]+C[i-1][j-1];
		}
	}
}
void show(){
	for(int i= 0; i<=m; ++i){
		printf("%d ", b[i]);
	}
	printf("\n");
}
int main(){
	LL t;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld", &n, &m);
		for(LL i =  0; i<=m; ++i){
			scanf("%lld", &b[i]);
		}
		b[0]--;
		for(int i = 1; i<=n; ++i){
			for(int j = 0; j<=m; ++j){
				if(b[j]){
					a[i] = j;
					b[j]--;
					break;
				}
			}
			for(int j = 0; j<=m; ++j){
				if(b[j]){
					b[j+a[i]]-=b[j];
				}
			}
		}
		for(int i = 1; i<n; ++i){
			printf("%lld ", a[i]);
		}
		printf("%lld\n", a[n]);
	}
	return 0;
}