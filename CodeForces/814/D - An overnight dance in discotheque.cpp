#include <bits/stdc++.h>
using namespace std;
struct node{
	double x,y,r;
}p[1123];
int n,i,j,a[1123],b[1123],ta,tb,num;
double ans;
inline double dis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline bool cmp(node a,node b){
	return a.r>b.r;
}
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf %lf %lf",&p[i].x,&p[i].y,&p[i].r);
	sort(p,p+n,cmp);
	for(i=0;i<n;i++){
		for(j=0;j<ta;j++)
			if(dis(p[a[j]],p[i])<p[a[j]].r)
				break;
		if(j<ta){
			for(num=j=0;j<tb;j++)
				if(dis(p[b[j]],p[i])<p[b[j]].r)
					num++;
			b[tb++]=i;
			if(num%2)
				ans-=acos(-1)*p[i].r*p[i].r;
			else
				ans+=acos(-1)*p[i].r*p[i].r;
		}
		else
			a[ta++]=i,ans+=acos(-1)*p[i].r*p[i].r;
	}
	printf("%.8lf\n",ans);
	return 0;
}