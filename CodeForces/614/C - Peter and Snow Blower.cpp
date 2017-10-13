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
const LL inf=1e18,mod=1e9+7,maxn=112345;
struct node{
	double x,y;
}p[maxn];
int n;
double a=inf,b;
inline double dis(node a,node b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline double area(double x){
	return x*pi;
}
inline double xmult(node p1,node p2,node p){
	return (p1.x-p.x)*(p2.y-p.y)-(p2.x-p.x)*(p1.y-p.y);
}
inline double distoseg(node p,node a,node b){
	node t=p;
	t.x+=a.y-b.y,t.y+=b.x-a.x;
	if(xmult(a,t,p)*xmult(b,t,p)>eps)
		return min(dis(p,a),dis(p,b));
	return fabs(xmult(p,a,b))*fabs(xmult(p,a,b))/dis(a,b);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>p[0].x>>p[0].y;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		a=min(a,dis(p[0],p[i])),b=max(b,dis(p[0],p[i]));
		if(i>1)
			a=min(a,distoseg(p[0],p[i-1],p[i]));
	}
	a=min(a,distoseg(p[0],p[1],p[n]));
	printf("%.18f\n",area(b)-area(a));
	return 0;
}