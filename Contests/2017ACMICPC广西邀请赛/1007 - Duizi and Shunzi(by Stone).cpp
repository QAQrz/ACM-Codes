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
const LL mod = 1000000007;
const int MAX = 1e6+10;
int n;
int a[MAX];
int maxx, minn, x;
int main(){
	while(~scanf("%d", &n)){
		memset(a, 0, sizeof(a));
		maxx = -1, minn = MAX;
		int ans = 0;
		for(int i = 0; i<n; ++i){
			scanf("%d", &x);
			a[x]++;
			if(x>maxx)maxx = x;
			if(x<minn)minn = x;
			if(a[x]>2){
				a[x]-=2;
				ans++;
			}
		}
		for(int i = minn; i<=maxx; ++i){
			if(a[i]==2){
				ans++;
			}else if(a[i]==1&&a[i+1]==1&&a[i+2]){
				ans++;
				a[i+1]--;
				a[i+2]--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}