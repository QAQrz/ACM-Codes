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
LL n;
LL fast(LL a, LL n){
	LL base = a, ret =1;
	while(n>0){
		if(n&1)ret = ret*base;
		base*= base;
		n>>=1;
	}
	return ret;
}
LL f[1000];
void Init(){
	f[0] = 0;
	for(LL i = 1; i<=20; ++i){
		f[i] = fast(i,i);
	}
}
int main(){
	Init();
	while(~scanf("%lld", &n)){
		int ans = 0;
		for(int i = 1; i<=15; ++i){
			if(f[i]<=n)ans++;
			else break;
		}
		printf("%d\n", ans);
	}
	return 0;
}