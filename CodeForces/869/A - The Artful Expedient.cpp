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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=2123,maxm=2123456;
int n,a[maxn],b[maxn],vis[maxm],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		vis[a[i]]=1;
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		vis[b[i]]=1;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(vis[a[i]^b[j]])
				ans++;
	db(ans%2?"Koyomi":"Karen");
	return 0;
}