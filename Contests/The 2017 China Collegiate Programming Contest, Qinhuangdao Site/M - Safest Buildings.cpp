#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pc(x) putchar(x)
#define ps(x) puts(x)
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-6;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=111;
int t, n, pos;
double r, R;
struct node{
	int x, y, id;
	double d;
}p[maxn];
void show_n(){
	printf("%d\n", n);
	for(int i = 1; i<n; ++i){
		printf("%d ", i);
	}
	printf("%d\n", n);
}
bool cmp(node a, node b){
	if(fabs(a.d-b.d)>eps)return a.d<b.d;
	return a.id<b.id;
}
int getnum(){
	int num = 0;
	for(int i = 0; i<n;++i){
		if(fabs(p[i].d-p[0].d)<eps)num++;
		else break;
	}
	return num;
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lf%lf", &n, &R, &r);
		for(int i = 0; i<n; ++i){
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].d = sqrt(1.0*p[i].x*p[i].x+1.0*p[i].y*p[i].y);
			p[i].id = i+1;
		}
		
		for(int i =0; i<n; ++i){
			if(p[i].d<fabs(R-2*r)+eps){
				p[i].d = 0;
			}
		}
		sort(p, p+n, cmp);
		int flag = 0;
		printf("%d\n", getnum());
		for(int i =0; i<n; ++i){
			if(fabs(p[i].d-p[0].d)<eps){
				if(flag)printf(" %d", p[i].id);
				else {
					flag = 1;
					printf("%d", p[i].id);
				}
			}else break;
		}
		printf("\n");
	}
	return 0;
}