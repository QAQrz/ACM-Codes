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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
LL x,pri[66666],flag,vis[66666],t;
inline bool ispri(LL x){
	if(x<2)
		return 0;
	for(LL i=2;i*i<=x;i++)
		if(!(x%i))
			return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>x;
	for(LL i=2;i<66666;i++)
		if(!vis[i]){
			pri[t++]=i;
			for(LL j=i*i;j<66666;j+=i)
				vis[j]=1;
		}
	if(ispri(x))
		db("yes");
	else{
		for(LL i=0;i<t&&!flag&&pri[i]<=x;i++){
			for(LL j=1;j>0&&j<=x&&!flag;){
				j*=pri[i];
				if(x==j)
					flag=1;
			}
		}
		db(flag?"yes":"no");
	}
	return 0;
}