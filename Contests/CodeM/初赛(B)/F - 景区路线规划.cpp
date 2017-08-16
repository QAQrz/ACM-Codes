#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,w,next;
}p[21234];
struct ans{
	double a,b;
};
int n,m,k,c[128],h1[128],h2[128],cnt,head[128],u,v,w;
map<int,ans>mmp;
inline void add(int u,int v,int w){
	p[cnt].v=v,p[cnt].w=w,p[cnt].next=head[u],head[u]=cnt++;
}
ans dfs(int x,int k){
	if(mmp.count(x*500+k))
		return mmp[x*500+k];
	ans a={(double)0,(double)0};
	int num=0;
	for(int i=head[x];~i;i=p[i].next)
		if(k>=p[i].w+c[p[i].v]){
			ans b=dfs(p[i].v,k-p[i].w-c[p[i].v]);
			a.a+=b.a,a.b+=b.b,num++;
		}
	if(num)
		a.a/=num,a.b/=num;
	a.a+=h1[x],a.b+=h2[x];
	return mmp[x*500+k]=a;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	memset(head,-1,sizeof head);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&c[i],&h1[i],&h2[i]);
		add(0,i,0);
	}
	while(m--){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	ans a=dfs(0,k);
	printf("%.5f %.5f\n",a.a,a.b);
	return 0;
}