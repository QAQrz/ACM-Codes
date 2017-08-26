#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=112345;
int n,a[maxn],b[maxn],cnt,vis[maxn],sz;
map<int,int>mmp;
vector<int>vec[maxn];
void dfs(int x,int s){
	if(vis[x])
		return;
	vis[x]=1;
	vec[s].pb(x);
	dfs(mmp[a[x]],s);
}
int main(){
	// ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		mmp[b[i]]=i;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i,++cnt);
	db(cnt);
	for(int i=1;i<=cnt;i++){
		sz=vec[i].size();
		printf("%d",sz);
		for(int j=0;j<sz;j++)
			printf(" %d",vec[i][j]);
		printf("\n");
	}
	return 0;
}