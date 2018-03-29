#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,w,next;
}p[22222];
int n,m,k,ds,head[1111],vis[1111],dis[1111],i,j,u,v,w,cnt,cntm,tra[11],tt,visi[1111],ans,sum,maxs,minsum=0x3f3f3f3f,minans,flag;
string str,str1,s[1111];
map<string,int>maps;
queue<int>q;
void add(int u,int v,int w){
	p[cnt].v=v,p[cnt].w=w,p[cnt].next=head[u],head[u]=cnt++;
}
int main(){
	scanf("%d %d %d %d",&n,&m,&k,&ds);
	memset(head,-1,sizeof head);
	while(k--){
		cin>>str>>str1>>w;
		if(!maps[str])
			u=maps[str]=++cntm,s[u]=str;
		else
			u=maps[str];
		if(str[0]=='G'&&!visi[u])
			visi[u]=tra[tt++]=u;
		if(!maps[str1])
			v=maps[str1]=++cntm,s[v]=str1;
		else
			v=maps[str1];
		if(str1[0]=='G'&&!visi[v])
			visi[v]=tra[tt++]=v;
		add(u,v,w);
		add(v,u,w);
	}
	for(i=0;i<tt;i++){
		q.push(tra[i]);
		memset(dis,0x3f3f3f3f,sizeof dis);
		memset(vis,0,sizeof vis);
		sum=dis[tra[i]]=0,vis[tra[i]]=1,maxs=0x3f3f3f3f;
		while(q.size()){
			u=q.front();
			vis[u]=0;
			q.pop();
			for(j=head[u];~j;j=p[j].next)
				if(dis[p[j].v]>dis[u]+p[j].w){
					dis[p[j].v]=dis[u]+p[j].w;
					if(!vis[p[j].v]){
						vis[p[j].v]=1;
						q.push(p[j].v);
					}
				}
		}
		for(j=1;j<=cntm;j++)
			if(!visi[j]){
				if(dis[j]>ds)
					break;
				maxs=min(maxs,dis[j]),sum+=dis[j];
			}
		if(j<=cntm)
			continue;
		if(maxs<=ds&&(maxs>ans||(maxs==ans&&sum<minsum)||(maxs==ans&&sum==minsum&&s[tra[i]].compare(s[minans])<0)))
			ans=maxs,minsum=sum,minans=tra[i],flag=1;
	}
	if(flag){
		cout<<s[minans]<<endl;
		printf("%.1lf %.1lf\n",1.0*ans,1.0*minsum/n);
	}
	else
		cout<<"No Solution"<<endl;
	return 0;
}