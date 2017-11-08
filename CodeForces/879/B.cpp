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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=512;
LL n,k,a[maxn],ans,vis[maxn];
vector<LL>v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		v.pb(a[i]);
	}
	if(k>=n){
		sort(a,a+n);
		db(a[n-1]);
	}
	else{
		while(1){
			if(v[0]<v[1]){
				vis[v[1]]++;
				if(vis[v[1]]>=k){
					ans=v[1];
					break;
				}
				v.pb(v[0]);
				v.erase(v.begin());
			}
			else{
				vis[v[0]]++;
				if(vis[v[0]]>=k){
					ans=v[0];
					break;
				}
				v.pb(v[1]);
				v.erase(v.begin()+1);
			}
		}
		db(ans);
	}
	return 0;
}