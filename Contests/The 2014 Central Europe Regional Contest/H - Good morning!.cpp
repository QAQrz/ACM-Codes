#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pc(x) putchar(x)
#define ps(x) puts(x)
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
int t,k,ans;
void dfs(int a,int x){
	if(x>k||(!x&&!a))
		return;
	if(a==1){
		dfs(2,x);
		dfs(4,x);
	}
	else if(a==2){
		dfs(3,x);
		dfs(5,x);
	}
	else if(a==3)
		dfs(6,x);
	else if(a==4){
		dfs(5,x);
		dfs(7,x);
	}
	else if(a==5){
		dfs(6,x);
		dfs(8,x);
	}
	else if(a==6)
		dfs(9,x);
	else if(a==7)
		dfs(8,x);
	else if(a==8){
		dfs(0,x);
		dfs(9,x);
	}
	x=x*10+a;
	if(abs(x-k)<abs(ans-k))
		ans=x;
	dfs(a,x);
	if(a==1){
		dfs(2,x);
		dfs(4,x);
	}
	else if(a==2){
		dfs(3,x);
		dfs(5,x);
	}
	else if(a==3)
		dfs(6,x);
	else if(a==4){
		dfs(5,x);
		dfs(7,x);
	}
	else if(a==5){
		dfs(6,x);
		dfs(8,x);
	}
	else if(a==6)
		dfs(9,x);
	else if(a==7)
		dfs(8,x);
	else if(a==8){
		dfs(0,x);
		dfs(9,x);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>k;
		ans=0;
		dfs(1,ans);
		db(ans);
	}
	return 0;
}