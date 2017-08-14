#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
typedef long long LL;
int n,vis[1123456],u,v;
double ans;
vector<int>vec[1123456];
void dfs(int x,int s,double p){
	vis[x]=1;
	int sum=0;
	for(int i=vec[x].size()-1;~i;i--)
		if(!vis[vec[x][i]])
			sum++;
	if(!sum)
		ans+=p*s;
	else
		for(int i=vec[x].size()-1;~i;i--)
			if(!vis[vec[x][i]])
				dfs(vec[x][i],s+1,p/sum);
	vis[x]=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,0,1);
	printf("%.15lf\n",ans);
	return 0;
}