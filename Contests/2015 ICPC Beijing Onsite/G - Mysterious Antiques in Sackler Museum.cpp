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
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
struct node{
	int x, y;
}p[4];
bool f(node a, node b, node c){
	if(a.x==b.x&&a.x==c.x)return 1;
	if(a.x==b.y&&a.x==c.x)return 1;
	if(a.x==b.x&&a.x==c.y)return 1;
	if(a.x==b.y&&a.x==c.y)return 1;
	if(a.y==b.x&&a.x==c.x)return 1;
	if(a.y==b.y&&a.x==c.x)return 1;
	if(a.y==b.x&&a.x==c.y)return 1;
	if(a.y==b.y&&a.x==c.y)return 1;


	if(a.x==b.x&&a.y+b.y==c.x)return 1;
	if(a.x==b.x&&a.y+b.y==c.y)return 1;
	if(a.y==b.x&&a.x+b.y==c.x)return 1;
	if(a.y==b.x&&a.x+b.y==c.y)return 1;
	if(a.x==b.y&&a.y+b.x==c.x)return 1;
	if(a.x==b.y&&a.y+b.x==c.y)return 1;
	if(a.y==b.y&&a.x+b.x==c.x)return 1;
	if(a.y==b.y&&a.x+b.x==c.y)return 1;

	return 0;
}
bool check(){
	for(int i = 0; i<4; ++i){
		for(int j = 0; j<4; ++j){
			for(int k = 0; k<4; ++k){
				if(i==j||i==k||j==k)continue;
				if(f(p[i], p[j], p[k]))return 1;
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	scanf("%d", &t);
	while(t--){
		for(int i  =0 ; i<4; ++i){
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		if(check())printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}