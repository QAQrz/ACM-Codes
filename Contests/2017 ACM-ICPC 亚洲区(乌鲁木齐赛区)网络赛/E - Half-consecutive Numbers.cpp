#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
const int MAX = 1e5+10;
const double PI = acos(-1.0);
typedef long long LL;
using namespace std;
LL p[333];
int main() {
	p[1] = 1LL;
	p[2] = 3LL;
	for(int i = 3; i<=100; ++i){
		p[i] = p[i-1]*2+p[i-2];
	}
	int t;
	LL n, k;
	scanf("%d", &t);
	for(int tt = 1; tt<=t; ++tt){
		scanf("%lld", &n);
		for(int i = 1; i<=40; ++i){
			if(i&1)k = p[i]*p[i];
			else k = p[i]*p[i]-1;
			if(k>=n){
				printf("Case #%d: %lld\n", tt, k);
				break;
			}
		}
	}
	return 0;
}