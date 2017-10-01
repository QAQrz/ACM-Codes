#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
struct Point{
	double x,y;
}a,b,c;
struct Line { Point a, b; };
Point intersection(Line u, Line v){
	Point ret = u.a;
	double t =((u.a.x-v.a.x)*(v.a.y-v.b.y)
			  -(u.a.y-v.a.y)*(v.a.x-v.b.x))
			 /((u.a.x-u.b.x)*(v.a.y-v.b.y)
			  -(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x += (u.b.x-u.a.x) * t;
	ret.y += (u.b.y-u.a.y) * t;
	return ret;
}
Point circumcenter(Point a,Point b,Point c){
	Line u, v;
	u.a.x = (a.x+b.x)/2, u.a.y = (a.y+b.y)/2;
	u.b.x = u.a.x-a.y+b.y, u.b.y = u.a.y+a.x-b.x;
	v.a.x = (a.x+c.x)/2, v.a.y = (a.y+c.y)/2;
	v.b.x = v.a.x-a.y+c.y, v.b.y = v.a.y+a.x-c.x;
	return intersection(u, v);
}
Point subt(Point u, Point v){
	Point ret;
	ret.x = u.x - v.x,ret.y = u.y - v.y;
	return ret;
}
double dmult(Point u, Point v){
	return u.x*v.x + u.y*v.y;
}
double vlen(Point p){
	return sqrt(p.x*p.x + p.y*p.y);
}
double angle_cos(Line u, Line v){
	return dmult(subt(u.a, u.b), subt(v.a, v.b))/vlen(subt(u.a, u.b))/vlen(subt(v.a, v.b));
}
int main(){
	ios::sync_with_stdio(0);
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
	Point d=circumcenter(a,b,c);
	Line l={d,b},l2={d,a},l3={d,c};
	db((abs(angle_cos(l,l2)-angle_cos(l,l3))<eps)?"Yes":"No");
	return 0;
}