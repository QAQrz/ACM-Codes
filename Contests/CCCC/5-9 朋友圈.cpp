#include <bits/stdc++.h>
using namespace std;
int pre[33333],n,m,i,a,b,k,u,v,num[33333],ans;
int find(int x){
	int t=x,temp;
	while(pre[x]!=x)
		x=pre[x];
	while(pre[t]!=t)
		temp=pre[t],pre[t]=x,t=temp;
	return x;
}
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)
		pre[i]=i;
	while(m--){
		cin>>k;
		if(k)
			cin>>a;
		while(--k){
			cin>>b;
			u=find(a),v=find(b);
			if(u!=v)
				pre[u]=v;
		}
	}
	for(i=1;i<=n;i++)
		u=find(i),num[u]++,ans=max(ans,num[u]);
	cout<<ans<<endl;
	return 0;
}