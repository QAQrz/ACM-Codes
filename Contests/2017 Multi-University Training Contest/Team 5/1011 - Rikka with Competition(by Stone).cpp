#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAX = 1e5+10;
const int mod = 1e9+7;
LL n, k, a[MAX];
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &n, &k);
		for(int i= 0 ; i<n; ++i)
			scanf("%lld", &a[i]);
		sort(a, a+n);
		int ans = 0;
		if(a[n-1]-a[0]>k)ans++;
		for(int i = n-1; i>=1; --i)
			if(a[i]-a[i-1]>k)
				break;
			else
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}