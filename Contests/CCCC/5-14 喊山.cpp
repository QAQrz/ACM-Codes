#include <bits/stdc++.h>
using namespace std;
vector<int>v[10086];
int n,m,k,i,a,b,ans,s,l,vis[10086];
struct node{
	int s,x;
};
int main(){
	cin>>n>>m>>k;
	while(m--){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	while(k--){
		cin>>a;
		node p={0,a};
		queue<node>q;
		q.push(p);
		memset(vis,0,sizeof vis);
		vis[a]=1,s=ans=0;
		while(q.size()){
			node u=q.front();
			q.pop();
			l=v[u.x].size();
			for(i=0;i<l;i++){
				node p={u.s+1,v[u.x][i]};
				if(!vis[p.x]){
					vis[p.x]=1;
					if(p.s>s)
						s=p.s,ans=p.x;
					else if(p.s==s&&ans>p.x)
						ans=p.x;
					q.push(p);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}