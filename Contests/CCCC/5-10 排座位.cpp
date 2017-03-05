#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,b,i,s[128][128],vis[128];
int dfs(int x,int b){
	if(x==b)
		return 1;
	int ans=0;
	vis[x]=1;
	for(i=1;i<=n;i++)
		if(!vis[i]&&s[x][i]>0)
			ans+=dfs(i,b);
	vis[x]=0;
	return ans;
}
int main(){
	cin>>n>>m>>k;
	while(m--){
		cin>>a>>b;
		cin>>s[a][b];
		s[b][a]=s[a][b];
	}
	while(k--){
		memset(vis,0,sizeof vis);
		cin>>a>>b;
		if(s[a][b]<0){
			if(dfs(a,b))
				cout<<"OK but..."<<endl;
			else
				cout<<"No way"<<endl;
		}
		else if(s[a][b]<1){
			if(dfs(a,b))
				cout<<"No problem"<<endl;
			else
				cout<<"OK"<<endl;
		}
		else
			cout<<"No problem"<<endl;
	}
	return 0;
}