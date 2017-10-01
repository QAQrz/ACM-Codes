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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1024;
struct node{
	double a,b,c,d,e;
}p[maxn];
double dult(node a,node b){
	return a.a*b.a+a.b*b.b+a.c*b.c+a.d*b.d+a.e*b.e;
}
node cal(node a,node b){
	return node{a.a-b.a,a.b-b.b,a.c-b.c,a.d-b.d,a.e-b.e};
}
double dis(int i,int j,int k){
	node x=cal(p[j],p[i]),y=cal(p[k],p[i]);
	return dult(x,y)/sqrt(dult(x,x))/sqrt(dult(y,y));
}
int n,m,ans[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].a>>p[i].b>>p[i].c>>p[i].d>>p[i].e;
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=1;j<=n&&!flag;j++)
			for(int k=j+1;k<=n&&!flag;k++)
				if(i!=j&&i!=k&&acos(dis(i,j,k))-pi/2<-eps)
					flag=1;
		if(!flag)
			ans[m++]=i;
	}
	db(m);
	for(int i=0;i<m;i++)
		db(ans[i]);
	return 0;
}