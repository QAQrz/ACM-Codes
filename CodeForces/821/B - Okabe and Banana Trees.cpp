#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=1123456;
LL ans;
double m,b;
LL sum(LL x){
	return x/2*(x+1)+(x%2?(x+1)/2:0);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>m>>b;
	for(LL i=0;-1.0*i/m+b>=0;i++)
		ans=max(ans,sum((LL)(-1.0*i/m+b))*(i+1)+sum(i)*(LL)(-1.0*i/m+b+1));
	db(ans);
	return 0;
}