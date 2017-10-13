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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=512;
LL n,m,a[maxn][maxn],b[maxn][maxn],q,x,y,x2,y2;
char s[maxn][maxn];
inline void addn(LL x,LL y){
	for(int i=x;i<=n;i+=i&-i)
		for(int j=y;j<=m;j+=j&-j)
			a[i][j]++;
}
inline void addm(LL x,LL y){
	for(int i=x;i<=n;i+=i&-i)
		for(int j=y;j<=m;j+=j&-j)
			b[i][j]++;
}
inline LL queryn(LL x,LL y){
	LL ans=0;
	for(int i=x;i;i-=i&-i)
		for(int j=y;j;j-=j&-j)
			ans+=a[i][j];
	return ans;
}
inline LL querym(LL x,LL y){
	LL ans=0;
	for(int i=x;i;i-=i&-i)
		for(int j=y;j;j-=j&-j)
			ans+=b[i][j];
	return ans;
}
inline LL caln(){
	return queryn(x2,y2)-queryn(x,y2)-queryn(x2,y-1)+queryn(x,y-1);
}
inline LL calm(){
	return querym(x2,y2)-querym(x-1,y2)-querym(x2,y)+querym(x-1,y);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++)
			if(s[i][j]=='.'){
				if(i&&s[i-1][j]=='.')
					addn(i+1,j+1);
				if(j&&s[i][j-1]=='.')
					addm(i+1,j+1);
			}
	}
	cin>>q;
	while(q--){
		cin>>x>>y>>x2>>y2;
		if(x==x2&&y==y2)
			db(0);
		else if(x==x2)
			db(calm());
		else if(y==y2)
			db(caln());
		else
			db(caln()+calm());
	}
	return 0;
}