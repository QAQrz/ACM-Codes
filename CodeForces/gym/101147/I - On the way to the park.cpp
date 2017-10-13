#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAX = 5e5+10;
const LL mod = 1e9+7;
const double eps = 1e-7;
int n, cnt, t;
double R, x, y, r;
struct node{
	double pos;
	int flag;
}p[MAX];
bool cmp(node a, node b){
	if(fabs(a.pos-b.pos)>eps)return a.pos<b.pos;
	else return a.flag>b.flag;
}
int main() {
	freopen("walk.in", "r", stdin);
	scanf("%d", &t);
	while(t--){
		scanf("%d%lf", &n, &R);
		cnt = 0;
		for(int i = 0; i<n; ++i){
			scanf("%lf%lf%lf", &x, &y, &r);
			if(y<0)y = -y;
			if(y>R-r||R<r)continue;
			p[cnt].flag = (int)r;
			p[cnt++].pos = x-sqrt((r-R)*(r-R)-y*y);
			p[cnt].flag = (int)-r;
			p[cnt++].pos = x+sqrt((r-R)*(r-R)-y*y);
		}
		sort(p, p+cnt, cmp);
		/*for(int i = 0; i<cnt; ++i){
			printf("%.2f %d\n", p[i].pos, p[i].flag);
		}*/
		int num = 0, ans = 0;
		for(int i =0; i<cnt; ++i){
			num+=p[i].flag;	
			ans = max(ans, num);
		}
		printf("%d\n", ans);
	}
	return 0;
}