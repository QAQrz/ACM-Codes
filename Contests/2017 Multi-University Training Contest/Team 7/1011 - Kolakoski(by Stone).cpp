#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <cmath>
#include <set>
#include <stdlib.h>
using namespace std;
typedef long long LL;
const LL MAX = 1e7+10;
const LL mod = 7654321;
const double eps = 5e-6;
const double PI = acos(-1.0);
int a[MAX];
void init(){
	a[1] = 1;
	a[2] = 2;
	int sum = 3;
	int r = 2;
	while(sum+1<MAX){
		if(r%2)a[sum] = 1;
		else a[sum] = 2;
		a[sum+1] = 3-a[sum];
		sum+=a[++r];
	}
}
int main(){
	int t, x;
	init();
	scanf("%d", &t);
	while(t--){
		scanf("%d", &x);
		printf("%d\n", a[x]);
	}
	return 0;
}