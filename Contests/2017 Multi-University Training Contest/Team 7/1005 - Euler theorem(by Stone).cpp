#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <cmath>
#include <set>
#include <stdlib.h>
using namespace std;
typedef long long LL;
const LL MAX = 8000000+10;
const LL mod = 7654321;
const double eps = 5e-6;
const double PI = acos(-1.0);
int euler(int n){
	int res=n,a=n;
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			res=res/i*(i-1);
			while(a%i==0) a/=i;
		}
	}
	if(a>1) res=res/a*(a-1);
	return res;
}
int solve(int x){
	int ans = 0;
	set<int>que;
	for(int i = 1; i<=x+1; ++i)
		que.insert(x%i);
	return que.size();
}
int main(){
	int t, x;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &x);
		printf("%d\n", (x-x/2)+1);
	}
	return 0;
}