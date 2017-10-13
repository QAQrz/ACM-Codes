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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=112345;
LL k,sum[512],p,ans[maxn][33],num[33],vis[maxn];
void dfs(int x,int n,int s){
	if(!vis[s]){
		vis[s]=1;
		memcpy(ans[s],num,sizeof num);
	}
	else
		return;
	if(x>26)
		return;
	for(int i=n;i;i--)
		if(s+sum[i]<=100000){
			num[x]=i;
			dfs(x+1,i,s+sum[i]);
		}
}
int main(){
	ios::sync_with_stdio(0);
	for(p=0;;p++){
		sum[p+1]=sum[p]+p;
		if(sum[p+1]>100000)
			break;
	}
	dfs(1,447,0);
	cin>>k;
	if(!k)
		db("a");
	else
		for(int i=1;i<27;i++)
			for(int j=0;j<ans[k][i];j++)
				printf("%c",'a'+i-1);
	return 0;
}