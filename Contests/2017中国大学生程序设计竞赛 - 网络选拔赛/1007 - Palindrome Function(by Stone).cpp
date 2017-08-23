#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdlib.h>
typedef long long LL;
using namespace std;
const LL MAX = 1e6+10;
const double eps = 1e-8;
const double PI = acos(-1.0);
const LL MAXLEN = 50;
LL digit[MAXLEN], base;
LL fast(LL a, LL n){
	LL base = a, ret = 1;
	while(n){
		if(n&1)ret = ret*base;
		base*=base;
		n>>=1;
	}
	return ret;
}
LL calc(LL n) {
	if(n==0)return 0;
	LL len = 0, x, m = n, ret, pp =1;
	while(n) {
		digit[len++] = n%base;
		n/=base;
		pp*=base;
	}
	if(len==1)return digit[0];
	x = 0;
	for(LL i = len-1; i>=len/2; --i){
		x = x*base+digit[i];
	}
	ret = x;
	LL k = len/2;
	if(len&1)k++;
	while(k<len){
		x = x*base+digit[k];
		k++;
	}
	if(x>m)ret--;
	ret-=fast(base,len-len/2-1);
	len--;
	while(len>0){
		x = len-len/2;
		ret+=(base-1)*fast(base,x-1);
		len--;
	}
	ret++;
	return ret;
}
int main() {
	LL t, L, R, l, r;
	scanf("%lld", &t);
	for(LL tt = 1; tt<=t; ++tt) {
		scanf("%lld%lld%lld%lld", &L, &R, &l, &r);
		LL ans = 0, ret;
		for(LL i = l; i<=r; ++i) {
			base = i;
			ret = calc(R)-calc(L-1);
			ans = ans+R-L+1+ret*(i-1);
		}
		printf("Case #%lld: %lld\n", tt, ans);
	}
	return 0;
}