#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <cmath>
#include <stdlib.h>
using namespace std;
typedef long long LL;
const LL MAX = 5000+10;
const LL mod = 7654321;
const double eps = 1e-8;
const double PI = acos(-1.0);
#define zero(x) (((x)>0?(x):(-x))<eps)
int ans, m, len;
char s[MAX];
void solve(int a, int b){
	int l = 0, r = 0, sum = 0;
	while(a+r<b-r){
		sum+=abs(s[a+r]-s[b-r]);
		r++;
		if(b-l-a-l+1<=ans*2)break;
		while(sum>m&&r>l){
			sum-=abs(s[a+l]-s[b-l]);
			l++;
		}
		if(ans<r-l)ans = r-l;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &m);
		scanf("%s", s);
		len = strlen(s);
		ans = 0;
		for(int i = 1; i<len; ++i)
			solve(0, i);
		for(int i = 0; i<len-1; ++i)
			solve(i,len-1);
		printf("%d\n", ans);
	}
	return 0;
}